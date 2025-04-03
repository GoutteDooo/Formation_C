const player_object = JSON.parse(localStorage.getItem("player"));

const PLAYER_CLASS = document.getElementById("player-class");
const PLAYER_NAME = document.getElementById("player-name");
const PLAYER_GOLD = document.getElementById("player-gold");
const PLAYER_HEALTH = document.getElementById("player-health");
const PLAYER_LEVEL = document.getElementById("player-level");
const PLAYER_STRENGTH = document.getElementById("player-strength");
const PLAYER_MENTAL = document.getElementById("player-mental");

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

updatePlayer();

const updateActions = () => {
  const state = localStorage.getItem("state");
  if (state == "1") {
    ACTIONS.innerHTML = `
      <button class="btn btn-primary" onclick="submitPlayer(event)">Fight</button>
      <button class="btn btn-primary" onclick="submitPlayer(event)">Trade</button>
      <button class="btn btn-primary" onclick="submitPlayer(event)">Rest</button>
    `;
  }
}

updateActions();