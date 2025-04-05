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
  //navbar
  const NAVBAR = document.createElement("div");
  NAVBAR.id = "page-navbar";
  INTERNET_PAGE.appendChild(NAVBAR);
  const LOGO = document.createElement("div");
  LOGO.id = "page-logo";
  NAVBAR.appendChild(LOGO);
  LOGO.textContent = "Trade Village 💰";
  const PROFILE = document.createElement("div");
  PROFILE.id = "page-profile";
  NAVBAR.appendChild(PROFILE);
  PROFILE.textContent = player_object.name;

  //body
  const PAGE_BODY = document.createElement("div");
  PAGE_BODY.id = "page-body";
  INTERNET_PAGE.appendChild(PAGE_BODY);
  //buttons
  const BODY_BUTTONS = document.createElement("div");
  BODY_BUTTONS.id = "body-buttons";
  PAGE_BODY.appendChild(BODY_BUTTONS);
  const BUTTON_PROFILE = document.createElement("button");
  BUTTON_PROFILE.id = "page-btn-profile";
  BUTTON_PROFILE.textContent = "See your profile";
  BUTTON_PROFILE.addEventListener("click", showProfile);
  BODY_BUTTONS.appendChild(BUTTON_PROFILE);
  const BUTTON_BUY = document.createElement("button");
  BUTTON_BUY.id = "page-btn-buy";
  BUTTON_BUY.textContent = "Buy";
  BODY_BUTTONS.appendChild(BUTTON_BUY);
  BUTTON_BUY.addEventListener("click", buy);
  const BUTTON_SELL = document.createElement("button");
  BUTTON_SELL.id = "page-btn-sell";
  BUTTON_SELL.textContent = "Sell";
  BODY_BUTTONS.appendChild(BUTTON_SELL);
  BUTTON_SELL.addEventListener("click", sell);
}

const showProfile = () => {
  const player_object = JSON.parse(localStorage.getItem("player"));
  console.log("show profile");
  
}

const buy = () => {
  const player_object = JSON.parse(localStorage.getItem("player"));
  console.log("buy");
}

const sell = () => {
  const player_object = JSON.parse(localStorage.getItem("player"));
  console.log("sell");
}