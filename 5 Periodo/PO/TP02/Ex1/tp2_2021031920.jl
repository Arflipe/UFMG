f = open(ARGS[1], "r")

objs_i = []

total_objects = parse(Int, split(readline(f), '\t')[2])

# Leitura do arquivo
while !eof(f)
    objects = split(readline(f), '\t')
    o = [parse(Int, objects[2])+1,parse(Float16, objects[3])]
    push!(objs_i, o)
end
close(f)

# Ordenação em ordem decrescente com base nos pesos
sort!(objs_i, by = x -> x[2],rev=true)

# Lista das caixas com o id's dos seus objetos e a lista de pesos em suas respectivas caixas
boxes = [[]]
w_is = [[]]

# Index da caixa atual
global box_i = 1

while !isempty(objs_i)
    
    # Enquanto houver objetos na lista, tenta-se colocar o mais pesado
    o = popfirst!(objs_i) 
    global act_b = round(reduce(+, w_is[box_i], init=0.0);digits=1) #Peso da caixa atual

    # Caso o objeto atual não caiba, será tentado colocar os objetos de menor peso.
    if round(act_b + o[2];digits=1) > 20

        # Caso ainda haja objetos na lista e o objeto de menor peso caiba na caixa
        while !isempty(objs_i) && last(objs_i)[2] + act_b <= 20
            
            # Atualiza peso da caixa atual, retira o objeto da lista e adiciona na caixa
            global act_b += last(objs_i)[2] + act_b 
            oo = pop!(objs_i)
            push!(boxes[box_i],oo[1])
            push!(w_is[box_i],oo[2])
            
        end

        # Se não dê para adicionar o objeto mais leve, cria-se uma nova caixa
        push!(boxes,[])
        push!(w_is,[])

        # Atualiza a caixa atual para ser a nova caixa vazia
        global box_i += 1 
    end
    # Adiciona-se o objeto inicial na caixa atual
    push!(boxes[box_i],o[1])
    push!(w_is[box_i],o[2])
end

println("TP2 2021031920 = ",length(boxes))

for i in 1:length(boxes)
    wb = 0
    for j in 1:length(boxes[i])
        print(Int(boxes[i][j]),"\t")
    end
    print("\n")
end