# Write your MySQL query statement below

SELECT 
e.name,
b.bonus
FROM Employee e
LEFT JOIN Bonus b
On e.empId = b.empId
Where bonus < 1000 OR b.bonus IS NULL;