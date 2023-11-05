#=
Variables:
Xn = how many units are produced in period n
Yn = if positive, surplus in period n, if negative, backlog in period n
SCn = total cost of units in storage in period n
Fn = total fine in period n

Objective function:
minimize sum(Cn * Xn + SCn + Fn)

Constraints:
Y1 = X1 - D1 => first Y is the surplus or backlog in period 1
Yn = Xn + Yn-1 - Dn for n > 1 => Yn takes into account the surplus or backlog from the previous period
SCn >= SCn * Yn for all n => if Yn is positive, SCn is positive, if Yn is negative, SCn = 0
Fn >= Fn * Yn * -1 for all n => if Yn is positive, Fn = 0, if Yn is negative, Fn is positive
FnumPeriods = 0 => must deliver all units by the end of the last period

The demand, production cost, storage cost and fine are given in the file passed as argument.
=#

using JuMP
using HiGHS

mutable struct BacklogLotsizing
	numPeriods::Int
	demand::Array{Int64}
	productionCost::Array{Float64}
	storageCost::Array{Float64}
	fine::Array{Float64}
end

function readData(file)
	numPeriods = 0
	demand = []
	productionCost = []
	storageCost = []
	fine = []
	for l in eachline(file)
		q = split(l, '\t')
		num = parse(Int64, q[2])
		if q[1] == "n"
			numPeriods = num
			demand = [0 for i in 1:numPeriods]
			productionCost = [0.0 for i in 1:numPeriods]
			storageCost = [0.0 for i in 1:numPeriods]
			fine = [0.0 for i in 1:numPeriods]
		elseif q[1] == "d"
			demand[num] = parse(Int64, q[3])
		elseif q[1] == "c"
			productionCost[num] = parse(Float64, q[3])
		elseif q[1] == "s"
			storageCost[num] = parse(Float64, q[3])
		elseif q[1] == "p"
			fine[num] = parse(Float64, q[3])
		end
	end
	return BacklogLotsizing(numPeriods, demand, productionCost, storageCost, fine)
end

model = Model(HiGHS.Optimizer)
set_silent(model)

file = open(ARGS[1], "r")

data = readData(file)

@variable(model, x[1:data.numPeriods] >= 0)
@variable(model, y[1:data.numPeriods])
@variable(model, sc[1:data.numPeriods] >= 0)
@variable(model, f[1:data.numPeriods] >= 0)

@constraint(model, y[1] == x[1] - data.demand[1])

for i in 2:data.numPeriods 
	@constraint(model, y[i] == x[i] + y[i - 1] - data.demand[i])
end

for i in 1:data.numPeriods
	@constraint(model, sc[i] >= data.storageCost[i] * y[i])
	@constraint(model, f[i] >= data.fine[i] * (y[i] * -1))
end

@constraint(model, f[data.numPeriods] == 0)

@objective(model, Min, sum(data.productionCost[i] * x[i] + sc[i] + f[i] for i in 1:data.numPeriods))

optimize!(model)

sol = objective_value(model)
println("TP1 2021031920 = ", sol)