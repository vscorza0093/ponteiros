# Ponteiro

Ponteiro é uma varíavel que armazena um endereço de memória de uma outra variável

Então se fizermos a operação

```C
    int num = 10;
    int index = num;

    // index = 10;
```
a variável index terá o mesmo valor que a variável num, o número 10

## Referência 

Podemos acessar o endereço de memória de uma variável através do "operador de referência" &  que retornará o endereço de memória onde determinada varíavel está armazenada.

```C
    int myAge = 30;
    // myAge = 30
    // &myAge = 0061FF14
```
    
 (Tecnicamente era pra ser um valor hexadecimal(?) aparentemente é um inteiro(?))

Para printarmos um ponteiro utilizamos o especificador de formato "%p"

```C
    int myAge = 30;
    printf("pointer: %p", &myAge);
    // pointer: 0061FF14
```

Se quisessemos que a variável index recebesse a variável num para, em outro momento, acessarmos seu valor, devemos utilizar ponteiros, utilizando asterísco para o tipo de dados que será recebido por exemplo

```C
    int num = 10;
    int* memoryAddress = &num;
    // memoryAddress = 0061FF10
```

Uma variável de ponteiro aponta para um tipo de dados do mesmo tipo, então um ponteiro (int*) deve apontar para uma variável (int)

## Deferência

Deferência significa armazenar em uma variável um endereço de memória de outra variável utilizando o "operador de deferência" * 

Em, C, quando acessamos arrays através de colchetes e um índice específico estamos acessando o valor contido dentro de um endereço de memória, então estamos apontando para esse endereço de memória e buscando o valor ali dentro contido, então, se quisessemos passar um endereço da memória como parâmetro de uma função, não poderíamos fazer a seguinte operação

```C
    void swap(int* a, int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
    void itemsToSwap(int lista[]){
        for (int i = 0; i < 4; i++)
            swap((lista[i]), lista[i + 1]);
        
        for (int i = 0; i < 5; i++)
            printf("%d", lista[i]);
    }
```

Obeteríamos um erro na hora da compilação, pois, na linha 59 deste arquivo, na primeira chamada da função swap (swap((lista[i]), lista[i + 1]);) não estamos passando o endereço da memória para a variável swap, que está esperando receber um endereço de memória de uma variável do tipo inteiro, estamos apenas passando um valor inteiro.

Podemos printar um endereço de memória como um número inteiro através do especificador de formato "%d" ou como um hexadecimal através do especificador de formato "%hx"

```C
    printf("mem int %d", &memoryAddress);
    printf("mem hex %hx", &num);
    // memoryAddress 6422288
    // num 0061FF10
```
Um variável que é um array sempre apontará para o primeiro endereço de uma sequência de itens do mesmo tipo.
Sendo assim, podemos obter o seu primeiro endereço de memória de várias formas distintas

```C
    int lista[5] = 1, 2, 3, 4, 5;
    printf("%hx", lista);           // ff00
    printf("%hx", &lista);          // ff00
    printf("%hx", &lista[0]);       // ff00
    printf("%hx\n", (lista + 0));   //ff00
```

Então, para passarmos o endereço de memória de um item em determinada posição de um array, devemos utilizar algum dos exemplos a cima.

Voltando para o exemplo anterior da função swap, o resultado final será esse

```C
    void swap(int* a, int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
    void itemsToSwap(int lista[]){
        for (int i = 0; i < 4; i++)
            swap((lista + i), (lista + (i + 1)));
        
        for (int i = 0; i < 5; i++)
            printf("%d", lista[i]);
    }
```

Assim, estamos passando o endereço da memória de determinada posição do array para a função swap, que verificará se os tipos passados são compatíveis.

Em seguida, utilizaremos o operador de deferência para poder acessar o valor contido dentro do endereço de memória que recebemos, para fazer todas as operações necessárias. 
Ao invés de usar o operador de deferência no tipo de dado (int), usaremos diretamente no nome da variável (a) e (b)

```C
    void swap(int* a, int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
```

Assim, fizemos as devidas alterações no valor, diretamente no endereço da memória do índice específico do array.
