#=
Variables:
Xn = if vertex n is in the independent set

Objective function:
maximize sum(Xn)

Constraints:
sum(Xm * Mnm, for m in numVertices) <= K - K*Xn for all n => The idea is if vertex Xn is chosen, K - K*Xn = 0, so the sum of the edges (u, v), where v is also in the independent set has 
to be 0, else if Xn is not chosen, it does not matter how many vs in (u, v) are in the independent set
Xn is binary

The graph is given in the file passed as argument, and the edges are stored in the adjacency matrix Mnm.
=#

using JuMP
using HiGHS

mutable struct ConjuntoIndependente
	numVertices::Int
	adjacencyMatrix::Array{Int, 2}
	constant::Int
end

function readData(file)
	numVertices = 0
	adjacencyMatrix = []
	for l in eachline(file)
		q = split(l, '\t')
		num = parse(Int64, q[2])
		if q[1] == "n"
			numVertices = num
			adjacencyMatrix = [0 for i in 1:numVertices, j in 1:numVertices]
		elseif q[1] == "e"
			adjacencyMatrix[parse(Int64, q[2]), parse(Int64, q[3])] = 1
			adjacencyMatrix[parse(Int64, q[3]), parse(Int64, q[2])] = 1
		end
	end
	constant = numVertices + 1
	return ConjuntoIndependente(numVertices, adjacencyMatrix, constant)
end

model = Model(HiGHS.Optimizer)
set_silent(model)

file = open(ARGS[1], "r")

data = readData(file)

@variable(model, x[1:data.numVertices], Bin)

for i in 1:data.numVertices
	@constraint(model, data.constant - data.constant * x[i] >= sum(x[j] * data.adjacencyMatrix[i, j] for j in 1:data.numVertices))
end

@objective(model, Max, sum(x))

optimize!(model)

sol = objective_value(model)
println("TP1 2021031920 = ", sol)