SELECT * FROM movies WHERE id IN (
  SELECT movie_id FROM stars JOIN people ON person_id = id WHERE name = "Chadwick Boseman"
);