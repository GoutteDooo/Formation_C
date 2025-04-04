import monsters from "./monsters.js";
import clamp from "./helper_functions.js";
import levels_data from "./levels_data.js";


const PLAYER_CLASS = document.getElementById("player-class");
const PLAYER_NAME = document.getElementById("player-name");
const PLAYER_LEVEL = document.getElementById("player-level");
const PLAYER_EXP = document.getElementById("player-exp");
const PLAYER_HEALTH = document.getElementById("player-health");
const PLAYER_STRENGTH = document.getElementById("player-strength");
const PLAYER_MENTAL = document.getElementById("player-mental");
const PLAYER_GOLD = document.getElementById("player-gold");

const GAME_DAY = document.getElementById("game-day");
const PLAYER_INFOS = document.getElementById("player-infos");

const ACTIONS = document.getElementById("actions");

const updatePlayer = () => {
  const player_object = JSON.parse(localStorage.getItem("player"));

  if (player_object.stats.exp > levels_data[player_object.stats.level]["exp_needed"]) {
    player_object.stats.level += 1;
    const new_strength = levels_data[player_object.stats.level]["stats_upgrade"][player_object.class]["strength"];
    const new_mental = levels_data[player_object.stats.level]["stats_upgrade"][player_object.class]["mental"];
    const new_health = levels_data[player_object.stats.level]["stats_upgrade"][player_object.class]["max_health"];
    player_object.stats.strength += new_strength;
    player_object.stats.mental += new_mental;
    player_object.stats.max_health += new_health;
    player_object.stats.health = player_object.stats.max_health;
    const game_datas = JSON.parse(localStorage.getItem("game_datas"));
    game_datas.player_infos = `${game_datas.player_infos} <br /> You have reached level ${player_object.stats.level}! You won ${new_strength} strengths, ${new_mental} mentals and ${new_health} healths and your hp are fully restored !`;
    localStorage.setItem("player", JSON.stringify(player_object));
    localStorage.setItem("game_datas", JSON.stringify(game_datas));
  }

  PLAYER_CLASS.textContent = player_object.class;
  PLAYER_NAME.textContent = player_object.name;
  PLAYER_LEVEL.textContent = player_object.stats.level;
  PLAYER_EXP.textContent = player_object.stats.exp;
  PLAYER_HEALTH.textContent = player_object.stats.health;
  PLAYER_STRENGTH.textContent = player_object.stats.strength;
  PLAYER_MENTAL.textContent = player_object.stats.mental;
  PLAYER_GOLD.textContent = player_object.gold;

}

const updateActions = () => {
  const state = JSON.parse(localStorage.getItem("game_datas")).state;
  if (state == "1") {
    ACTIONS.innerHTML = `
      <button class="btn btn-primary" id="button-explore">Explore the world</button>
      <button class="btn btn-primary" id="button-trade">Trade on internet</button>
      <button class="btn btn-primary" id="button-money">Try to find money</button>
      <button class="btn btn-primary" id="button-rest">Rest</button>
    `;
    const exploreBtn = document.querySelector("#button-explore");
    const tradeBtn = document.querySelector("#button-trade");
    const moneyBtn = document.querySelector("#button-money");
    const restBtn = document.querySelector("#button-rest");
    exploreBtn.addEventListener("click", explore);
    tradeBtn.addEventListener("click", trade);
    moneyBtn.addEventListener("click", findMoney);
    restBtn.addEventListener("click", rest);
  }
}

const updateInfos = () => {
  const game_datas = JSON.parse(localStorage.getItem("game_datas"));
  GAME_DAY.textContent = game_datas.day;
  PLAYER_INFOS.innerHTML = game_datas.player_infos;
}

const updatePage = () => {
  updatePlayer();
  updateActions();
  updateInfos();
}

updatePage();

/* ACTIONS */
// State 1

function explore(e) {
  const rng = Math.floor(Math.random() * 100);

  let distance = prompt("Which distance do you want to explore ? (From 1 to 100 kms)");
  while (distance < 0 || distance > 100) { distance = prompt("Which distance do you want to explore ? (From 1 to 100 kms)");}
  if (distance == null) return;
  if (rng < 10)
  {
    findObject();
  }
  else 
  {
    explore_fight(distance);
  }
  timePassed(distance);
  updatePage();
}

function trade(e) {
  console.log("Trade");
}

function findMoney(e) {
  console.log("Find money");
}

function rest(e) {
  console.log("Rest");
}

/* ACTIONS END */


/* Functions for actions */


