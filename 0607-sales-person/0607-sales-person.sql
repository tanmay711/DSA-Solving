# Write your MySQL query statement below
select s.name
from SalesPerson s
    where sales_id not in
    (
        select o.sales_id
        from Orders o
        JOIN company c
        on o.com_id = c.com_id
        where c.name = "RED"
    )