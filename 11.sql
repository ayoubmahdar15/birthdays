-- 11. Write a SQL query to list the titles of the five highest rated movies (in order)
-- that Chadwick Boseman starred in, starting with the highest rated.

    
    SELECT movies.title FROM movies JOIN ratings ON movies.id = ratings.movie_id WHERE id IN (SELECT movie_id 
    FROM stars WHERE person_id = (SELECT id FROM people WHERE name = "Chadwick Boseman"))
    ORDER BY ratings.rating DESC LIMIT 5;  
    
    
    
    
    
    
--  SELECT DISTINCT name
--  FROM
--        movies,
--       ratings,
--        stars,
--        people

--    SELECT title FROM movies WHERE id IN (SELECT movie_id FROM ratings WHERE movie_id
--    IN (SELECT movie_id FROM stars WHERE person_id
--    IN (SELECT id FROM people WHERE name = "Chadwick Boseman")))
--    ORDER BY ratings DESC LIMIT 5;

--  SELECT title from MOVIES WHERE id IN (SELECT movie_id FROM ratings WHERE movie_id IN (SELECT movie_id FROM stars 
--  WHERE person_id IN (SELECT id FROM people WHERE name = "Chadwick Boseman")))
--  ORDER BY ratings DESC LIMIT 5; 