-- # Write your MySQL query statement below
SELECT name
FROM Customer
WHERE IFNULL(referee_id, 0) != 2;


-- # Best Solution
-- # Best Solution 1: WHERE OR
SELECT name
FROM Customer
WHERE referee_id != 2
    OR referee_id IS NULL;

-- # Best Solution 2: COALESCE
SELECT name
FROM Customer
WHERE COALESCE(referee_id, 0) <> 2;

-- # Best Solution 3: IFNULL
SELECT name
FROM Customer
WHERE IFNULL(referee_id, 0) <> 2;

-- # Best Solution 4: Subquery
SELECT name
FROM Customer
WHERE id NOT IN (
        SELECT id
        FROM Customer
        WHERE referee_id = 2
    )