-- ***********************
-- Name: Shweyin Than
-- ID: 115675175
-- Date: 5/31/2018
-- Purpose: Lab 4 DBS301
-- ***********************

-- Question 1 –-
-- Display the difference between the Average pay and Lowest pay in the company.  Name this result Real Amount.  
-- Format the output as currency with 2 decimal places.

SELECT TO_CHAR(AVG(salary) - MIN(salary), '$999,999.99') as "Real Amount"
FROM employees;

-- Question 2 --
-- Display the department number and Highest, Lowest and Average pay per each department. 
-- Name these results High, Low and Avg.  Sort the output so that the department with highest average salary is shown first.  
-- Format the output as currency where appropriate.

SELECT department_id as "Department Number", TO_CHAR(MAX(salary), '$999,999.99') as "Highest",
        TO_CHAR(MIN(salary), '$999,999.99') as "Lowest", TO_CHAR(AVG(salary), '$999,999.99') as "Average"
FROM employees
GROUP BY(department_id)
ORDER BY AVG(salary);


-- Question 3 --
-- Display how many people work the same job in the same department. Name these results Dept#, Job and How Many. 
-- Include only jobs that involve more than one person.  Sort the output so that jobs with the most people involved are shown first.

SELECT department_id as "Department Number", job_id as "Job", COUNT(employee_id) as "Employee Count"
FROM employees
GROUP BY department_id, job_id
HAVING COUNT(employee_id) > 1
ORDER BY COUNT(employee_id) desc;

-- Question 4 --
-- For each job title display the job title and total amount paid each month for this type of the job. 
-- Exclude titles AD_PRES and AD_VP and also include only jobs that require more than $12,000.  
-- Sort the output so that top paid jobs are shown first.

SELECT job_id as "Job", TO_CHAR(SUM(salary), '$999,999.99') as "Monthly Amount Paid"
FROM employees
WHERE job_id NOT IN('AD_PRES', 'AD_VP')
GROUP BY (job_id)
HAVING SUM(salary) > 12000.0
ORDER BY SUM(salary) desc;

-- Question 5 --
-- For each manager number display how many persons he / she supervises. 
-- Exclude managers with numbers 100, 101 and 102 and also include only those managers that supervise more than 2 persons.  Sort the output so that manager numbers with the most supervised persons are shown first.
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
