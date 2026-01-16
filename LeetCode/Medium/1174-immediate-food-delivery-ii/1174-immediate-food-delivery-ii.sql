# Write your MySQL query statement below
select 
    round(
        avg(
            case 
                when d1.order_date = d1.customer_pref_delivery_date then 100
                else 0
            end
        ),
        2
    ) as immediate_percentage
from Delivery as d1
inner join (
    select customer_id,
        min(order_date) as first_order_date
    from Delivery
    group by customer_id
) as d2
on d1.customer_id = d2.customer_id
and d1.order_date = d2.first_order_date

