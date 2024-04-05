# Push Swap 
O objetivo do projeto é criar um algoritmo de ordenação para ordenar os números inteiros recebidos como argumentos. Contudo temos que ordená-los utilizando apenas duas stacks (A e B), sendo que ao final da ordenação a stack A deve estar ordenada e a stack B vazia.
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
