;(async function () {
  const BATCH_SIZE = 5;              // comentários por lote
  const COOLDOWN_EVERY = 10;         // lotes antes do descanso
  const COOLDOWN_MS = 120000;        // 2 min de descanso
  const MIN_DELAY = 3000;
  const MAX_DELAY = 8000;

  const sleep = ms => new Promise(r => setTimeout(r, ms));
  const jitter = () => MIN_DELAY + Math.random() * (MAX_DELAY - MIN_DELAY);

  const click = async el => {
    if (!el) return false;
    el.scrollIntoView({ block: "center" });
    await sleep(120);
    el.click();
    return true;
  };

  const getButtons = () =>
    [...document.querySelectorAll("button, div[role='button'], span")]
      .filter(el => !!el.offsetParent);

  const findText = t =>
    getButtons().find(el => (el.innerText || el.textContent || "").trim() === t);

  const waitForText = async (t, seconds = 20) => {
    for (let i = 0; i < seconds * 2; i++) {
      const el = findText(t);
      if (el) return el;
      await sleep(500);
    }
    return null;
  };

  const dismissError = async () => {
    const ok = findText("OK");
    if (ok) {
      console.log("Popup de erro — dispensando.");
      await click(ok);
      await sleep(2000);
      return true;
    }
    return false;
  };

  let batchCount = 0;

  for (let round = 1; round <= 999; round++) {
    console.log("Rodada", round);
    await dismissError();

    const selectBtn = await waitForText("Select", 25);
    if (!selectBtn) { console.log("Sem botão Select — parando."); break; }
    await click(selectBtn);
    await sleep(1000);

    let boxes = [...document.querySelectorAll('[aria-label="Toggle checkbox"]')];
    for (let i = 0; i < 15 && !boxes.length; i++) {
      await sleep(1000);
      boxes = [...document.querySelectorAll('[aria-label="Toggle checkbox"]')];
    }

    if (!boxes.length) { console.log("Sem checkboxes — parando."); break; }

    const amount = Math.min(BATCH_SIZE, boxes.length);
    console.log("Selecionando", amount, "comentários");
    for (let i = 0; i < amount; i++) { await click(boxes[i]); await sleep(80); }
    await sleep(800);

    let deletes = getButtons().filter(el => (el.innerText || el.textContent || "").trim() === "Delete");
    if (!deletes.length) { console.log("Sem botão Delete — parando."); break; }
    await click(deletes[deletes.length - 1]);
    await sleep(2500);

    deletes = getButtons().filter(el => (el.innerText || el.textContent || "").trim() === "Delete");
    if (!deletes.length) { console.log("Sem confirmação — parando."); break; }
    await click(deletes[deletes.length - 1]);
    console.log("Lote apagado");

    batchCount++;
    if (batchCount % COOLDOWN_EVERY === 0) {
      console.log("Descanso de 2 min...");
      await sleep(COOLDOWN_MS);
    } else {
      await sleep(jitter());
    }
  }
  console.log("Terminou");
})();