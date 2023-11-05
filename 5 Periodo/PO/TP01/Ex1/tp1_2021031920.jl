#=
Variables:
Xnm = if object n is in box m
Ym = if box m is used

Objective function:
minimize sum(Ym)

Constraints:
sum(Xnm) = 1 for all n => each object must be in a box
sum(Xnm * Wn) <= C * Ym for all m => the sum of the weights of the objects in box m must be less than or equal to the capacity of box m
Xnm, Ym are binary

Each box has a capacity of 20Kg, and the number of objects and weight of each object are given in the file passed as argument.
=#

using JuMP
using HiGHS

mutable struct Empacotamento
	numObjects::Int
	weights::Array{Float64}
	capacity::Int64
end

function readData(file)
	numObjects = 0
	weights = []
	capacity = 20
	for l in eachline(file)
		q = split(l, '\t')
		num = parse(Int64, q[2])
		if q[1] == "n"
			numObjects = num
			weights = [0.0 for i in 1:numObjects]
		elseif q[1] == "o"
			weights[num + 1] = parse(Float64, q[3])
		end
	end
	return Empacotamento(numObjects, weights, capacity)
end

model = Model(HiGHS.Optimizer)
set_silent(model)

file = open(ARGS[1], "r")

data = readData(file)

@variable(model, x[1:data.numObjects, 1:data.numObjects], Bin)
@variable(model, y[1:data.numObjects], Bin)

for i in 1:data.numObjects
	@constraint(model, sum(x[i, :]) == 1)
end

for j in 1:data.numObjects
	@constraint(model, sum(x[:, j] .* data.weights) <= data.capacity * y[j])
end

@objective(model, Min, sum(y))

optimize!(model)

sol = objective_value(model)
println("TP1 2021031920 = ", sol)