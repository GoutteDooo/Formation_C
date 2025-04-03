const player_object = JSON.parse(localStorage.getItem("player"));

const PLAYER_CLASS = document.getElementById("player-class");
const PLAYER_NAME = document.getElementById("player-name");
const PLAYER_GOLD = document.getElementById("player-gold");
const PLAYER_HEALTH = document.getElementById("player-health");
const PLAYER_LEVEL = document.getElementById("player-level");
const PLAYER_STRENGTH = document.getElementById("player-strength");
const PLAYER_MENTAL = document.getElementById("player-mental");

const GAME_DAY = document.getElementById("game-day");

const ACTIONS = document.getElementById("actions");

const updatePlayer = () => {
  PLAYER_CLASS.textContent = player_object.class;
  PLAYER_NAME.textContent = player_object.name;
  PLAYER_GOLD.textContent = player_object.gold;
  PLAYER_HEALTH.textContent = player_object.stats.health;
  PLAYER_LEVEL.textContent = player_object.stats.level;
  PLAYER_STRENGTH.textContent = player_object.stats.strength;
  PLAYER_MENTAL.textContent = player_object.stats.mental;
}

const updateActions = () => {
  const state = JSON.parse(localStorage.getItem("game_datas")).state;
  if (state == "1") {
    ACTIONS.innerHTML = `
      <button class="btn btn-primary" onclick="explore(event)">Explore the world</button>
      <button class="btn btn-primary" onclick="trade(event)">Trade on internet</button>
      <button class="btn btn-primary" onclick="findMoney(event)">Try to find money</button>
      <button class="btn btn-primary" onclick="rest(event)">Rest</button>
    `;
  }
}

const updateDay = () => {
  const game_datas = JSON.parse(localStorage.getItem("game_datas"));
  GAME_DAY.textContent = game_datas.day;
}

const updatePage = () => {
  updatePlayer();
  updateActions();
  updateDay();
}

updatePage();

/* ACTIONS */

function explore(e) {
  const rng = Math.floor(Math.random() * 100);
  if (rng < 5) {
    console.log("Find nothing particular, just one day passed and some lives left.");
  }
  else if (rng < 15)
  {
    console.log("Find object : Gold or item to sell");
  }
  else 
  {
    console.log("Fight against a monster");
  }
  e.preventDefault();
}

function trade(e) {
  console.log("Trade");
  e.preventDefault();
}

function findMoney(e) {
  console.log("Find money");
  e.preventDefault();
}

function rest(e) {
  console.log("Rest");
  e.preventDefault();
}