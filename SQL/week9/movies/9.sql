SELECT name FROM people JOIN stars WHERE id = person_id AND movie_id = (
  SELECT id FROM movies WHERE year = 2004) ORDER BY birth;