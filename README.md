# UFC: exercícios em linguagem C

Implementações em C feitas durante a graduação em Ciência da Computação na UFC.

| Pasta | O que trata |
| --- | --- |
| Criptografia de Frases | Cifragem de frases |
| Lista Ligada | Lista encadeada simples |
| Lista Ligada de Imóveis | Lista encadeada aplicada a um cadastro de imóveis |
| Árvore Binária de Busca | Inserção, busca e remoção |
| Threads | Criação e sincronização de threads |
| Manipulação de Saldo com threads | Acesso concorrente a um saldo compartilhado |
| Threads e Monitoramento de Deadlock | Detecção de deadlock entre threads |

Também há dois repositórios com implementações completas de árvores balanceadas: [AVL](https://github.com/MayronnGomes/AVL-Tree-Implementation-in-C) e [Rubro-Negra](https://github.com/MayronnGomes/RB-Tree-Implementation-in-C-).

## Como compilar

```bash
gcc arquivo.c -o programa -pthread
./programa
```

O `-pthread` é necessário nos exemplos com threads.

## Autor

Mayronn Gomes Viana. Código acadêmico, UFC.
