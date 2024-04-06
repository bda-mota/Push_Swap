# Push Swap 
O objetivo do projeto é criar um algoritmo de ordenação para ordenar os números inteiros recebidos como argumentos. Contudo temos que ordená-los utilizando apenas duas stacks (A e B), sendo que ao final da ordenação, a stack A deve estar ordenada e a stack B vazia.
Para a ordenação podemos utilizar apenas os seguintes movimentos:

## Movimentos 

| Comando | Descrição       | Ação                           |
|---------|-----------------|--------------------------------|
| sa      | swap a | trocar os elementos do topo da stack A |
| sb      | swap b | trocar os elementos do topo da stack B |
| ss      | swap a + b | trocar os dois elementos do topo de ambas stacks |
| pa      | push a | move o elemento do topo de B para o topo de A |
| pb      | push b | move o elemento do topo de A para o topo de B |
| ra      | rotate a | move o elemento do topo de A para ser o último |
| rb      | rotate b | move o elemento do topo de B para ser o último |
| rr      | rotate a + b | move ambos os elemento do topo para ser o último |
| rra     | reverse rotate a | move o elemento debaixo de A para o topo |
| rrb     | reverse rotate b | move o elemento do topo de B para o topo |
| rrr     | reverse rotate a + b| move ambos os elementos debaixo para ficarem no topo |

## Execução 

Após clonar o repositório entre na paste e digite "make" no terminal, após isso o programa "./push_swap" será criado.

Digite o nome do executável seguido dos números a serem ordenados. Exemplo: ./push_swap 1 5 7 -9 0 -7891 78913

Lembre-se que para o programa ordenar os argumentos devem ser:
- números inteiros entre o MIN_INT e MAX_INT;
- os valores não podem estar ordenados
- não pode haver números duplicados
- não pode mandar argumento vazio

## Checagem 

Para chegar tem o executável, basta apenar digitar "make bonus" no terminal, o arquivo "./checker" será criado.

Para utilizar basta apenas passar os argumentos da seguinte forma:

ARG="5 1 0 7 6 3 45 98 -20"; ./push_swap $ARG | ./checker $ARG


ou 


./push_swap 5 4 6 1 | ./checker 5 4 6 1


Se a ordenação estiver correta o retorno será "OK" e caso não esteja será "KO"

## Ordenando você mesmo

Você pode utilizar apenas o ./push_swap e aguardar o retorno da ordenação (ex: sa, ra), e após utilizar o ./checker para testar.


No terminal digitando apenar "./checker 5 1 4" você pode enviar para ele os comandos para ordenação e após isso ele irá retornar OK ou KO


Exemplo:


./push_swap 2 1 3

output: sa


./checker 2 1 3
input: sa

output: OK
