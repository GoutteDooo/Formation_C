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

  let distance = prompt("Which distance do you want to explore ? (From 1 to 100 kms)");
  while (distance < 0 || distance > 100) { distance = prompt("Which distance do you want to explore ? (From 1 to 100 kms)");}

  if (rng < 10)
  {
    findObject();
    console.log("Find object : Gold or item to sell");
  }
  else 
  {
    fight(distance);
    console.log("Fight a monster of distance " + distance);
  }
}

function trade(e) {
  console.log("Trade");
}

function findMoney(e) {
  console.log("Find money");
}

function rest(e) {
  console.log("Rest");
}

import { monsters } from "./monsters.js";
function fight(distance) {
  const rng = Math.floor(Math.random() * 100);
  //find possible monsters at this distance
  //
}