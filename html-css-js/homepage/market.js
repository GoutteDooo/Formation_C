const market = {
  seller1: {
    "name": "Mr. Smith",
    "nuts": 10000,
    "description": "He is hard in business.",
    "selling_objects": [
      {
        id:9,
        default_price_range: [500,600],
        lowest_selling_price: 400,
        selling_message: "My kid is not playing with it anymore. I hope your child will.",
        refused_message: "Are you mad with this price ?"
      },
      {
        id:13,
        default_price_range: [1000,1500],
        lowest_selling_price: 950,
        selling_message: "Michael Jackson is the best singer of all time. Enjoy it.",
        refused_message: "It's an insult !! I refuse your price. HMMMMMMM 😡😡😡"
      }
    ],
    "buying_objects": [
      {
        id:4,
        default_buying_range: [6000,9000],
        highest_buying_price: 12000,
        buying_message: "I hope this watch is like the picture. Otherwise, I'll pursuit you."
      },
      {
        id:5,
        default_buying_range: [1500,2500],
        highest_buying_price: 3200,
        buying_message: "My kid will appreciate this one."
      }
    ]
  },
  seller2: {
    "name": "Jean65492",
    "nuts": 2000000,
    "description": "He is smooth and easy in business.",
    "selling_objects": [
      {
        id:3,
        default_price_range: [45000,50000],
        lowest_selling_price: 30000,
        selling_message: "Oh !!! A buyer !!! I'm so happy to sell one object !! ❤️",
        refused_message: "Oh it's kind of you, but I can't sell it at a too low price. Can you propose a better price ?"
      },
      {
        id:6,
        default_price_range: [2000,2500],
        lowest_selling_price: 1200,
        selling_message: "THANK YOU !!!! I hope you enjoy this club !! If not, don't hesitate to sell it back to me, I'll buy it from you again ❤️❤️❤️",
        refused_message: "I'm sorry, but I can't sell it at this price. Can you propose a better price ?"
      }
    ],
    "buying_objects": [
      {
        id:1,
        default_buying_range: [300000,400000],
        highest_buying_price: 450000,
        buying_message: "Thank you..."
      },
      {
        id:2,
        default_buying_range: [100000,150000],
        highest_buying_price: 170000,
        buying_message: "YEEEEEEEEEAAAAAAAAAAAAAAAAAAHHHHHHHHHHHHHHH"
      },
    ]
  },
}

export default market;