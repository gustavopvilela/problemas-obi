# Vector

Este material continua a Introdução ao C++. Aqui começamos a
usar a **STL** (*Standard Template Library*), a biblioteca pronta que vem com o C++.
A primeira ferramenta dela — e a mais usada em competições — é o `vector`.

---

## 1. Por que existe o `vector`?

Com arrays comuns, você precisa decidir o tamanho **antes** de rodar o programa:

```cpp
int v[100];    // e se o problema pedir 101 números? E se pedir só 3?
```

O `vector` resolve isso. Ele é uma lista de elementos do mesmo tipo que:

- **cresce e diminui** durante a execução;
- **sabe o próprio tamanho** (`v.size()`);
- pode ser **copiado, comparado e devolvido por uma função**, coisas que um array
  comum não faz;
- é usado exatamente como um array: `v[0]`, `v[1]`, `v[2]`...

Pense nele como uma "fila de caixas numeradas" na qual você pode encaixar uma
caixa nova no fim sempre que precisar.

> [!NOTE]
> O `vector` faz parte do cabeçalho `<vector>`, mas como usamos
> `#include <bits/stdc++.h>`, ele já vem junto — não precisa incluir nada a mais.

---

## 2. Criando um vector

```cpp
vector<int> a;                  // vazio, tamanho 0
vector<int> b(10);              // 10 inteiros, todos valendo 0
vector<int> c(10, 7);           // 10 inteiros, todos valendo 7
vector<int> d = {4, 8, 15, 16}; // já com esses valores
vector<int> e = d;              // cópia independente de d

vector<double> notas;           // funciona com qualquer tipo
vector<string> nomes;
vector<char> letras;
```

O que vai entre `< >` é o **tipo** dos elementos. `vector<int>` guarda inteiros,
`vector<string>` guarda strings, e assim por diante.

> [!WARNING]
> `vector<int> b(10);` cria 10 elementos. `vector<int> b = {10};` cria **um**
> elemento valendo 10. Parecem iguais, mas não são.

---

## 3. As operações do dia a dia

### Adicionar no fim: `push_back`

```cpp
vector<int> v;      // v = {}
v.push_back(5);     // v = {5}
v.push_back(3);     // v = {5, 3}
v.push_back(9);     // v = {5, 3, 9}
```

### Tamanho: `size`

```cpp
cout << v.size() << "\n";   // 3
```

### Acessar um elemento: `[ ]`

```cpp
cout << v[0] << "\n";       // 5  (o primeiro é o índice 0!)
cout << v[2] << "\n";       // 9  (o último é o índice size() - 1)
v[1] = 100;                 // v = {5, 100, 9}
```

### Remover do fim: `pop_back`

```cpp
v.pop_back();               // v = {5, 100}
```

### Esvaziar: `clear`

```cpp
v.clear();                  // v = {}, size() vira 0
```

---

## 4. Lendo e imprimindo um vector

Quando o problema diz quantos números virão:

```cpp
int n;
cin >> n;

vector<int> v(n);                       // já cria com n posições
for (int i = 0; i < n; i++) cin >> v[i];
```

Quando você **não** sabe quantos virão:

```cpp
vector<int> v;
int x;
while (cin >> x) v.push_back(x);        // lê até a entrada acabar
```

Imprimindo:

```cpp
for (int i = 0; i < (int) v.size(); i++) {
    cout << v[i];
    if (i + 1 < (int) v.size()) cout << " ";   // espaço só entre os números
}
cout << "\n";
```

Existe uma forma mais curta de percorrer, o **for baseado em intervalo**:

```cpp
for (int x : v) cout << x << " ";       // lê cada elemento como cópia
cout << "\n";

for (int &x : v) x *= 2;                // com & você altera o vector
```

> [!WARNING]
> `v.size()` devolve um tipo **sem sinal**. Se você escrever
> `for (int i = 0; i <= v.size() - 1; i++)` com o vector vazio,
> `v.size() - 1` não vira `-1`: vira um número gigante e o laço roda para sempre.
> Por isso usamos `(int) v.size()` ou a forma `i < v.size()`.

---

## 5. Tabela de funções do `vector`

Considere `vector<int> v;` em todos os exemplos.

### Tamanho e estado

