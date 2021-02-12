-- 8. write a SQL query to list the names of all people who starred in Toy Story.

    SELECT name FROM people JOIN stars ON people.id = stars.person_id JOIN movies ON stars.movie_id = movies.id 
    WHERE title LIKE "Toy Story"; 
    
    

-- 8. write a SQL query to list the names of all people who starred in Toy Story.

--    SELECT name FROM people JOIN stars ON people.id = stars.people_id 
--    JOIN movies ON stars.movies_id = movies.id WHERE title LIKE "Toy Story";

--    SELECT name FROM people WHERE id IN (SELECT person_id from stars WHERE movie_id IN 
--    (SELECT id FROM movies WHERE title = "Toy Story"))
