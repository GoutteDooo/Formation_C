const NAME_ELEMENT = document.getElementById("name-input");
const SUBMIT_PLAYER = document.getElementById("submit-player");
const CLASS_ELEMENT = document.getElementsByName("choose-class");

const player = {
  name: "",
  class: "",
  gold: 0,
  stats: {
    level: 0,
    strength: 0,
    defense: 0,
    health : 0
  }
}

const enterName = (e) => {
  NAME_ELEMENT.textContent = `Your name is: ${e.target.value}`;
}

const submitPlayer = (e) => {
  e.preventDefault();
  console.log(CLASS_ELEMENT);
  
  player.name = NAME_ELEMENT.textContent;
  player.class = CLASS_ELEMENT.value;
  console.log(player.class);
}