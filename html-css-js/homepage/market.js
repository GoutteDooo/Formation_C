const market = {
  seller1: {
    "name": "Mr. Smith",
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
    ],
    "buying_objects": [
      {
        id:4,
        default_buying_range: []
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