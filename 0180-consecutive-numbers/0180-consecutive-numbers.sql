# Write your MySQL query statement below
WITH ConsecutiveCheck AS (
    SELECT 
        num,
        LEAD(num, 1) OVER (ORDER BY id) AS next_num,
        LEAD(num, 2) OVER (ORDER BY id) AS next_next_num
    FROM 
        Logs
)
SELECT DISTINCT
    num AS ConsecutiveNums
FROM 
    ConsecutiveCheck
WHERE 
    num = next_num 
    AND num = next_next_num;
