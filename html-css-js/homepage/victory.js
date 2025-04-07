function animateText() {
  const TEXT = document.querySelector("h1");
  // Appliquer l'animation de couleurs et rotation
  TEXT.classList.add("animate-colorRotate");
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