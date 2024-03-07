#=
Variables:
Xn = if vertex n is in the induced subgraph
Ynm = if edge (n, m) is in the induced subgraph

Objective function:
maximize sum(Ynm * Wnm)

Constraints:
Ynm = Ymn for all (n, m) in edges => if edge (n, m) is in the induced subgraph, edge (m, n) is also in the induced subgraph
Ynm >= Xn + Xm - 1 for all (n, m) in edges => if both vertices are in the induced subgraph, the edge is also in the induced subgraph

# since the 2nd constraint is >=, it could choose all positive edges, without choosing any vertex or just one of the 2, so these constraints are needed to correct it

Ynm <= Xn for all (n, m) in edges => limits Ynm to be 0 if vertex n is not in the induced subgraph
Ynm <= Xm for all (n, m) in edges => limits Ynm to be 0 if vertex m is not in the induced subgraph

Xn is binary
Ynm is continuous

The graph is given in the file passed as argument, with the edges and their weights.
=#

using JuMP
using HiGHS

mutable struct InducedSubgraph
	numVertices::Int
	edges::Array{Tuple{Int, Int}}
	edgesWeight::Array{Float64, 2}
end

function readData(file)
	numVertices = 0
	edges = []
	edgesWeight = []
	for l in eachline(file)
		q = split(l, '\t')
		num = parse(Int64, q[2])
		if q[1] == "n"
			numVertices = num
			edgesWeight = [0.0 for i in 1:numVertices, j in 1:numVertices]
		elseif q[1] == "e"
			push!(edges, (parse(Int64, q[2]), parse(Int64, q[3])))
			edgesWeight[parse(Int64, q[2]), parse(Int64, q[3])] = parse(Float64, q[4])
			edgesWeight[parse(Int64, q[3]), parse(Int64, q[2])] = parse(Float64, q[4])
		end
	end
	return InducedSubgraph(numVertices, edges, edgesWeight)
end

model = Model(HiGHS.Optimizer)
set_silent(model)

file = open(ARGS[1], "r")

data = readData(file)

@variable(model, x[1:data.numVertices], Bin)
@variable(model, y[1:data.numVertices, 1:data.numVertices], Bin)

for (u, v) in data.edges
	@constraint(model, y[u, v] == y[v, u])
	@constraint(model, y[u, v] >= x[u] + x[v] - 1)
	@constraint(model, y[u, v] <= x[u])
	@constraint(model, y[u, v] <= x[v])
end

@objective(model, Max, sum(y[i, j] * data.edgesWeight[i, j] for i in 1:data.numVertices, j in 1:i))

optimize!(model)

# print the vertices in the induced subgraph
for i in 1:data.numVertices
	if value(x[i]) > 0
		print(i, " ")
	end
end

sol = objective_value(model)
println("TP1 2021031920 = ", sol)