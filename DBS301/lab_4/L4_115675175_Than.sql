-- ***********************
-- Name: Shweyin Than
-- ID: 115675175
-- Date: 5/31/2018
-- Purpose: Lab 4 DBS301
-- ***********************

-- Question 1 –- 

SELECT TO_CHAR(AVG(salary) - MIN(salary), '$999,999.99') as "Real Amount"
FROM employees;

-- Question 2 --

SELECT department_id as "Department Number", TO_CHAR(MAX(salary), '$999,999.99') as "Highest",
        TO_CHAR(MIN(salary), '$999,999.99') as "Lowest", TO_CHAR(AVG(salary), '$999,999.99') as "Average"
FROM employees
GROUP BY(department_id)
ORDER BY AVG(salary);


-- Question 3 --

SELECT department_id as "Department Number", job_id as "Job", COUNT(employee_id) as "Employee Count"
FROM employees
GROUP BY department_id, job_id
HAVING COUNT(employee_id) > 1
ORDER BY COUNT(employee_id) desc;

-- Question 4 --

SELECT job_id as "Job", TO_CHAR(SUM(salary), '$999,999.99') as "Monthly Amount Paid"
FROM employees
WHERE job_id NOT IN('AD_PRES', 'AD_VP')
GROUP BY (job_id)
HAVING SUM(salary) > 12000.0
ORDER BY SUM(salary) desc;

-- Question 5 --

SELECT manager_id as "Manager ID", COUNT(employee_id) as "Supervised Employees"
FROM employees
WHERE manager_id NOT IN(100, 101, 102)
GROUP BY (manager_id)
HAVING COUNT(employee_id) > 2
ORDER BY COUNT(employee_id) desc;

-- Question 6 --

SELECT department_id as "Department ID", MAX(hire_date) as "Latest Hire Date", MIN(hire_date) as "Earliest Hire Date"
FROM employees
WHERE department_id NOT IN (10, 20)
GROUP BY department_id
HAVING MAX(hire_date) < TO_DATE('2001/01/01', 'YYYY/MM/DD')
ORDER BY MAX(hire_date) desc;
