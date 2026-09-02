# Introdução ao C++ para Competições de Programação

Este documento cobre o básico da linguagem C++ no contexto de maratonas e olimpíadas
de programação, principalmente a OBI. 😘😘

---

## 1. O esqueleto de todo programa

Praticamente todo código de competição começa igual. Este é o template base:

```cpp
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Seu código aqui

    return 0;
}
```

### O que cada linha faz

**`#include <bits/stdc++.h>`**
É um cabeçalho não-padrão (existe no GCC/g++) que inclui *todas* as bibliotecas
padrão de uma vez: `<iostream>`, `<vector>`, `<algorithm>`, `<cmath>`, `<string>` e
todo o resto. Em competição isso economiza tempo e evita esquecer um include.
Fora de competição, prefira incluir só o que usa — o `bits/stdc++.h` deixa a
compilação mais lenta e não é portável (não funciona no compilador da Microsoft
nem no Clang do macOS por padrão).

**`using namespace std;`**
Tudo da biblioteca padrão vive dentro do *namespace* `std`. Sem essa linha você
precisaria escrever `std::cin`, `std::cout`, `std::vector<int>` a cada uso.
Com ela, basta `cin`, `cout`, `vector<int>`. Em projetos grandes essa prática é
desaconselhada (pode causar conflito de nomes), mas em um arquivo único de
competição é o padrão.

**`ios_base::sync_with_stdio(false);`**
Por padrão, o C++ mantém os fluxos `cin`/`cout` sincronizados com os do C
(`scanf`/`printf`), para que você possa misturar os dois. Essa sincronização
custa caro. Desligá-la torna `cin`/`cout` muito mais rápidos — a diferença
aparece em problemas com centenas de milhares de linhas de entrada.

> [!WARNING]
> Depois de desligar a sincronização, **não misture** `cin`/`cout` com
> `scanf`/`printf` no mesmo programa: a ordem da saída pode sair embaralhada.

**`cin.tie(NULL);`**
Por padrão, `cin` está "amarrado" a `cout`: antes de cada leitura, o `cout` é
descarregado (*flush*) automaticamente. Isso garante que um prompt apareça antes
da leitura, mas em competição não há usuário humano lendo prompts — então
desamarrar elimina um flush a cada leitura e ganha mais velocidade.

**`return 0;`**
Indica ao sistema que o programa terminou com sucesso. No `main` do C++ ele é
opcional (o compilador o insere implicitamente), mas é bom hábito escrevê-lo.

---

## 2. Entrada e saída

`cin` lê da entrada padrão, `cout` escreve na saída padrão.

```cpp
int n;
cin >> n;                 // lê um inteiro

int a, b;
cin >> a >> b;            // lê dois inteiros (separados por espaço ou quebra de linha)

cout << "Soma: " << a + b << "\n";
```

- `>>` ignora espaços em branco e quebras de linha automaticamente.
- Prefira `"\n"` a `endl`. O `endl` além de quebrar linha força um *flush* do
  buffer, e milhares de flushes deixam o programa lento.

### Lendo linhas inteiras

```cpp
string linha;
getline(cin, linha);      // lê até a quebra de linha, incluindo espaços
```

Cuidado com a armadilha clássica: se você usa `cin >> n` e depois `getline`, o
`getline` lê o resto vazio da linha do `n`. Solução:

```cpp
int n;
cin >> n;
cin.ignore();             // descarta o '\n' pendente
string linha;
getline(cin, linha);
```

### Lendo até o fim da entrada

Muitos problemas não informam a quantidade de casos de teste:

```cpp
int x;
while (cin >> x) {
    // processa x até a entrada acabar
}
```

### Controlando casas decimais

```cpp
double media = 7.3333;
cout << fixed << setprecision(2) << media << "\n";   // 7.33
```

---

## 3. Tipos de dados

| Tipo | Tamanho | Faixa aproximada                   |
|---|---|------------------------------------|
| `int` | 4 bytes | $-2 \cdot 10^9$ a $2 \cdot 10^9$                 |
| `long long` | 8 bytes | $-9 \cdot 10^{18}$ a $9 \cdot 10^{18}$               |
| `unsigned int` | 4 bytes | $0$ a $4 \cdot 10^9$                        |
| `float` | 4 bytes | $\approx 7$ dígitos significativos          |
| `double` | 8 bytes | $\approx 15$ dígitos significativos         |
| `char` | 1 byte | um caractere (`'a'`, `'Z'`, `'0'`) |
| `bool` | 1 byte | `true` / `false`                   |
| `string` | variável | texto                              |

**O erro mais comum em competições é o *overflow* de `int`.** Se o resultado
puder passar de $2\,147\,483\,647$, use `long long`:

```cpp
long long soma = 0;
for (int i = 0; i < n; i++) soma += v[i];
```

Atenção: mesmo guardando em `long long`, a conta `a * b` com `a` e `b` do tipo
`int` é feita em `int` e transborda **antes** de ser atribuída. Force o tipo:

```cpp
long long p = (long long) a * b;
```

### Declaração e constantes

```cpp
int n = 10;
const int MAXN = 100005;   // constante — não pode ser alterada
double pi = 3.14159265358979;
char c = 'A';
string nome = "Gustavo";
bool ok = true;
```

---

## 4. Operadores

**Aritméticos:** `+`, `-`, `*`, `/`, `%`

```cpp
7 / 2      // 3   (divisão inteira!)
7.0 / 2    // 3.5 (basta um operando ser real)
7 % 2      // 1   (resto da divisão)
```

**Relacionais:** `==`, `!=`, `<`, `>`, `<=`, `>=` — resultam em `true`/`false`.