| Função | O que faz | Exemplo |
|---|---|---|
| `v.size()` | quantos elementos há | `if (v.size() == 0) ...` |
| `v.empty()` | `true` se está vazio | `if (v.empty()) ...` |
| `v.resize(k)` | passa a ter exatamente `k` elementos (sobra vira 0, excesso é cortado) | `v.resize(5);` |
| `v.resize(k, x)` | idem, preenchendo as novas posições com `x` | `v.resize(5, -1);` |
| `v.clear()` | remove tudo | `v.clear();` |
| `v.assign(k, x)` | substitui todo o conteúdo por `k` cópias de `x` | `v.assign(n, 0);` |

### Acesso a elementos

| Função | O que faz | Exemplo |
|---|---|---|
| `v[i]` | elemento da posição `i` (não confere se existe) | `v[3]` |
| `v.at(i)` | igual, mas acusa erro se `i` for inválido | `v.at(3)` |
| `v.front()` | primeiro elemento (mesmo que `v[0]`) | `cout << v.front();` |
| `v.back()` | último elemento (mesmo que `v[v.size()-1]`) | `cout << v.back();` |

### Inserir e remover

| Função | O que faz | Exemplo |
|---|---|---|
| `v.push_back(x)` | acrescenta `x` no fim | `v.push_back(7);` |
| `v.pop_back()` | remove o último | `v.pop_back();` |
| `v.emplace_back(x)` | como `push_back`, porém constrói o elemento no lugar (mais rápido para tipos grandes) | `v.emplace_back(7);` |
| `v.insert(v.begin() + i, x)` | insere `x` na posição `i`, empurrando o resto | `v.insert(v.begin()+2, 9);` |
| `v.erase(v.begin() + i)` | apaga o elemento da posição `i` | `v.erase(v.begin()+2);` |
| `v.erase(v.begin()+i, v.begin()+j)` | apaga do índice `i` até `j-1` | `v.erase(v.begin(), v.begin()+3);` |
| `v.swap(w)` | troca o conteúdo de dois vectors | `v.swap(w);` |

> [!WARNING]
> `insert` e `erase` no **meio** do vector precisam deslocar todos os elementos
> seguintes. Fazer isso dentro de um laço grande deixa o programa lento
> ($O(n)$ por operação). Sempre que possível, adicione e remova pelo fim, com
> `push_back` / `pop_back`, que são instantâneos.

### Posições (iteradores)

Um **iterador** é uma forma de apontar para uma posição do vector. Você o usará
principalmente para passar intervalos às funções da próxima seção.

| Função | O que faz |
|---|---|
| `v.begin()` | aponta para o primeiro elemento |
| `v.end()` | aponta para **depois** do último (não é um elemento válido) |
| `v.rbegin()` / `v.rend()` | os mesmos, na ordem invertida |

A dupla `v.begin(), v.end()` significa, na prática, "o vector inteiro".

### Capacidade (raramente necessário)

| Função | O que faz |
|---|---|
| `v.capacity()` | quanto espaço já está reservado na memória |
| `v.reserve(k)` | reserva espaço para `k` elementos de uma vez, evitando realocações |
| `v.shrink_to_fit()` | devolve a memória sobrando |

Isso só importa quando você vai inserir milhões de elementos; para a maioria dos
problemas, ignore.

---

## 6. Funções de `<algorithm>` que valem ouro

Não são funções do `vector`, mas trabalham com ele e resolvem meio problema
sozinhas. Todas recebem o intervalo `v.begin(), v.end()`.

| Função | O que faz |
|---|---|
| `sort(v.begin(), v.end())` | ordena em ordem crescente |
| `sort(v.rbegin(), v.rend())` | ordena em ordem **decrescente** |
| `reverse(v.begin(), v.end())` | inverte a ordem dos elementos |
| `max_element(v.begin(), v.end())` | aponta para o maior elemento |
| `min_element(v.begin(), v.end())` | aponta para o menor elemento |
| `count(v.begin(), v.end(), x)` | quantas vezes `x` aparece |
| `find(v.begin(), v.end(), x)` | procura `x`; devolve `v.end()` se não achar |
| `accumulate(v.begin(), v.end(), 0LL)` | soma todos os elementos |
| `binary_search(v.begin(), v.end(), x)` | diz se `x` existe (**exige vector ordenado**) |
| `lower_bound(v.begin(), v.end(), x)` | primeira posição $\geq x$ (exige ordenado) |
| `unique(v.begin(), v.end())` | junta repetidos vizinhos no início (use após `sort`) |

