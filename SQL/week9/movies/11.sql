SELECT rating FROM ratings JOIN (
  SELECT id FROM movies JOIN stars ON movie_id = id WHERE person_id = (
    SELECT id FROM people WHERE name = "Chadwick Boseman"))
      ON movie_id = id ORDER BY rating DESC;