# Write your MySQL query statement below
select sd.student_id , sd.student_name , su.subject_name, count(e.student_id) as attended_exams
from  Students sd
cross join Subjects su
left join Examinations e 
on sd.student_id = e.student_id and su.subject_name = e.subject_name
group by sd.student_id, sd.student_name, su.subject_name
order by sd.student_id, sd.student_name, su.subject_name;
