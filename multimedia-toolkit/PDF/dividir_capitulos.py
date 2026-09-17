import pymupdf, os, re

pdf_list = [file for file in os.listdir() if '.pdf' in file]

ARQUIVO_PDF = pdf_list[0]
PASTA_SAIDA = "capitulos"

os.makedirs(PASTA_SAIDA, exist_ok=True)

pdf = pymupdf.open(ARQUIVO_PDF)

# Tenta obter o índice/bookmarks do PDF

toc = pdf.get_toc()

print(f"Total de páginas: {len(pdf)}")
print(f"Entradas no índice do PDF: {len(toc)}")


# Mostra o índice encontrado
print("\nÍNDICE DO PDF:")
print("-" * 60)

for nivel, titulo, pagina in toc:
    print(f"Nível {nivel}: {titulo} -> página {pagina}")


# Seleciona apenas entradas de primeiro nível

capitulos = []

for nivel, titulo, pagina in toc:

    if nivel == 1:
        capitulos.append({
            "titulo": titulo,
            "pagina": pagina - 1
        })


if not capitulos:
    print("\nNenhum capítulo de nível 1 encontrado.")
    print("O PDF provavelmente não possui bookmarks de capítulos.")

    pdf.close()
    exit()


print(f"\n{len(capitulos)} capítulos encontrados.")

# Dividir o PDF

for i, capitulo in enumerate(capitulos):

    pagina_inicio = capitulo["pagina"]

    if i + 1 < len(capitulos):
        pagina_fim = capitulos[i + 1]["pagina"] - 1
    else:
        pagina_fim = len(pdf) - 1


    titulo = capitulo["titulo"]


    # Remove caracteres inválidos do nome do arquivo
    nome = re.sub(r'[\\/*?:"<>|]', "", titulo)

    # Evita nomes grandes
    nome = nome[:100]

    caminho = os.path.join(PASTA_SAIDA, f"{i + 1:02d}_{nome}.pdf")

    novo_pdf = pymupdf.open()

    novo_pdf.insert_pdf(
        pdf,
        from_page=pagina_inicio,
        to_page=pagina_fim
    )

    novo_pdf.save(caminho)
    novo_pdf.close()


    print(
        f"[OK] {titulo}\n"
        f"     páginas {pagina_inicio + 1} até {pagina_fim + 1}\n"
        f"     -> {caminho}\n"
    )


pdf.close()

print("Divisão concluída!")