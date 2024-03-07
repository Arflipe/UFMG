mutable struct ColoracaoData
    n::Int
    ng::Array{Array{Int}} # ng é a lista de adjacências do grafo
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
	return ColoracaoData(n,ng)
end

function coloracao(ng)
    # Obter o número de vértices no grafo
    num_vertices = length(ng)

    # Criar um vetor para armazenar os tamanhos das vizinhanças de cada vértice
    tamanhos_vizinhanca = [(i, length(ng[i])) for i in 1:num_vertices]

    # Ordenar os vértices pelo tamanho de suas vizinhanças em ordem decrescente
    sort!(tamanhos_vizinhanca, by=x->x[2], rev=true)

    # Criar um vetor para armazenar as cores atribuídas a cada vértice
    cores = zeros(Int, num_vertices)

    # Número total de cores usadas
    num_cores_usadas = 0

    for (vertice, _) in tamanhos_vizinhanca
        cores_utilizadas = Set()

        # Iterar sobre os vértices adjacentes ao vértice atual
        for adjacente in ng[vertice]
            # Se o vértice adjacente já foi colorido, adicione sua cor ao conjunto
            if cores[adjacente] != 0
                push!(cores_utilizadas, cores[adjacente])
            end
        end

        cor_minima = 1
        while cor_minima in cores_utilizadas
            cor_minima += 1
        end

        # Atribuir a cor mínima ao vértice atual
        cores[vertice] = cor_minima

        # Atualizar o número total de cores usadas, se necessário
        num_cores_usadas = max(num_cores_usadas, cor_minima)
    end

    println("TP2 2021031920 = ", num_cores_usadas)

    # Imprimir os vértices em cada classe de cor, em ordem crescente
    for cor in 1:num_cores_usadas
        vertices_na_cor = [i for i in 1:num_vertices if cores[i] == cor]
        vertices_na_cor_ordenados = sort(vertices_na_cor)
        println("$cor COR: ", join(vertices_na_cor_ordenados, "    "))
        #println(cor, " COR: ", )
    end
    
end

file = open(ARGS[1], "r")

data = readData(file)

coloracao(data.ng)