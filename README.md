# Emulator

Emulador desenvolvido para uma Arquitetura Toy, com as seguintes configurações:


* 11 registradores (r0-r10), sendo r0 sempre com o valor 0. Também existe um registrador PC.
* Memória separada em código e dados: Dados (1024 palavras de 32 bits) e Código (1024 instruções)

## Intruções

* ADD rx, ry        // rx = rx + ry
* SUB rx, ry
* DIV rx, ry
* MUL rx, ry
* BRZ rx, DES       // PC+=DES se rx = 0
* BRNZ rx, DES      // PC+=DES se rx != 0
* IBRZ rx, ADR      // PC = ADR se rx = 0
* BLZ rx, DES       // PC+=DES se rx < 0
* MOV rx, ry        // rx = ry
* LOADM rx, ADR     // rx = MEM(ADR)
* STOREM rx, ADR    // MEM(ADR) = rx
* LOADI rx, VAL     // rx = VAL
* WRITE rx          // printf(“%d\n”, rx)
* READ rx           // scanf(“%d”, rx)
* EXIT              // exit(0)

## Building it

```
mkdir build && cd build
cmake ..
make
```

## Usage
