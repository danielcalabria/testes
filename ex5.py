#URI 1088 Bolhas e Baldes

def main (): 

	global cont
	global entrada
	entrada = raw_input()

	while entrada!='0': 

		cont = 0
				
		entrada = entrada.split()
		tam = int(entrada[0])
		
		del(entrada[0])
		
		ordenado = mergeSort(0,tam)

		#print (entrada)
		#print (ordenado)

		if cont%2==0:
			print("Carlos")
		else:
			print("Marcelo")

		entrada = raw_input() 
	
def merge(listaDaEsquerda, listaDaDireita):
	i = 0
	j = 0
	global cont

	tamE = len(listaDaEsquerda)
	tamD = len(listaDaDireita)

	saida=[]

	while i < tamE and j < tamD:

		if listaDaEsquerda[i] < listaDaDireita[j]:
			saida.append(listaDaEsquerda[i])
			i += 1
		else:
			saida.append(listaDaDireita[j])
			j += 1
			cont+= tamE-i
			
	while i < tamE:

		saida.append(listaDaEsquerda[i])
		i += 1
	
	while j < tamD:
			saida.append(listaDaDireita[j])
			j += 1
	
	return saida

def mergeSort(esq, direita):
	
	v=[]

	if esq+1 >= direita:
		v.append(entrada[esq])
		return v

	meio = (esq + direita)/2

	a = mergeSort(esq, meio)
	b = mergeSort(meio, direita)

	v = merge(a,b)

	return v
	
main()
