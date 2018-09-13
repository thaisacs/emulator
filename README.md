# Emulator

Emulador desenvolvido para uma Arquitetura Toy, com as seguintes configurações:


* 11 registradores (r0-r10), sendo r0 sempre com o valor 0. Também existe um registrador PC.
* Memória separada em código e dados:
+ Dados: 1024 palavras de 32 bits
+ Código: 1024 instruções (endereçamento: 0 - 1023)

## Intruções

## Building it

```
mkdir build && cd build
cmake ..
make
```

## Usage