**Lógicos:** `&&` (e), `||` (ou), `!` (não).

**Atribuição composta:** `+=`, `-=`, `*=`, `/=`, `%=`.

**Incremento/decremento:** `i++`, `++i`, `i--`, `--i`.

**Bit a bit:** `&`, `|`, `^`, `~`, `<<`, `>>`.
`x << 1` dobra `x`; `x >> 1` divide por 2; `x & 1` diz se `x` é ímpar.

---

## 5. Estruturas condicionais

```cpp
if (nota >= 7.0) {
    cout << "Aprovado\n";
} else if (nota >= 5.0) {
    cout << "Recuperacao\n";
} else {
    cout << "Reprovado\n";
}
```

Operador ternário — um `if/else` em uma linha:

```cpp
cout << (a > b ? a : b) << "\n";   // imprime o maior
```

`switch` para comparar um valor contra várias constantes:

```cpp
switch (opcao) {
    case 1: cout << "Um\n";   break;
    case 2: cout << "Dois\n"; break;
    default: cout << "Invalido\n";
}
```

Sem o `break`, a execução "vaza" para o próximo caso.

---

## 6. Laços de repetição

```cpp
// for: quando você sabe quantas iterações
for (int i = 0; i < n; i++) {
    cout << i << "\n";
}

// while: enquanto a condição for verdadeira
while (n > 0) {
    n /= 2;
}

// do-while: executa ao menos uma vez
do {
    cin >> x;
} while (x != 0);
```

`break` sai do laço imediatamente; `continue` pula para a próxima iteração.

Laços aninhados são a base de matrizes e de algoritmos $O(n^2)$:

```cpp
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        cout << mat[i][j] << " ";
```

---

## 7. Vetores e matrizes (arrays estáticos)

```cpp
int v[100];               // 100 inteiros, índices de 0 a 99
int w[5] = {1, 2, 3, 4, 5};
int mat[100][100];        // matriz 100x100
```

Leitura típica:

```cpp
int n;
cin >> n;
int v[n];                 // funciona no g++, mas não é C++ padrão
for (int i = 0; i < n; i++) cin >> v[i];
```

O mais seguro é declarar com tamanho máximo constante e **globalmente**:

```cpp
const int MAXN = 100005;
int v[MAXN];

int main () {
    // ...
}
```

Arrays globais são zerados automaticamente; arrays locais contêm lixo.
Além disso, arrays grandes declarados dentro do `main` podem estourar a pilha —
declare-os fora dela.

> Índices começam em 0 e vão até `tamanho - 1`. Acessar fora disso não gera erro
> de compilação, mas causa comportamento indefinido (o famoso *runtime error*).

---

## 8. Strings

```cpp
string s = "olimpiada";
cout << s.size() << "\n";     // 9 — quantidade de caracteres
cout << s[0] << "\n";         // 'o' — acesso por índice
s += " brasileira";           // concatenação
```

Percorrendo caractere a caractere:

```cpp
for (int i = 0; i < (int) s.size(); i++) {
    if (s[i] == 'a') cout << "achei um a na posicao " << i << "\n";
}
```

Caracteres são números na tabela ASCII, o que permite truques úteis:

```cpp
char d = '7';
int valor = d - '0';          // 7
char maiuscula = 'a' - 32;    // 'A'  (ou use toupper('a'))
```

> Compare `s.size()` com um `int` usando cast: `s.size()` retorna um tipo sem
> sinal, e uma comparação com um `int` negativo dá resultado inesperado.

---

## 9. Funções

```cpp
int soma (int a, int b) {
    return a + b;
}

void imprime (int x) {       // void = não retorna nada
    cout << x << "\n";
}

int main () {
    imprime(soma(2, 3));     // 5
}
```

A função precisa ser declarada **antes** de ser usada.

### Recursão

```cpp
long long fatorial (int n) {
    if (n <= 1) return 1;          // caso base
    return n * fatorial(n - 1);    // caso recursivo
}
```

Toda função recursiva precisa de um caso base, senão a pilha estoura.

---

## 10. Structs

Agrupam dados relacionados sob um mesmo nome:

```cpp
struct Aluno {
    string nome;
    int idade;
    double nota;
};

int main () {
    Aluno a;
    a.nome = "Ana";
    a.idade = 17;
    a.nota = 9.5;

    cout << a.nome << " tirou " << a.nota << "\n";
}
```

---

## 11. Erros clássicos em competição

| Sintoma | Causa provável |
|---|---|
| *Wrong Answer* só em casos grandes | overflow de `int` — troque por `long long` |
| *Time Limit Exceeded* com I/O pesado | faltou `sync_with_stdio(false)` ou usou `endl` |
| *Runtime Error* | acesso fora dos limites do array, divisão por zero, recursão infinita |
| *Presentation Error* | quebra de linha ou espaço a mais/a menos na saída |
| Comparação de `double` falhando | use `fabs(a - b) < 1e-9` em vez de `a == b` |

> [!NOTE]
> **Outras dicas:**
> - Leia o formato da saída com atenção: acentos, maiúsculas e a quebra de linha
  final importam.
> - Não imprima textos como `"Digite um numero:"` — o juiz compara a saída
  caractere a caractere.
> - Estime a complexidade antes de codar: um juiz típico executa da ordem de
  $10^8$ operações simples por segundo.

---

## 12. Exemplo completo

Problema: ler `n` e depois `n` inteiros; imprimir a soma e a média com duas
casas decimais.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    long long soma = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        soma += x;
    }

    double media = (double) soma / n;

    cout << "Soma: " << soma << "\n";
    cout << "Media: " << fixed << setprecision(2) << media << "\n";

    return 0;
}
```

