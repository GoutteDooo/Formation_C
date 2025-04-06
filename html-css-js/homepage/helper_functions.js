export default function clamp(value, min, max) {
  return Math.min(Math.max(value, min), max);
}

export function capitalize(string) {
  return string[0].toUpperCase() + string.slice(1);
}

export function displayPrice(price) {
  price = String(price);
  for (let i = price.length - 1; i >= 0; i--) {
    if ((price.length - i) % 3 === 0) {
      price = price.slice(0, i) + " " + price.slice(i);
    }
  }
  return `${price} 🥜`;
}