WITH cte as (
    SELECT
        d.name AS Department, 
        e.name AS Employee,
        e.salary as Salary,
        MAX(e.salary) OVER
        (
            PARTITION BY e.departmentId
        ) as max_salary
    FROM Employee e
    JOIN Department d
        ON e.departmentId = d.id
)

select Department, Employee, Salary
from cte
where salary = max_salary;