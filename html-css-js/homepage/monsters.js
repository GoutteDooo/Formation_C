const monsters = {
  monster1: {
    "name": "Slime",
    "health": 60,
    "strength": 3,
    "mental": 2,
    "default_attack": "strength",
    "gold": [30,90],
    "exp": [10,20],
    "distance": [0,50],
    "probability": 90
  },
  monster2: {
    "name": "Nasty martian",
    "health": 200,
    "strength": 5,
    "mental": 2,
    "default_attack": "strength",
    "gold": [100,220],
    "exp": [50,100],
    "distance": [8,70],
    "probability": 40
  },
  monster3: {
    "name": "Enraged werewolf",
    "health": 600,
    "strength": 10,
    "mental": 5,
    "default_attack": "strength",
    "gold": [300,500],
    "exp": [150,220],
    "distance": [20,100],
    "probability": 20
  },
  monster4: {
    "name": "Big button nose Sorcerer",
    "health": 1500,
    "strength": 3,
    "mental": 15,
    "default_attack": "mental",
    "gold": [700,1200],
    "exp": [300,500],
    "distance": [60,100],
    "probability": 10
  }
}

export default monsters;