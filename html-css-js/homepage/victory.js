function animateText() {
  const text = document.querySelector("h1").textContent;
  let index_text = 0;
  const colors = [
    "#00ff00",
    "#ff0000",
    "#0000ff",
    "#ffff00",
    "#ff00ff",
    "#00ffff",
    "#000000",
    "#ffffff",
    "#ff0000",
    "#00ff00",
    "#0000ff",
  ]
  setInterval(() => {
    text[index_text] = "a";
    index_text++;
  }, 100);
}

function removeFadeOut() {
  const FADE_OUT = document.querySelector("#fade-out");

  setTimeout(() => {
    FADE_OUT.remove();
  }, 3000);
}

function initVictory() {
  removeFadeOut();
  animateText();
}

initVictory();