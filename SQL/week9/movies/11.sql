SELECT title FROM movies JOIN stars ON movie_id = id WHERE person_id = (
  SELECT id FROM people WHERE name = "Chadwick Boseman");