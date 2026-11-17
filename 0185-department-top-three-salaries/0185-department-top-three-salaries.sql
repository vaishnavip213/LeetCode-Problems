# Write your MySQL query statement below

with newtable as (
    select d.name as Department, e.name as Employee, e.salary as Salary,
    dense_rank() over (
        partition by d.name
        order by e.salary desc
    ) as ranking 
    from Employee e
    left join Department d on d.id = e.departmentId
)
select Department , Employee , Salary
from newtable
where ranking <= 3


-- select d.name as Department, e.name as Employee, e.salary as Salary
-- from Employee e
-- join Department d on e.departmentId = d.id
-- where e.salary in (select distinct top 3 salary 
--                    from Employee e2
--                    where e2.departmentId = d.id
--                    order by salary desc)
-- order by Department , Salary desc;