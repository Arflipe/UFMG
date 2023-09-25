.data
cartao: .word 4 9 1 6 6 4 1 8 5 9 3 6 9 0 0 3
##### START MODIFIQUE AQUI START #####
#
# Este espaço eh para você definir as suas constantes e vetores auxiliares.
##### END MODIFIQUE AQUI END #####
.text
main:
la a0, cartao
jal ra, verifica
beq zero,zero,FIM
##### START MODIFIQUE AQUI START #####
verifica: lw t0, 60(a0) # Carregando último dígito do vetor
addi sp, sp -8 # Colocando o stack pointer 2 posições para cima
sw ra, 4(sp) # Colocando ra na pilha
sw t0, 0(sp) # Colocando o último dígito do vetor na pilha
jal ra, multvetores # Inicializar o procedimento multvetores
addi t2, zero, 10 # t2 = 10
rem a0, a0, t2 # a1 = a1 % 10
lw t0, 0(sp) # Carregando o último dígito do vetor da pilha
addi sp, sp 4 # Volta a pilha para 1 posição abaixo
bne t0, a0, L1 # Se o valor retornado por multvetores % 10 for diferente do último dígito do cartão de crédito, vai pra L1
addi a0, zero, 1 # a1 = 1
beq zero, zero, F1 # Vai pro final
L1: add a0, zero, zero # a1 = 0
F1:lw ra, 0(sp) # Carrega o endereço de retorno da pilha
addi sp, sp, 4 # Volta a pilha para a posição inicial
jalr zero, 0(ra) # Volta pra linha 11
multvetores: add a1, zero, zero # a1 = 0
addi t0, zero, 2 # t0 = 2 (multiplicador)
addi t2, zero, 10 # t2 = 10 (somar dígitos separado)
add t3, zero, zero # t3 = 0 (quantos dígitos foram somados)
addi t4, zero, 15 # t4 = 15 (números máximos a serem somados)
addi t5, zero, 2 #t5 = 2 (controle do multiplicador)
L3: beq t4, t3, F2 # Se já tiver somado os 15 números do cartão, ir para o final
lw t1, 0(a0) # Carregar o dígito do cartão
addi a0, a0, 4 # Apontar para o próximo dígito do cartão
mul t1, t1, t0 # Multiplica por 2 ou 1
blt t1, t2, L2 # Se t1 < 10, vai pra L2
addi t1, t1, -10 # t1 -= 10
addi a1, a1, 1 # a1++
L2: add a1, a1, t1 # a1 += t1
addi t3, t3, 1 # Mais um dígito somado
beq t0, t5, L4 
addi t0, t0, 1 # Se t0 = 1, t0++
beq zero, zero, L3 # Vai pra L3
L4: addi t0, t0, -1 # Se t0 = 2, t0--
beq zero, zero, L3 # Vai pra L3
F2: add a0, a1, zero
jalr zero, 0(ra) # Acaba o procedimento multvetores
##### END MODIFIQUE AQUI END #####
FIM: add zero, zero, zero