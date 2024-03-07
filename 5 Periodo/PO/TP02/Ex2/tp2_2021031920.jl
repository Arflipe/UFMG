mutable struct ConjuntoIndependenteData
    n::Int
    ng::Array{Array{Int}}
end

function readData(file)
	n = 0
	ng = [[]]
	for l in eachline(file)
		q = split(l, "\t")

		if q[1] == "n"
			n = parse(Int64, q[2])
			ng = [[] for i=1:n]
		elseif q[1] == "e"
			v = parse(Int64, q[2])
			u = parse(Int64, q[3])
			push!(ng[v], u)
			push!(ng[u], v)
		end
	end
	return ConjuntoIndependenteData(n,ng)
end

function conjunto_independente(G)
    # Inicializa um conjunto vazio para armazenar o conjunto independente máximo
    conjunto_maximo = Set()

    # Lista de vértices ordenada por grau decrescente
    vertices_ord = sort([(v, length(G[v])) for v in 1:length(G)], by=x->x[2])

    for (vertice, _) in vertices_ord
        # Adiciona o vértice ao conjunto independente máximo se não estiver conectado aos vértices já selecionados
        if all(neigh -> neigh ∉ conjunto_maximo, G[vertice])
            push!(conjunto_maximo, vertice)
        end
    end

    println("TP2 2021031920 = ", length(conjunto_maximo))
    ordenado = sort(collect(conjunto_maximo))
    println(join(ordenado, "\t"))
end

file = open(ARGS[1], "r")

data = readData(file)

conjunto_independente(data.ng)
