select v.customer_id , count(v.customer_id) as count_no_trans 
from Visits v
left join Transactions t
on v.visit_id = t.visit_id
where v.visit_id not in (select t.visit_id from Transactions t)
group by v.customer_id;