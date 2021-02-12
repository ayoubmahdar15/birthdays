-- 9. write a SQL query to list the names of all people who starred in a movie released in 2004, ordered by birth year.

    SELECT DISTINCT name FROM people JOIN stars ON people.id = stars.person_id 
    JOIN movies ON stars.movie_id = movies.id WHERE year = 2004 ORDER BY birth;







--    SELECT DISTINCT name
--    FROM
--        people,
--        stars,
--        movies
--    WHERE people.id = stars.person_id
--        AND stars.movies_id = movies_id
--        AND year = 2004
--    ORDER BY birth


--    SELECT DISTINCT name FROM people WHERE id IN (SELECT person_id FROM stars WHERE movie_id IN (SELECT id FROM movies WHERE year = 2004))
--    ORDER BY birth;
