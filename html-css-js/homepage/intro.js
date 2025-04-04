const PLAYER_TEXT = document.getElementById("player-text");
const NAME_INPUT = document.getElementById("name");
const SUBMIT_PLAYER = document.getElementById("submit-player");

const player = {
  name: "John",
  class: "Warrior",
  gold: 0,
  default_attack: "strength",
  stats: {
    level: 0,
    strength: 0,
    mental: 0,
    health : 0,
    exp : 0
  }
}

const updateInfoPlayer = (e) => {
  console.log(e.srcElement.classList.contains("choose-class"));
  if (e.srcElement.classList.contains("choose-class"))
  {
    player.class = e.srcElement.value;
  }
  else
  {
    player.name = NAME_INPUT.value;
  }
  PLAYER_TEXT.textContent = `Your name is: ${player.name ? player.name : "John"} and you are a ${player.class}`;
}

const submitPlayer = (e) => {
  e.preventDefault();
  generateHero();
  startGame();
}

const generateHero = () => {
  /* Generate Hero */
  
  const selectedClass = document.querySelector('input[name="choose-class"]:checked');
  if (selectedClass) {
    player.class = selectedClass.value;
  }
  player.name = player.name ? player.name : "John";
  
  if (player.class == "Warrior") {
    player.stats.strength = 10;
    player.stats.mental = 4;
    player.stats.health = 360;
    player.default_attack = "strength";
  } else if (player.class == "Mage") {
    player.stats.strength = 3;
    player.stats.mental = 12;
    player.stats.health = 220;
    player.default_attack = "mental";
  } else if (player.class == "Alchemist") {
    player.stats.strength = 7;
    player.stats.mental = 7;
    player.stats.health = 280;
    player.default_attack = "all";
  }
  player.gold = 200;
  player.stats.level = 1;
  console.log(player);
  //write player in data.json
  let json_data = JSON.stringify(player);
  localStorage.setItem("player", json_data);
}

function startGame() {
  /* Start Game */
  const game_datas = {
    state: "1",
    day: "1",
  }
  localStorage.setItem("game_datas", JSON.stringify(game_datas));
  window.location.href = "village.html";
}