select e.name 
from Employee e
cross join Employee m
on e.id = m.managerId 
group by e.id 
having count(m.managerId) >=5; 
