# Write your MySQL query statement below
WITH cte as 
(
    select d.name as Department, 
    e.name as Employee,
    e.salary as salary, 
    max(e.salary) over (
            partition by e.departmentId 
        ) as max_salary

    from Employee e
    JOIN Department d
        on e.departmentId = d.id
)

Select Department, Employee, Salary
from cte 
where salary = max_salary;