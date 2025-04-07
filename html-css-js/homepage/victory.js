function animateText() {
  const text = document.querySelector("h1");
  let selector = text.textContent[0];
  console.log(selector);
  
  setInterval(() => {
    text.innerHTML = "YOU WIN !!!";
  }, 100);
}

animateText();