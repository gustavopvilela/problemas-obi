# Problemas de Programação Competitiva

Repositório com soluções em **C++** para problemas de programação competitiva
(plataforma [beecrowd](https://judge.beecrowd.com/)), utilizados no projeto de ensino do IFMG - Campus Formiga, com foco na preparação para a
**OBI — Olimpíada Brasileira de Informática**.

Além das soluções, o repositório reúne os enunciados em PDF e material de estudo sobre
os tópicos utilizados.

## Estrutura

```
.
├── <numero>.cpp        # solução de cada problema, nomeada pelo ID do problema
├── pdfs/               # enunciados dos problemas em PDF
├── material/           # material de estudo (Markdown + PDF)
└── CMakeLists.txt      # gera um executável por arquivo .cpp
```

Cada tópico também está disponível em PDF na mesma pasta.

## Compilando

O `CMakeLists.txt` percorre todos os arquivos `.cpp` do repositório e cria um alvo
para cada um, usando o padrão **C++20**.

```bash
cmake -S . -B cmake-build-debug
cmake --build cmake-build-debug
```

O executável de um problema específico pode ser gerado com:

```bash
cmake --build cmake-build-debug --target 1176
```

Alternativamente, para compilar um único arquivo manualmente:

```bash
g++ -std=c++20 -O2 -o 1176 1176.cpp
```

> As soluções usam `#include <bits/stdc++.h>`, extensão disponível no GCC.

## Executando

Os problemas leem da entrada padrão e escrevem na saída padrão:

```bash
./1176 < entrada.txt
```
