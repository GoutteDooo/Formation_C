SELECT name FROM people WHERE id IN (
  SELECT person_id FROM directors WHERE movie_id IN (
    SELECT id FROM movies JOIN ratings ON movie_id = id WHERE rating >= 9.0));