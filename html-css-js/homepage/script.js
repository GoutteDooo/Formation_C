const PLAYER_TEXT = document.getElementById("player-text");
const NAME_INPUT = document.getElementById("name");
const SUBMIT_PLAYER = document.getElementById("submit-player");

const player = {
  name: "",
  class: "Warrior",
  gold: 0,
  stats: {
    level: 0,
    strength: 0,
    defense: 0,
    health : 0
  }
}

const updateInfoPlayer = (e) => {
  PLAYER_TEXT.textContent = `Your name is: ${e.target.value} and you are a ${player.class}`;
}

const submitPlayer = (e) => {
  if (NAME_INPUT.value.length < 2) return;
  console.log(NAME_INPUT.value.length);
  
  e.preventDefault();
  /* Generate Hero */
  
  const selectedClass = document.querySelector('input[name="choose-class"]:checked');
  if (selectedClass) {
    player.class = selectedClass.value;
  }
  player.name = PLAYER_TEXT.textContent;
  console.log(player);
  
}