# Write your MySQL query statement below
select
    e1.employee_id,
    e1.name,
    e2.reports_count,
    e2.average_age
from Employees as e1
inner join(
    select
        reports_to,
        count(*) as reports_count,
        round(avg(age), 0) as average_age        
    from Employees
    where reports_to is not null
    group by reports_to
)as e2
on e1.employee_id = e2.reports_to
order by e1.employee_id asc