const levels_data = {
  "1": {
    "exp_needed":200,
    "stats_upgrade": {
      "Warrior": {
        "strength": 2,
        "mental": 0,
        "max_health": 30,
      },
      "Mage": {
        "strength": 0,
        "mental": 2,
        "max_health": 15,
      },
      "Alchemist": {
        "strength": 1,
        "mental": 1,
        "max_health": 20,
      },
    }
  },
  "2": {
    "exp_needed":500,
    "stats_upgrade": {
      "Warrior": {
        "strength": 2,
        "mental": 0,
        "max_health": 50,
      },
      "Mage": {
        "strength": 0,
        "mental": 3,
        "max_health": 35,
      },
      "Alchemist": {
        "strength": 1,
        "mental": 1,
        "max_health": 40,
      },
    }
  },
  "3": {
    "exp_needed":1000,
    "stats_upgrade": {
      "Warrior": {
        "strength": 3,
        "mental": 0,
        "max_health": 100,
      },
      "Mage": {
        "strength": 0,
        "mental": 4,
        "max_health": 55,
      },
      "Alchemist": {
        "strength": 1,
        "mental": 1,
        "max_health": 70,
      },
    }
  },
  "4": {
    "exp_needed":1700,
    "stats_upgrade": {
      "Warrior": {
        "strength": 3,
        "mental": 1,
        "max_health": 170,
      },
      "Mage": {
        "strength": 1,
        "mental": 4,
        "max_health": 80,
      },
      "Alchemist": {
        "strength": 2,
        "mental": 2,
        "max_health": 110,
      },
    }
  },
  "5": {
    "exp_needed":2900,
    "stats_upgrade": {
      "Warrior": {
        "strength": 3,
        "mental": 1,
        "max_health": 200,
      },
      "Mage": {
        "strength": 1,
        "mental": 4,
        "max_health": 110,
      },
      "Alchemist": {
        "strength": 3,
        "mental": 2,
        "max_health": 150,
      },
    }
  },
  "6": {
    "exp_needed":4800,
    "stats_upgrade": {
      "Warrior": {
        "strength": 4,
        "mental": 1,
        "max_health": 250,
      },
      "Mage": {
        "strength": 1,
        "mental": 4,
        "max_health": 170,
      },
      "Alchemist": {
        "strength": 3,
        "mental": 3,
        "max_health": 210,
      },
    }
  },
  "7": {
    "exp_needed":7777,
    "stats_upgrade": {
      "Warrior": {
        "strength": 5,
        "mental": 2,
        "max_health": 350,
      },
      "Mage": {
        "strength": 2,
        "mental": 6,
        "max_health": 220,
      },
      "Alchemist": {
        "strength": 4,
        "mental": 4,
        "max_health": 290,
      },
    }
  },
  "8": {
    "exp_needed":11000,
    "stats_upgrade": {
      "Warrior": {
        "strength": 6,
        "mental": 2,
        "max_health": 420,
      },
      "Mage": {
        "strength": 2,
        "mental": 7,
        "max_health": 280,
      },
      "Alchemist": {
        "strength": 4,
        "mental": 4,
        "max_health": 350,
      },
    }
  },
  "9": {
    "exp_needed":16000,
    "stats_upgrade": {
      "Warrior": {
        "strength": 7,
        "mental": 2,
        "max_health": 500,
      },
      "Mage": {
        "strength": 2,
        "mental": 7,
        "max_health": 320,
      },
      "Alchemist": {
        "strength": 4,
        "mental": 5,
        "max_health": 420,
      },
    }
  },
  "10": {
    "exp_needed":22222,
    "stats_upgrade": {
      "Warrior": {
        "strength": 8,
        "mental": 2,
        "max_health": 660,
      },
      "Mage": {
        "strength": 2,
        "mental": 8,
        "max_health": 440,
      },
      "Alchemist": {
        "strength": 5,
        "mental": 5,
        "max_health": 550,
      },
    }
  },
  "11": {
    "exp_needed":30000,
    "stats_upgrade": {
      "Warrior": {
        "strength": 9,
        "mental": 3,
        "max_health": 750,
      },
      "Mage": {
        "strength": 3,
        "mental": 10,
        "max_health": 500,
      },
      "Alchemist": {
        "strength": 6,
        "mental": 6,
        "max_health": 680,
      },
    }
  },
  "12": {
    "exp_needed":40000,
    "stats_upgrade": {
      "Warrior": {
        "strength": 11,
        "mental": 3,
        "max_health": 900,
      },
      "Mage": {
        "strength": 3,
        "mental": 12,
        "max_health": 650,
      },
      "Alchemist": {
        "strength": 8,
        "mental": 8,
        "max_health": 800,
      },
    }
  },
  "13": {
    "exp_needed":52000,
    "stats_upgrade": {
      "Warrior": {
        "strength": 12,
        "mental": 4,
        "max_health": 1050,
      },
      "Mage": {
        "strength": 3,
        "mental": 14,
        "max_health": 770,
      },
      "Alchemist": {
        "strength": 10,
        "mental": 9,
        "max_health": 920,
      },
    }
  },
  "14": {
    "exp_needed":67000,
    "stats_upgrade": {
      "Warrior": {
        "strength": 15,
        "mental": 5,
        "max_health": 1500,
      },
      "Mage": {
        "strength": 5,
        "mental": 14,
        "max_health": 990,
      },
      "Alchemist": {
        "strength": 11,
        "mental": 12,
        "max_health": 1250,
      },
    }
  },
  "15": {
    "exp_needed":85000,
    "stats_upgrade": {
      "Warrior": {
        "strength": 19,
        "mental": 6,
        "max_health": 1800,
      },
      "Mage": {
        "strength": 8,
        "mental": 18,
        "max_health": 1300,
      },
      "Alchemist": {
        "strength": 12,
        "mental": 13,
        "max_health": 1550,
      },
    }
  },
  "16": {
    "exp_needed":105000,
    "stats_upgrade": {
      "Warrior": {
        "strength": 21,
        "mental": 7,
        "max_health": 2300,
      },
      "Mage": {
        "strength": 8,
        "mental": 20,
        "max_health": 1600,
      },
      "Alchemist": {
        "strength": 14,
        "mental": 13,
        "max_health": 2000,
      },
    }
  },
  "17": {
    "exp_needed":105000000,
    "stats_upgrade": {
      "Warrior": {
        "strength": 21,
        "mental": 7,
        "max_health": 2300,
      },
      "Mage": {
        "strength": 8,
        "mental": 20,
        "max_health": 1600,
      },
      "Alchemist": {
        "strength": 14,
        "mental": 14,
        "max_health": 2000,
      },
    }
  },
}


export default levels_data;