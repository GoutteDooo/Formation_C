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
      },
      {
        id:13,
        default_price_range: [1000,1500],
        lowest_selling_price: 950,
        selling_message: "Michael Jackson is the best singer of all time. Enjoy it.",
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
    "description": "He is weird, but he is smooth and easy in business.",
    "selling_objects": [
      {
        id:3,
        default_price_range: [45000,50000],
        lowest_selling_price: 30000,
        selling_message: "Oh !!! A buyer !!! I'm so happy to sell one object !! ❤️",
      },
      {
        id:6,
        default_price_range: [2000,2500],
        lowest_selling_price: 1200
        selling_message: "THANK YOU !!!! I hope you will like this club !! Otherwise, don't hesitate, I'll rebuy this if you don't like it ❤️❤️❤️",
      }
    ]
  },
}

export default market;