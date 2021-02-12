-- 10. write a SQL query to list the names of all people who have directed a movie that received a rating of at least 9.0.

    SELECT DISTINCT name FROM people JOIN directors ON people.id = directors.person_id JOIN movies ON directors.movie_id
    JOIN ratings ON ratings.movie_id = movies.id
    WHERE rating >= 9.0;




--    SELECT DISTINCT name
--    FROM
--        people,
--        directors,
--        ratings
--    WHERE people.id = directors.person_id
--       AND directors.ratings.movie_id = movies_id
--        AND rating >= 9.0
--
--    SELECT DISTINCT name FROM people WHERE id
--    IN (SELECT person_id FROM directors WHERE movie_id
--    IN (SELECT movie_id FROM ratings WHERE rating >= 9.0));