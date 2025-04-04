const internet = document.getElementById("internet");
const returnBtn = document.getElementById("return");

document.addEventListener("DOMContentLoaded", () => {
  returnBtn.addEventListener("mouseup", () => {
    window.location.href = "village.html";
  });
  updatePage();
});



const updatePage = () => {
  connexion();
}

const connexion = () => {
  internet.textContent = "Connecting to the internet";
  let connected = false;
  let dots = 0;
  setInterval(() => {
    internet.textContent += '.';
    dots++;
    if (dots > 3) {
    internet.textContent = "Connecting to the internet";
    dots = 0;
    }
    if (connected) {
      return;
    }
  },300)

  setTimeout(() => {
    connected = true;
    removeInterval();
  }, 1000);
}