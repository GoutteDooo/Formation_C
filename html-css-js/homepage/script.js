const nameElement = document.getElementById("name-input");

const enterName = (e) => {
  nameElement.textContent = e.target.value;
}