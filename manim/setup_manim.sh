```bash
#!/usr/bin/env bash

set -e

echo "======================================"
echo "       Configurador de projeto Manim"
echo "======================================"
echo

# Verifica se está rodando em Debian/Ubuntu/Mint
if ! command -v apt >/dev/null 2>&1; then
    echo "Erro: este script precisa de uma distribuição baseada em Debian/Ubuntu."
    exit 1
fi

echo "[1/5] Atualizando lista de pacotes..."
sudo apt update

echo
echo "[2/5] Instalando dependências do sistema..."
sudo apt install -y \
    python3-full \
    python3-venv \
    python3-dev \
    build-essential \
    pkg-config \
    libcairo2-dev \
    libpango1.0-dev \
    libpangocairo-1.0-0 \
    ffmpeg \
    texlive-latex-base \
    texlive-latex-extra \
    texlive-fonts-extra \
    texlive-latex-recommended \
    texlive-science \
    tipa

echo
echo "[3/5] Criando ambiente virtual..."

if [ ! -d ".venv" ]; then
    python3 -m venv .venv
    echo "    .venv criado."
else
    echo "    .venv já existe."
fi

echo
echo "[4/5] Instalando Manim..."

source .venv/bin/activate

python -m pip install --upgrade pip setuptools wheel
python -m pip install --upgrade manim

echo
echo "[5/5] Verificando instalação..."

if ! command -v manim >/dev/null 2>&1; then
    echo
    echo "ERRO: Manim não foi encontrado."
    exit 1
fi

echo
echo "======================================"
echo "        Manim instalado com sucesso!"
echo "======================================"
echo

manim --version

echo
echo "Ambiente virtual:"
echo "    .venv"

echo
echo "Para ativá-lo novamente:"
echo "    source .venv/bin/activate"

echo
echo "Para testar:"
echo "    manim -pql seu_arquivo.py NomeDaScene"
echo
```
