# Atividade-06-Infra-Software

## Codigo:
### O objetivo:
É resolver o problema dos produtores e consumidores utilizando threads, semáforos e mutex para sincronização dos recursos compartilhados.
O código inicia recebendo um input de 4 inteiros, que serão respectivamente a quantidade de produtores, quantidade de consumidores, valor N que será usado na fórmula do valor produzido pelo trabalhador, e o ultimo input é a quantidade de slots que o buffer terá. O código rodará infinitamente.
### Implementação:
Para resolver esse problema, foram criados 2 semáforos e um mutex, 1 semáforo para verificar se o buffer está cheio, pois com o buffer cheio o produtor não poderá produzir, 1 semáforo para verificar se o buffer está vazio, pois com o buffer vazio o consumidor não poderá consumir, e o mutex para evitar que 2 threads acessem o buffer para modifica-lo ao mesmo tempo. 



## Makefile:
Makefile simples que realiza apenas 3 funções. 

### make, que gerará o binário: 
> gcc main.c -o main -lpthread

### make run, que roda o binário gerado:
> ./main

### clean, que limpa esse binário gerado: 
> $(RM) main
