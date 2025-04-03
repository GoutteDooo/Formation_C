const nameElement = document.getElementById("name-input");
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
  nameElement.textContent = `Your name is: ${e.target.value}`;
}