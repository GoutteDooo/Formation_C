const CONNEXION = document.getElementById("connexion");
const INTERNET_PAGE = document.getElementById("internet-page");
const returnBtn = document.getElementById("return");

const player_object = JSON.parse(localStorage.getItem("player"));

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
    INTERNET_PAGE.removeChild(CONNEXION);
    // Display player's page
    createPlayerPage();
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

const createPlayerPage = () => {
  const NAVBAR = document.createElement("div");
  NAVBAR.id = "page-navbar";
  INTERNET_PAGE.appendChild(NAVBAR);
  const LOGO = document.createElement("div");
  LOGO.id = "page-logo";
  NAVBAR.appendChild(LOGO);
  LOGO.textContent = "Trade Village";
  const PROFILE = document.createElement("div");
  PROFILE.id = "page-profile";
  NAVBAR.appendChild(PROFILE);
  PROFILE.textContent = player_object.name;
}