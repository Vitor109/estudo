SELECT m1.title
FROM stars s1
JOIN movies m1 ON s1.movie_id = m1.id
JOIN people p1 ON s1.person_id = p1.id
JOIN stars s2 ON m1.id = s2.movie_id
JOIN people p2 ON s2.person_id = p2.id
WHERE p1.name = 'Johnny Depp'
AND p2.name = 'Helena Bonham Carter'
AND p1.id != p2.id;