function explore_fight(distance) {
  //find possible monsters at this distance and store it in possible_monsters
  const possible_monsters = [];
  let monster_to_fight;
  let proba_sum = {
    sum: 0,
    proba_monsters: []
  };
  for (const monster in monsters) {
    if (monsters[monster].distance[0] <= distance && monsters[monster].distance[1] >= distance) {
      console.log("You have a " + monsters[monster].name + " at distance " + distance);
      possible_monsters.push(monsters[monster]);
    }
  }
  //do the sum of the probabilities of all monsters
  console.log("possible monsters: ", possible_monsters);
  for (const m_index in possible_monsters) { 
    console.log(m_index, ": ", possible_monsters[m_index]);
    proba_sum.sum += possible_monsters[m_index]["probability"];
    proba_sum.proba_monsters.push(possible_monsters[m_index]["probability"]);
  }
  console.log(proba_sum);
  //recreate new probabilities
  const rng = Math.floor(Math.random() * proba_sum.sum);
  console.log("rng: ", rng);
  
  for (let i = 0; i < proba_sum.proba_monsters.length; i++) {
    //and select the monster hitting with the rng
    if (proba_sum.proba_monsters[i] >= rng) {
      monster_to_fight = {...possible_monsters[i]};
      break;
    }
    else
    {
      proba_sum.proba_monsters[i + 1] ? proba_sum.proba_monsters[i + 1] += proba_sum.proba_monsters[i] : monster_to_fight = possible_monsters[i];
    }
  }
  console.log("monster to fight: ", monster_to_fight);
  fight(monster_to_fight);
  
}

const fight = (monster) => {
  //Get player stats
  const player_object = JSON.parse(localStorage.getItem("player"));
  // Get monster stats
  const monster_object = monster;

  //calculate default attack vs monster attack
  const p_attack = player_object.default_attack;
  const m_defense = player_object.default_attack;
  const p_defense = monster_object.default_attack;
  const m_attack = monster_object.default_attack;
  let hp_lost = 0;

  //fight loop
  let player_turn = Math.random() < 0.5 ? true : false;
  while (player_object.stats.health > 0 && monster_object.health > 0) {
    console.log("player hp: ", player_object.stats.health);
    console.log("monster hp: ", monster_object.health);
    
    if (player_turn) {
      const damage_ratio = player_object.stats[p_attack] - monster_object[m_defense];
      const brut_damage = Math.round((Math.random() * (1 - 0.8) + 0.8) * player_object.stats[p_attack]);
      if (damage_ratio > 0) {
        monster_object.health -= brut_damage;
      }
      else
      //damage ratio is bad, 33% of damages
      {
        const net_damage = Math.round(brut_damage * 0.34);
        monster_object.health -= net_damage;
      }
    }
    else
    //monster turn
    {
      const damage_ratio = monster_object[m_attack] - player_object[p_defense];
      const brut_damage = Math.round((Math.random() * (1 - 0.8) + 0.8) * monster_object[m_attack]);
      if (damage_ratio > 0) {
        player_object.stats.health -= brut_damage;
        hp_lost += brut_damage;
      }
      else
      {
        const net_damage = Math.round(brut_damage * 0.34);
        player_object.stats.health -= net_damage;
        hp_lost += net_damage;
      }
    }

    //end of a hit
    //change turn
    player_turn = !player_turn;
  }

  //end of fight
  //if player loses, set lives to 1 and nothing for him
  if (player_object.health <= 0) {
    console.log("LOSE!");
    
    player_object.health = 1;
    const game_datas = JSON.parse(localStorage.getItem("game_datas"));
    game_datas.player_infos = `You fought against a ${monster_object.name} and lost. <br /> Your body has been reconstitued thanks to the village altar, but it is weak now. You have to regain lives before exploring the world again.`;
    localStorage.setItem("game_datas", JSON.stringify(game_datas));
    //update player datas
    localStorage.setItem("player", JSON.stringify(player_object));
    updatePage();
    return;
  }
  //if player wins, gain all he can win on the monster
  if (monster_object.health <= 0) {
    //wins gold from monster
    const min_gold = monster_object.gold[0];
    const max_gold = monster_object.gold[1];
    const gold_win = Math.round((Math.random() * (max_gold - min_gold) + min_gold));
    player_object.gold += gold_win;
    console.log("wins gold: ", gold_win);

    //wins exp from monster
    const min_exp = monster_object.exp[0];
    const max_exp = monster_object.exp[1];
    const exp_win = Math.round((Math.random() * (max_exp - min_exp) + min_exp));
    player_object.stats.exp += exp_win;
    console.log("wins exp: ", exp_win);

    console.log("Victory ! Player: ", player_object);

    //update player datas
    localStorage.setItem("player", JSON.stringify(player_object));

    const game_datas = JSON.parse(localStorage.getItem("game_datas"));
    game_datas.player_infos = `You fought against a ${monster_object.name} and won! <br /> You lost ${hp_lost} hp during the battle. <br /> You have gained ${gold_win} gold and ${exp_win} exp.`;
    localStorage.setItem("game_datas", JSON.stringify(game_datas));
    updatePage();
    return;
  }
  
}

const findObject = () => {
  console.log("Find object!");
};

const timePassed = (distance) => {
  let day_number = Number(JSON.parse(localStorage.getItem("game_datas")).day);
  day_number += clamp(Math.round(distance / 20), 1, 5);
  //set new day into localstorage
  let game_datas = JSON.parse(localStorage.getItem("game_datas"));
  game_datas.day = day_number;
  localStorage.setItem("game_datas", JSON.stringify(game_datas));
}
