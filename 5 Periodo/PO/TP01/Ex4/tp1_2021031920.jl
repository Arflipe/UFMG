#=
Variables:
Xnm = if vertex n uses color m
Ym = if color m is used

Objective function:
minimize sum(Ym)

Constraints:
sum(Xnm) = 1 for all n => each vertex must have a color
Xuk + Xvk <= 1 for all (u, v) in E and k in numVertex => if vertices u and v are connected, they cannot have the same color
Xnm <= Ym for all n and m => if vertex n uses color m, color m must be used
Xnm, Ym are binary

The graph is given in the file passed as argument.
=#

using JuMP
using HiGHS

mutable struct GraphColoring
	numVertex::Int
	edges::Array{Tuple{Int, Int}}
end

function readData(file)
	numVertex = 0
	edges = []
	for l in eachline(file)
		q = split(l, '\t')
		num = parse(Int64, q[2])
		if q[1] == "n"
			numVertex = num
		elseif q[1] == "e"
			push!(edges, (parse(Int64, q[2]), parse(Int64, q[3])))
		end
	end
	return GraphColoring(numVertex, edges)
end

model = Model(HiGHS.Optimizer)
set_silent(model)

file = open(ARGS[1], "r")

data = readData(file)

@variable(model, x[1:data.numVertex, 1:data.numVertex], Bin)
@variable(model, y[1:data.numVertex], Bin)

for i in 1:data.numVertex
	@constraint(model, sum(x[i, :]) == 1)
end

for (u, v) in data.edges
	for k in 1:data.numVertex
		@constraint(model, x[u, k] + x[v, k] <= 1)
	end
end

for i in 1:data.numVertex
	for j in 1:data.numVertex
		@constraint(model, x[i, j] <= y[j])
	end
end

@objective(model, Min, sum(y))

optimize!(model)

sol = objective_value(model)
println("TP1 2021031920 = ", sol)