# Write your MySQL query statement below
select user_id, email
from USERS
where email REGEXP '^[A-Za-z0-9_]+@[A-Za-z]+[.]com$'
order by user_id;