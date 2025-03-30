SELECT * FROM movies JOIN ratings ON movie_id = movies.id WHERE movies.id IN (
  SELECT movie_id FROM stars JOIN people ON person_id = id WHERE name = "Chadwick Boseman"
);