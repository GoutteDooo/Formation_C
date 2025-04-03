const nameElement = document.getElementById("name-input");

const enterName = (e) => {
  nameElement.textContent = `Your name is: ${e.target.value}`;
}