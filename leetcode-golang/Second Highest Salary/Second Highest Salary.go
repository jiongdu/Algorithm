//在WHERE中使用子查询
SELECT MAX(Salary) AS SecondHighestSalary FROM Employee WHERE 
salary < (SELECT MAX(Salary) FROM Employee)

