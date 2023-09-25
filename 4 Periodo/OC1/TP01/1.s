.data
vetor: .word 0 0 0 0
##### START MODIFIQUE AQUI START #####
#
# Este espaço eh para você definir as suas constantes e vetores auxiliares.
##### END MODIFIQUE AQUI END #####
.text
main:
add s0, zero, zero
#Teste 1
addi a0, zero, 5
addi a1, zero, 7
la a2, vetor
jal ra, primos
addi t0, zero, 2
beq t0, a0, OK1
beq zero, zero, T2
OK1: addi s0, s0, 1 #Teste ok, passou
#Teste 2
T2: addi a0, zero, 1
addi a1, zero, 6
la a2, vetor
jal ra, primos
addi t0, zero, 3
beq t0, a0, OK2
beq zero, zero, FIM
OK2: addi s0, s0, 1 #Teste ok, passou
beq zero, zero, FIM
##### START MODIFIQUE AQUI START #####
primos: bge a1, a0, L1 # Se a0 for maior que a1, troca
add t0, a1, zero
add a1, a0, zero
add a0, t0, zero
L1: add t0, a0, zero # t0 = n
add a0, zero, zero # Número de primos = 0
la t6, vetor
L2: blt a1, t0, F1 # Se n passar do intervalo vai pro final
#add t1, zero, zero
addi t1, zero, 2 # t1 = 2 = i
blt t0, t1, L3	# Se n for menor que 2, n não é primo, vai pra L3
beq t0, t1, L5 # 2 é primo
div t3, t0, t1	# t3 = n / 2
L4: blt t3, t1, L5 # Se t1 > n / 2, vai pra L5
rem t2, t0, t1 # t2 = n % i
beq zero, t2, L3 # Se n % i = 0, n não é primo
addi t1, t1, 1 # i++
beq zero, zero, L4 # Volta pra L4
L5: sw t0, 0(t6) # Salva n em vetor[numPrimos]
addi t6, t6, 4
addi a0, a0, 1 # NumPrimos++
L3: addi t0, t0, 1 # n++
beq zero, zero, L2 # Volta pra L2
F1: jalr zero, 0(ra)
##### END MODIFIQUE AQUI END #####
FIM: add zero, zero, zero
#Final da execucao, s0 deve ter o valor igual a 2.