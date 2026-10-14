# Limpador de Comentários do Instagram

Script de console que apaga **todos os comentários que você fez**, em qualquer perfil,
automatizando a página "Sua atividade" do Instagram.

Feito porque a API oficial da Meta não resolve esse caso: ela só lê e deleta comentários
em mídia que você **possui**, e não existe endpoint de "todos os comentários que eu fiz".

---

## Requisitos

- Chrome (ou derivado) **de desktop** — não funciona no app do celular
- Logado no Instagram no navegador
- **Idioma do Instagram e do navegador em inglês (US)** — obrigatório, o script busca
  pelos textos `Select`, `Delete` e `OK`
- Paciência: alguns minutos a algumas horas, dependendo do volume

---

## Como usar

1. Abra a página de comentários:

   ```
   https://www.instagram.com/your_activity/interactions/comments
   ```

2. **Não clique em "Select".** A página precisa estar no estado normal.

3. Abra o console:
   - `Ctrl + Shift + J` (Windows/Linux)
   - `Cmd + Option + J` (macOS)
   - ou `F12` → aba **Console**

4. Se o Chrome bloquear o `Ctrl+V`, digite `allow pasting` no console, dê Enter,
   e só então cole.

5. Cole o script abaixo e aperte **Enter**.

6. **Não feche nem troque de aba.** O Chrome pausa os timers em aba de fundo.
   Se precisar usar o PC, abra outra janela — não outra aba.

7. **Não clique em nada na página.** O script está clicando por você.

---

## Saída esperada

```
Rodada 1
Selecionando 5 comentários
Lote apagado
Rodada 2
...
```

Popups `Something went wrong` vão aparecer de vez em quando. É normal — é o rate limit
do Instagram, e o script fecha sozinho e continua.

---

## Configuração

Ajuste as constantes no topo do script:

| Constante | Padrão | O que faz |
| --- | --- | --- |
| `BATCH_SIZE` | `5` | Comentários apagados por lote. Aumentar = mais rápido, mais risco |
| `COOLDOWN_EVERY` | `10` | Quantos lotes antes de pausar |
| `COOLDOWN_MS` | `120000` | Duração da pausa (2 min) |
| `MIN_DELAY` | `3000` | Delay mínimo entre lotes |
| `MAX_DELAY` | `8000` | Delay máximo entre lotes |

Ritmo aproximado com os padrões: **~800 comentários/hora**.

Para ser mais conservador (menos popups de erro, mais tempo): suba `MIN_DELAY`,
`MAX_DELAY` e `COOLDOWN_MS`.

---

## Por que os delays existem

O Instagram trata exclusão de comentário como **ação**, igual curtir e seguir, e tem
teto de ações por hora. Passar do teto gera:

1. Popup `Something went wrong` — freio leve, recupera sozinho
2. **Bloqueio de ação de 24h** — se você insistir depois do aviso

O `jitter` aleatório existe para não criar padrão perfeito de bot. A pausa de 2 minutos
a cada 10 lotes derruba a média e dá tempo do contador esfriar.

Além disso, depois de cada lote a página recarrega a lista inteira e recria os checkboxes.
Clicar rápido demais faz o script pegar o DOM no meio da reconstrução — aí ele marca os
mesmos comentários de novo ou não acha nenhum checkbox.

---

## Avisos

- **Não tem lixeira.** Deletou, foi.
- Isso apaga **tudo**, inclusive comentários que você fez nos **seus próprios** posts.
- Antes de rodar, considere exportar seus dados para revisar:
  Configurações → Sua atividade → Baixar suas informações.

---

## Troubleshooting

| Sintoma | Causa provável | Solução |
| --- | --- | --- |
| `Sem botão Select — parando.` | Página em português | Trocar idioma do Instagram e do navegador para inglês |
| Console não aceita `Ctrl+V` | Bloqueio de paste do Chrome | Digitar `allow pasting`, Enter, depois colar |
| Para em `Sem checkboxes` | Você clicou em "Select" antes de rodar | Recarregar a página e rodar sem clicar em nada |
| Popup `Something went wrong` | Rate limit | Normal, o script dispensa e segue |
| Para de apagar por muito tempo | Rápido demais | Aumentar `MIN_DELAY` / `MAX_DELAY` / `COOLDOWN_MS` |
| Trava depois de um tempo | Aba em segundo plano | Manter a aba visível na frente |
| Apaga os mesmos comentários 2x | DOM não terminou de renderizar | Aumentar `DELAY` internos do lote |

---

## Alternativas

### Extensão do Chrome

Sobrevive a refresh da página, o que o script no console não faz.

```
https://github.com/sbolel/instagram-comment-activity-deleter
```

### Versão que chama a API interna (WebBloks)

Em vez de clicar em checkbox, dispara as requisições que a própria página usa. Bem mais
rápido e não quebra quando o Instagram muda o layout. Existe uma versão no gist abaixo,
no comentário do usuário `rlewkowicz` (setembro de 2026):

```
https://gist.github.com/sbolel/a2b2bfde16b3ab185fbc2e2049240abc
```

### instagrapi (Python)

API não-oficial. Roda headless em servidor, sem depender de navegador aberto. Ainda é
preciso enumerar as mídias e chamar `comment_delete()` para cada comentário — não existe
atalho de "apaga tudo".

---

## Créditos

Script adaptado das contribuições no gist original do
[@sbolel](https://gist.github.com/sbolel/a2b2bfde16b3ab185fbc2e2049240abc),
especialmente as versões de `CaptainGreenhat` e `Lumexio`.

## Referências

- [Instagram — Sua atividade / Comentários](https://www.instagram.com/your_activity/interactions/comments)
- [Ajuda: deletar um comentário](https://help.instagram.com/289098941190483)
- [Ajuda: deletar comentários que você fez em posts de outros](https://help.instagram.com/631948184906507/)
- [Meta — Comment Moderation API](https://developers.facebook.com/docs/instagram-platform/comment-moderation/)