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
        selling_message: "My kid is not playing with it anymore. Thank you for buying this.",
      },
      {
        id:13,
        default_price_range: [1000,1500],
        lowest_selling_price: 950,
        selling_message: "Michael Jackson is the best singer of all time. Thank you for buying this.",
      }
    ],
    "buying_objects": [
      {
        id:4,
        default_buying_range: [6000,9000],
        highest_buying_price: 12000
        buying_message: ""
      },
      {
        id:5,
        default_buying_range: [1500,2500],
        highest_buying_price: 3200
      }
  },
  seller2: {
    "name": "Jean12345",
    "nuts": 10000,
    "description": "He is hard in business.",
    "selling_objects": [
      {
        id:9,
        default_price_range: [520,600],
        lowest_selling_price: 455,
      },
      {
        id:13,
        default_price_range: [1100,1500],
        lowest_selling_price: 1000
      }
    ]
  },
}

export default market;