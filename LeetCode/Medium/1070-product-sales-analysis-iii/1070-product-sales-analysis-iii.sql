# Write your MySQL query statement below
select
    s1.product_id, 
    s2.first_year,
    s1.quantity,
    s1.price
from Sales as s1
inner join(
    select
        product_id ,  
        min(year) as first_year   
    from Sales
    group by product_id
) as s2
on s1.product_id = s2.product_id and s1.year = s2.first_year

-- select
--     sale_id,  
--     min(year) as first_year   
-- from Sales
-- group by product_id