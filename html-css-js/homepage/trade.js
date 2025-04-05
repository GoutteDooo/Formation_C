const CONNEXION = document.getElementById("connexion");
const returnBtn = document.getElementById("return");

document.addEventListener("DOMContentLoaded", () => {
  returnBtn.addEventListener("mouseup", () => {
    window.location.href = "village.html";
  });
  updatePage();
});



const updatePage = () => {
  connexion();
  setTimeout(() => {
    CONNEXION.textContent = "Afficher les objets";
    // Display objects of player
    // Display button to buy sthg (ordering will take time)
    // Display button to put sthg to sell
    // Display Invest button to start trading
  }, 2500);
}

const connexion = () => {
  CONNEXION.textContent = "Connecting to the internet";
  let dots = 0;
  const randomTime = Math.floor(Math.random() * 1000) + 1000;
  let interval = setInterval(() => {
    CONNEXION.textContent += '.';
    dots++;
    if (dots > 3) {
    CONNEXION.textContent = "Connecting to the internet";
    dots = 0;
    }
  },300)

  setTimeout(() => {
    clearInterval(interval);
    CONNEXION.textContent = "Connected !";
  }, randomTime);
}