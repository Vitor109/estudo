SELECT DISTINCT p.name
FROM stars s1
JOIN people p ON s1.person_id = p.id
JOIN stars s2 ON s1.movie_id = s2.movie_id
JOIN people kb ON s2.person_id = kb.id
JOIN ratings r ON s2.movie_id = r.movie_id
WHERE kb.name = 'Kevin Bacon'
AND kb.birth = 1958
AND p.name != 'Kevin Bacon';
