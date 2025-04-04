class Hero {
  constructor(class_name, health, strength, mental, gold) {
    this.class_name = class_name;
    this.health = health;
    this.strength = strength;
    this.mental = mental;
    this.gold = gold;
    this.default_attack = null;
  }

  setAttack() {
    if (this.class_name == "warrior") {
      this.default_attack = "strength";
    } else if (this.class_name == "mage") {
      this.default_attack = "mental";
    } else if (this.class_name == "alchemist") {
      this.default_attack = "all";
    }
  }

}