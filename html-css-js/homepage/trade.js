//imports
import objects from "./objects.js";

//import helper functions
import { capitalize, displayPrice } from "./helper_functions.js";

//Connexion to Browser
const CONNEXION = document.getElementById("connexion");
const INTERNET_PAGE = document.getElementById("internet-page");
const returnBtn = document.getElementById("return");

//Home Page
  //Navbar
const NAVBAR = document.createElement("div");
const LOGO = document.createElement("div");
const PROFILE = document.createElement("div");
const NUTS = document.createElement("div");
const PROFILE_NUTS = document.createElement("div");
  //Body
const PAGE_BODY = document.createElement("div");
const BODY_BUTTONS = document.createElement("div");
const BUTTON_PROFILE = document.createElement("button");
const BUTTON_BUY = document.createElement("button");
const BUTTON_SELL = document.createElement("button");

//Profile Page
const PROFILE_PAGE = document.createElement("div");
const INVENTORY = document.createElement("div");
let OBJECTS_UL = document.createElement("ul");

//Buying Page
const BUYING_PAGE = document.createElement("div");

//localstorage
let player_object = JSON.parse(localStorage.getItem("player"));
let sellers = JSON.parse(localStorage.getItem("sellers"));

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
    chargeHomePage();
    // Display objects of player
    // Display button to buy sthg (ordering will take time)
    // Display button to put sthg to sell
    // Display Invest button to start trading
  }, 2500);
}

