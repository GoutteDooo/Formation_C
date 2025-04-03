const NAME_ELEMENT = document.getElementById("name-input");
const SUBMIT_PLAYER = document.getElementById("submit-player");

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
  if (!NAME_ELEMENT) return;
  console.log(NAME_ELEMENT);
  
  e.preventDefault();
  /* Generate Hero */
  
  const selectedClass = document.querySelector('input[name="choose-class"]:checked');
  if (selectedClass) {
    player.class = selectedClass.value;
  }
  player.name = NAME_ELEMENT.textContent;
  console.log(player);
  
}