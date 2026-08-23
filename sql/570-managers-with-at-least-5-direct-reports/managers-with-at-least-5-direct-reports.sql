SELECT 
    e.name
FROM Employee e
INNER JOIN Employee ee 
    ON e.id = ee.managerId
GROUP BY e.id, e.name
HAVING COUNT(ee.id) >= 5;