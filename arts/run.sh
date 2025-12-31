#!/bin/bash

# Nome do arquivo C
FILE="christmastree.c"

# Gera o executável com o mesmo nome (sem extensão)
EXEC="${FILE%.c}"

# Compila o código
gcc "$FILE" -o "$EXEC"

# Checa se a compilação deu certo
if [ $? -eq 0 ]; then
    echo "Compilação bem-sucedida! Rodando o programa..."
    ./"$EXEC"
else
    echo "Erro na compilação!"
fi
