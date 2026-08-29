# Write your MySQL query statement below
-- select (
--     case
--     when income < 20000 then "Low Salary"
--     when income between 20000 and 50000 then "Average Salary"
--     else "High Salary"
--     END) as category , if(count(account_id)>0,count(account_id),0) as accounts_count 
-- from Accounts
-- ; this willnot work bcz group by gives only the rows which exists after performing the action it does not give average salary wala row


select "Low Salary" as category , count(*) as accounts_count
from Accounts
where income < 20000

union all

select "Average Salary" as category , count(*) as accounts_count
from Accounts
where income between 20000 and 50000

union all

select "High Salary" as category , count(*) as accounts_count
from Accounts
where income > 50000;









