SELECT * FROM movies JOIN ratings ON ratings.movie_id = movies.id WHERE movies.id IN (
  SELECT movie_id FROM stars JOIN people ON stars.person_id = people.id WHERE people.name = "Chadwick Boseman"
);