# **📒 Lista de Contatos (pBuffer)**
Um gerenciador simples de lista de contatos escrito em C usando **uma única alocação dinâmica de memória** e **nenhuma variável declarada**, além do `pBuffer`.

## **📋 Descrição**
**Lista de Contatos (pBuffer)** é um programa orientado por menu que permite aos usuários gerenciar uma lista de contatos — incluindo nome, idade e email — usando apenas um buffer de memória alocado dinamicamente (`pBuffer`). O projeto foi desenvolvido com restrições rigorosas:
* ❌ Nenhuma variável declarada (exceto o ponteiro `pBuffer`).
* ✅ Apenas **uma chamada para** `malloc` em todo o programa (com `realloc` ocasional).
* ✅ Toda a lógica manipulada via **aritmética de ponteiros**.

Este projeto serve como um desafio único em gerenciamento manual de memória e programação de baixo nível em C.

## **🎮 Como Funciona**
1. O programa inicia alocando um `pBuffer` que contém:
   * Três inteiros:
      * Contador para número de pessoas
      * Opção do menu
      * Variável utilitária (ex: para loop/busca)
   * Áreas temporárias:
      * 50 bytes para entrada de nome
      * 50 bytes para entrada de email
2. O usuário pode:
   * Adicionar contatos (nome, idade, email)
   * Remover contatos por nome
   * Buscar contatos
   * Listar todos os contatos
   * Sair do programa
3. Cada contato é armazenado no buffer como:
   * 50 bytes para nome
   * 4 bytes para idade
   * 50 bytes para email
4. A memória é realocada dinamicamente conforme contatos são adicionados ou removidos.

## **🏗️ Estrutura do Projeto**
O projeto contém um único arquivo fonte:

```
ListaContatos/
└── agenda_pbufferf.c  # Toda lógica e dados em um arquivo e um buffer
```

**agenda_pbufferf.c**
* Lógica principal do programa e loop.
* Todos os dados são manipulados através do `pBuffer` usando casting e cálculos de offset.
* Usa `fgets`, `scanf`, `strcpy`, `strcmp` e `memcpy` para manipular strings e memória.

## **🚀 Como Executar**
1. **Compile o programa:**

```bash
gcc agenda_pbufferf.c -o agenda
```

2. **Execute o programa:**

```bash
./agenda
```

## **💻 Exemplo de Saída**

```
+==========================================+
|             LISTA DE CONTATOS            |
+==========================================+
|  1 - Adicionar Nova Pessoa               |
|  2 - Remover Pessoa Existente            |
|  3 - Buscar Pessoa Específica            |
|  4 - Ver Todas as Pessoas                |
|  5 - Sair do Programa                    |
+==========================================+
Sua escolha: 1

=== ADICIONANDO NOVA PESSOA ===
Digite o nome completo: Alice Johnson
Digite a idade: 29
Digite o email: alice@exemplo.com
Sucesso! Pessoa adicionada. Total: 1 pessoa(s)
```

## **🎲 Funcionalidades**
* **malloc único**: Todo o gerenciamento de memória é feito com um `malloc` e `realloc`.
* **Zero variáveis declaradas**: Todos os dados são armazenados no buffer.
* **Layout manual de memória**: Informações de contato são gerenciadas via cálculos de offset.
* **Lista dinâmica de contatos**: Memória expande/encolhe baseada no número de pessoas.
* **Menu funcional**: Opções de adicionar, remover, buscar, listar e sair.

## **🛠️ Tecnologias Utilizadas**
* **Linguagem C**
* **Bibliotecas Padrão do C**:
   * `<stdio.h>`: Entrada/saída
   * `<stdlib.h>`: Gerenciamento de memória
   * `<string.h>`: Manipulação de strings
* **Aritmética de Ponteiros**: Técnica central para acessar e organizar memória
* **Alocação Dinâmica**: Usando `malloc`, `realloc` e `free`

## **📝 Possíveis Melhorias (Atualizações Futuras)**
* Usar `structs` para simplificar o manuseio de memória.
* Adicionar persistência de arquivo (salvar/carregar).
* Ordenação alfabética dos contatos.
* Suporte para múltiplos campos (ex: telefone, endereço).
* Interface GUI ou baseada em texto usando bibliotecas como `ncurses`.

## **👩‍💻 Autor**
Desenvolvido como um desafio de gerenciamento de memória em programação C, demonstrando o que pode ser feito sem variáveis, structs e apenas um único `malloc`.
