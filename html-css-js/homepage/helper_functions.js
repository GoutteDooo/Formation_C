export default function clamp(value, min, max) {
  return Math.min(Math.max(value, min), max);
}

export function capitalize(string) {
  return string[0].toUpperCase() + string.slice(1);
}


/**
 * @param {Number} price
 * @returns {String} price with 3 digits
 *  */
export function displayPrice(price) {
  price = String(price);
  let new_price = price.repeat(1);
  for (let i = price.length - 1; i >= 0; i--) {
    if ((price.length - i) % 3 === 0) {
      new_price = new_price.slice(0, i) + " " + new_price.slice(i);
    }
  }
  return `${new_price} 🥜`;
}