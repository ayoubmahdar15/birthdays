-- 13. write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.

SELECT DISTINCT(name) FROM people JOIN stars ON stars.person_id = people.id JOIN movies ON movies.id = stars.movie_id
WHERE movies.id IN
    (SELECT movie_id FROM movies
    JOIN stars ON people.id = stars.person_id
    WHERE people.name = "Kevin Bacon" AND people.birth = 1958)
        AND people.name != "Kevin Bacon";



--    SELECT DISTINCT name
--     FROM
--         people
--         stars
--         movie

--     WHERE people.id = stars.person_id
--         AND stars.movies_id = movies_id
--         includes Kevin Bacon star.name >= 9.0

--     SELECT count(DISTINCT name) FROM people JOIN stars ON people.id = stars.person_id WHERE movie_id IN
--     (SELECT movie_id FROM movies
--     JOIN people ON stars.person_id = people.id WHERE people.name = "Kevin Bacon"
--     AND people.birth = 1958) AND name != "Kevin Bacon";


