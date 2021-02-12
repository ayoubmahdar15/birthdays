-- 12. write a SQL query to list the titles of all movies in which both Johnny Depp and Helena Bonham Carter starred.

    SELECT title FROM movies JOIN stars ON movies.id = stars.movie_id JOIN people ON people.id = stars.person_id 
    WHERE people.name = "Johnny Depp" AND title in (SELECT title from movies JOIN stars ON movies.id = stars.movie_id 
    JOIN people ON stars.person_id = people.id WHERE people.name = "Helena Bonham Carter"); 





-- SELECT DISTINCT title
--    FROM
--        movies,
--        stars,
--        people,
--    WHERE movies.id = stars.movie_id
--        AND stars.person_id = people.id
--       AND rating >= 9.0


--    SELECT title FROM movies JOIN stars ON movies.id = stars.movie_id JOIN people ON stars.person_id = people.id 
--    WHERE people.name = "Johnny Depp" AND title IN (SELECT title FROM movies JOIN stars ON movies.id = stars.movie_id 
--    JOIN people ON stars.person_id = people.id WHERE people.name = "Helena Bonham Carter" )