const updateDatas = () => {
  NUTS.textContent = displayPrice(player_object.nuts);
  //remove all nodes from OBJECTS_UL
  player_object = JSON.parse(localStorage.getItem("player"));
  OBJECTS_UL.remove();
  OBJECTS_UL = document.createElement("ul");
  //add new objects to OBJECTS_UL
  for (const object of player_object.objects) {
    const OBJECT_LI = document.createElement("li");
    OBJECT_LI.textContent = capitalize(objects[object].name);
    OBJECTS_UL.appendChild(OBJECT_LI);
  }
  INVENTORY.appendChild(OBJECTS_UL);
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

const chargeHomePage = () => {
  /* navbar */
  NAVBAR.id = "page-navbar";
  INTERNET_PAGE.appendChild(NAVBAR);

  LOGO.id = "page-logo";
  LOGO.textContent = "Trade Village 💰";
  LOGO.addEventListener("click", () => loadPage(showHomePage));
  NAVBAR.appendChild(LOGO);

  PROFILE_NUTS.id = "page-profile-nuts";
  NAVBAR.appendChild(PROFILE_NUTS);

  PROFILE.id = "page-profile";
  PROFILE.addEventListener("click", () => loadPage(showProfile));
  PROFILE.textContent = player_object.name;
  PROFILE_NUTS.appendChild(PROFILE);

  NUTS.id = "page-nuts";
  NUTS.textContent = `🥜 ${player_object.nuts}`;
  PROFILE_NUTS.appendChild(NUTS);

  /* body */
  PAGE_BODY.id = "page-body";
  INTERNET_PAGE.appendChild(PAGE_BODY);
  //buttons
  BODY_BUTTONS.id = "body-buttons";
  PAGE_BODY.appendChild(BODY_BUTTONS);
  BUTTON_PROFILE.id = "page-btn-profile";
  BUTTON_PROFILE.textContent = "See your profile";
  BUTTON_PROFILE.addEventListener("click", () => loadPage(showProfile));
  BODY_BUTTONS.appendChild(BUTTON_PROFILE);
  BUTTON_BUY.id = "page-btn-buy";
  BUTTON_BUY.textContent = "Buy";
  BODY_BUTTONS.appendChild(BUTTON_BUY);
  BUTTON_BUY.addEventListener("click", () => loadPage(showBuyingPage));
  BUTTON_SELL.id = "page-btn-sell";
  BUTTON_SELL.textContent = "Sell";
  BODY_BUTTONS.appendChild(BUTTON_SELL);
  BUTTON_SELL.addEventListener("click", () => loadPage(sell));

  //other pages generation background
  generateProfile();
  generateBuyingPage();
}

const showHomePage = () => {
  INTERNET_PAGE.appendChild(PAGE_BODY);
  PAGE_BODY.appendChild(BODY_BUTTONS);
  BODY_BUTTONS.appendChild(BUTTON_PROFILE);
  BODY_BUTTONS.appendChild(BUTTON_BUY);
  BODY_BUTTONS.appendChild(BUTTON_SELL);
}

const generateProfile = () => {
  const player_object = JSON.parse(localStorage.getItem("player"));
  PROFILE_PAGE.id = "profile-page";
  PROFILE_PAGE.textContent = `Your Inventory`;
  INVENTORY.id = "inventory";
  PROFILE_PAGE.appendChild(INVENTORY);

  //display objects
  for (const object of player_object.objects) {
    const OBJECT_LI = document.createElement("li");
    OBJECT_LI.textContent = capitalize(objects[object].name);
    OBJECTS_UL.appendChild(OBJECT_LI);
  }
  INVENTORY.appendChild(OBJECTS_UL);
}

const showProfile = () => {
  PAGE_BODY.appendChild(PROFILE_PAGE);
}

const generateBuyingPage = () => {
  //Display all items sold by sellers
  BUYING_PAGE.id = "buying-page";
  for (const seller in sellers) 
  {
    const seller_object = sellers[seller];
    //Display items sold by seller
    for (const object in seller_object.selling_objects)
      //for each object sold by seller
    {
      //find object in objects data
      const sold_item_object = objects[seller_object.selling_objects[object]["id"]];

      const SOLD_ITEM_CONTAINER = document.createElement("div");
      SOLD_ITEM_CONTAINER.classList.add("sold-item-container");

      const SELLER_NAME_CONTAINER = document.createElement("div");
      SELLER_NAME_CONTAINER.classList.add("seller-name-container");
      SOLD_ITEM_CONTAINER.appendChild(SELLER_NAME_CONTAINER);

      const SELLER_NAME = document.createElement("h3");
      SELLER_NAME.textContent = `${capitalize(seller_object.name)}`;
      SELLER_NAME_CONTAINER.appendChild(SELLER_NAME);

      const SELLER_INFOS = document.createElement("button");
      SELLER_INFOS.textContent = "About";
      SELLER_INFOS.addEventListener("click", () => seeSellerInfos(seller_object["description"]));
      SELLER_NAME_CONTAINER.appendChild(SELLER_INFOS);

      const SOLD_ITEM = document.createElement("div");
      SOLD_ITEM.classList.add("sold-item");
      
      const sold_item_name = sold_item_object.name;
      
      const SOLD_ITEM_NAME_CONTAINER = document.createElement("div");
      SOLD_ITEM_NAME_CONTAINER.classList.add("sold-item-name-container");
      SOLD_ITEM.appendChild(SOLD_ITEM_NAME_CONTAINER);

      const SOLD_ITEM_NAME = document.createElement("h3");
      SOLD_ITEM_NAME.textContent = capitalize(sold_item_name);
      SOLD_ITEM_NAME_CONTAINER.appendChild(SOLD_ITEM_NAME);

      const SOLD_ITEM_ACTIONS = document.createElement("div");
      SOLD_ITEM_ACTIONS.classList.add("sold-item-actions");
      SOLD_ITEM.appendChild(SOLD_ITEM_ACTIONS);

      const SOLD_ITEM_ACTION_PRICE = document.createElement("div");
      SOLD_ITEM_ACTION_PRICE.classList.add("sold-item-action-price");
      //declare a price
      const item_price = randomizeSellerPrice(seller_object.selling_objects[object]);
      //display price
      SOLD_ITEM_ACTION_PRICE.textContent = displayPrice(item_price);
      SOLD_ITEM_ACTIONS.appendChild(SOLD_ITEM_ACTION_PRICE);

      const SOLD_ITEM_ACTION_BUY = document.createElement("button");
      SOLD_ITEM_ACTION_BUY.textContent = "Buy";
      SOLD_ITEM_ACTION_BUY.addEventListener("click", () => buy(seller_object, seller_object.selling_objects[object], item_price, SOLD_ITEM_CONTAINER));
      SOLD_ITEM_ACTIONS.appendChild(SOLD_ITEM_ACTION_BUY);

      const SOLD_ITEM_ACTION_TRADE = document.createElement("button");
      SOLD_ITEM_ACTION_TRADE.textContent = "Trade";
      SOLD_ITEM_ACTION_TRADE.addEventListener("click", () => trade(seller_object, seller_object.selling_objects[object], SOLD_ITEM_CONTAINER));
      SOLD_ITEM_ACTIONS.appendChild(SOLD_ITEM_ACTION_TRADE);
      SOLD_ITEM_CONTAINER.appendChild(SOLD_ITEM);

      BUYING_PAGE.appendChild(SOLD_ITEM_CONTAINER);
    }
  }
  
}

const showBuyingPage = () => {
  PAGE_BODY.appendChild(BUYING_PAGE);
}

const sell = () => {
  const player_object = JSON.parse(localStorage.getItem("player"));
  console.log("sell");
}

const clearPage = () => {
  PAGE_BODY.childNodes[0] ? PAGE_BODY.removeChild(PAGE_BODY.childNodes[0]) : null;
}

const loadPage = (page) => {
  clearPage();
  const rtime = Math.floor((Math.random() * 100) + 10);
  setTimeout(() => {
    page();
  }, rtime);
}

/* Helpers functions about trading */
//Buying

const seeSellerInfos = (description) => {
  window.alert(description);
}

const randomizeSellerPrice = (selling_object) => {
  const range = selling_object.default_price_range;
  const min_price = range[0];
  const max_price = range[1];
  const price = Math.floor((Math.random() * (max_price - min_price) + min_price));
  return price;
}

const buy = (seller_object, selling_object, price, container) => {
  // if player has enough nuts, buy object
  if (player_object.nuts >= price) {
    // Generate a copy of sellers in localstorage
    const new_sellers = JSON.parse(localStorage.getItem("sellers"));
    // find seller and its object and remove it
    for (const seller in new_sellers) {
      if (new_sellers[seller].name === seller_object.name) {
        const item_index = seller_object.selling_objects.indexOf(selling_object);
        // remove item from sellers object
        new_sellers[seller].selling_objects.splice(item_index, 1);
        break;
      }
    }
    // Replace the copy of sellers in localstorage
    localStorage.setItem("sellers", JSON.stringify(new_sellers));

    player_object.nuts -= price;
    // add object to player inventory
    player_object.objects.push(selling_object.id);
    localStorage.setItem("player", JSON.stringify(player_object));
    
    //remove node from DOM
    container.remove();

    // display seller message
    window.alert(seller_object.name + " sent you a message: \n" + selling_object.selling_message);
    updateDatas();
  }
  else
  {
    // if player doesn't have enough nuts, play refused message
    window.alert("You don't have enough nuts to buy this object.");
  }
}

const trade = () => {

}