Exemplos:

```cpp
vector<int> v = {5, 2, 9, 2, 7};

sort(v.begin(), v.end());                    // v = {2, 2, 5, 7, 9}

cout << *max_element(v.begin(), v.end());    // 9   (o * pega o valor apontado)
cout << count(v.begin(), v.end(), 2);        // 2

long long soma = accumulate(v.begin(), v.end(), 0LL);   // 25

reverse(v.begin(), v.end());                 // v = {9, 7, 5, 2, 2}
```

Removendo elementos repetidos (padrão muito comum):

```cpp
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());   // agora v só tem valores distintos
```

Verificando se um valor está presente:

```cpp
if (find(v.begin(), v.end(), 7) != v.end()) cout << "achei\n";
```

> [!NOTE]
> Use `0LL` (e não `0`) em `accumulate` quando a soma puder passar do limite do
> `int` — esse terceiro argumento define o tipo da soma.

---

## 7. Vector de duas dimensões (matriz)

Um `vector` pode guardar outros `vector`s. É assim que se faz uma matriz de
tamanho definido durante a execução:

```cpp
int n, m;
cin >> n >> m;

vector<vector<int>> mat(n, vector<int>(m, 0));   // n linhas, m colunas, tudo 0

for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        cin >> mat[i][j];
```

Lendo em voz alta: "um vector com `n` posições, e cada posição é um vector de
`m` inteiros valendo 0".

- `mat.size()` → número de linhas
- `mat[0].size()` → número de colunas

---

## 8. Vector em funções

Diferente de arrays, um `vector` pode ser passado e devolvido normalmente:

```cpp
// recebe uma CÓPIA — alterações não afetam o original
int soma (vector<int> v) {
    int s = 0;
    for (int x : v) s += x;
    return s;
}

// recebe por REFERÊNCIA — sem cópia e podendo alterar o original
void dobra (vector<int> &v) {
    for (int &x : v) x *= 2;
}

// referência constante: sem cópia, mas proibido alterar (o ideal para só ler)
int maior (const vector<int> &v) {
    return *max_element(v.begin(), v.end());
}

// devolvendo um vector
vector<int> pares (const vector<int> &v) {
    vector<int> r;
    for (int x : v) if (x % 2 == 0) r.push_back(x);
    return r;
}
```

> [!WARNING]
> Copiar um vector grande custa tempo. Em competição, passe sempre por
> referência (`&`) — use `const vector<int> &v` quando a função só precisa ler.

---

## 9. Erros comuns

| Erro | O que acontece |
|---|---|
| `v[5]` com `v.size() == 3` | lixo ou *runtime error*; o `vector` **não** cresce sozinho no acesso |
| Usar `v[i] = x` para adicionar | não funciona se a posição não existir; use `push_back` |
| `v.size() - 1` com vector vazio | vira um número enorme (tipo sem sinal) |
| `binary_search` sem ordenar antes | resposta errada, sem aviso |
| Guardar `v.back()` e depois dar `push_back` | referências antigas podem ficar inválidas após o vector crescer |
| Passar vector grande por valor | *Time Limit Exceeded* por causa das cópias |

---

## 10. Exemplo completo

Problema: ler `n` notas, imprimir a média, a maior nota e as notas em ordem
crescente.

```cpp
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<double> notas(n);
    for (int i = 0; i < n; i++) cin >> notas[i];

    double soma = accumulate(notas.begin(), notas.end(), 0.0);
    double media = soma / n;
    double maior = *max_element(notas.begin(), notas.end());

    sort(notas.begin(), notas.end());

    cout << fixed << setprecision(2);
    cout << "Media: " << media << "\n";
    cout << "Maior: " << maior << "\n";
    cout << "Ordenadas:";
    for (double x : notas) cout << " " << x;
    cout << "\n";

    return 0;
}
```

---

## Resumo rápido

```cpp
vector<int> v;              // cria
v.push_back(x);             // adiciona no fim
v.pop_back();               // remove do fim
v[i]                        // acessa
v.size()                    // tamanho
v.empty()                   // está vazio?
v.clear()                   // esvazia
v.front() / v.back()        // primeiro / último
sort(v.begin(), v.end());   // ordena
```
