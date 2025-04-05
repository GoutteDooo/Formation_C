export default function clamp(value, min, max) {
  return Math.min(Math.max(value, min), max);
}

export function capitalize(string) {
  return string[0].toUpperCase() + string.slice(1);
}