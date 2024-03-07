mutable struct Aresta
	v1::Int
	v2::Int
	peso::Int
end	

mutable struct SubgrafoData
    n::Int #numero de vertices
    ng::Array{Array{Int}} #
	arestas::Array{Aresta}
end

function readData(file)
	n = 0
	ng = [[]]
	arestas = []
	for l in eachline(file)
		q = split(l, "	")

		if q[1] == "n"
			n = parse(Int64, q[2])
			ng = [[] for i=1:n]
		elseif q[1] == "e"
			v = parse(Int64, q[2])
			u = parse(Int64, q[3])
			peso = parse(Int64, q[4])
			push!(ng[v], u)
			push!(ng[u], v)
			push!(arestas, Aresta(v, u, peso))
		end
	end
	return SubgrafoData(n, ng, arestas)
end

file = open(ARGS[1], "r")
subgrafo_data = readData(file)

function ordenarVertices(subgrafo_data::SubgrafoData)
    # Criar um dicionário para armazenar a soma das arestas conectadas a cada vértice
    soma_arestas = Dict{Int, Int}()

    # Calcular a soma das arestas para cada vértice
    for aresta in subgrafo_data.arestas
        soma_arestas[aresta.v1] = get(soma_arestas, aresta.v1, 0) + aresta.peso
        soma_arestas[aresta.v2] = get(soma_arestas, aresta.v2, 0) + aresta.peso
    end

    # Ordenar os vértices com base na soma das arestas
    vertices_ordenados = sort(collect(1:subgrafo_data.n), by=x->get(soma_arestas, x, 0))

    # Lista de vértices que serão removidos
    removidos = []

    # Enquanto o primeiro vértice da lista ordenada for menor que zero (negativo)
    while soma_arestas[vertices_ordenados[1]] < 0
        vertice_removido = vertices_ordenados[1]

        # Adiciona vértice na lista de removidos
        removidos = push!(removidos, vertice_removido)

        # Remover todas as arestas envolvidas com o vértice removido
        subgrafo_data.arestas = filter(a -> a.v1 != vertice_removido && a.v2 != vertice_removido, subgrafo_data.arestas)

        # Reseta o dicionário
        for aresta in subgrafo_data.arestas
            soma_arestas[aresta.v1] = 0
            soma_arestas[aresta.v2] = 0
        end

        # Recalcular a soma do peso das arestas pra cada vértice
        for aresta in subgrafo_data.arestas
            soma_arestas[aresta.v1] = get(soma_arestas, aresta.v1, 0) + aresta.peso
            soma_arestas[aresta.v2] = get(soma_arestas, aresta.v2, 0) + aresta.peso
        end

        # Reordenar vértices com as novas somas das arestas (desconsiderar os que foram removidos)
        vertices_ordenados = sort(collect(setdiff(1:subgrafo_data.n, removidos)), by=x->get(soma_arestas, x, 0))
    end

    println("TP2 2021031920 = ", sum(a.peso for a in subgrafo_data.arestas))
    return vertices_ordenados
end

# Uso da função
vertices_ordenados = ordenarVertices(subgrafo_data)

# Exibir a ordem dos vértices
for vertice in sort(vertices_ordenados)
    print(vertice, "    ")
end