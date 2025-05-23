-- /* Write your PL/SQL query statement below */
SELECT email AS Email 
FROM Person
GROUP BY email 
HAVING count(email) > 1;


-- Solution
-- Solution 1: JOIN (Slow):
SELECT DISTINCT P1.Email
FROM Person P1
JOIN Person P2 ON P1.Email = P2.Email
WHERE P1.Id <> P2.Id

-- Solution 2: Sub-query:
SELECT EMAIL FROM
    (SELECT Email, COUNT(Email) AS EmailCount
     FROM Person GROUP BY Email) Q
WHERE EmailCount >= 2

-- Solution 3: HAVING:
SELECT Email FROM Person
GROUP BY Email
HAVING COUNT(Email) >= 2
