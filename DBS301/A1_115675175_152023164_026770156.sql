-- ***********************
-- Name: Shweyin Than, Yvonne Deng, Eduardo Matus
-- ID: 115675175,152023164,026770156
-- Date: 6/17/2018
-- Purpose: Assignment 1 - DBS301
-- ***********************

-- Question 1 --
--Display the employee number, full employee name(Lastname, Firstname) within 25char, job and hire date
--hired in the end of month of May or November
--not hired in 1994 and 1995  
--sort with the most recently hired date

-- Q1 SOLUTION --
SELECT employee_id as "Employee Number",
    	SUBSTR(last_name||', '||first_name, 1, 25) as "Full Name",
    	job_id as "Job",
    	TO_CHAR(LAST_DAY(hire_date), 'fmMONTH ddth "of" YYYY') as "Start Date"
FROM employees
WHERE EXTRACT(MONTH FROM hire_date) in (5, 11)
AND EXTRACT(YEAR FROM hire_date) not in (1994, 1995)
ORDER BY hire_date DESC;

-- Question 2 --
--List the employee number, full name, job and the modified salary
--original salary is outside the range of $6,000 and $11,000
--work as VP or Managers(MAN, MGR)
--VP’s salary mutiple 30% and managers' salary mutiple 20%
--Sort by highest original salary

-- Q2 SOLUTION --
SELECT 'EMP# '||employee_id||' named '||first_name||' '||last_name||
    	' who is '||job_id||' will have a new salary of $'||
    	DECODE(UPPER(job_id), '%VP%', 1.3*salary,
           	1.2*salary)
    	as "Employees with increased Pay"
FROM employees
WHERE salary not between 6000 and 11000
AND (job_id like '%VP'
OR job_id like '%MAN'
OR job_id like '%MGR')
ORDER BY salary DESC;

-- Question 3 --
--Display last name, salary, job title and manager#(NONE), total income
--commission percenet equls 0
--or comes from SALES department,
--monthly modified salary required greater than $15,000
--Sort by highest salary

-- Q3 SOLUTION --
SELECT last_name,
    	salary,
    	job_id as "Job Title",
    	NVL(TO_CHAR(manager_id), 'NONE') as "Manager#",
    	TO_CHAR((salary + 1000) * 12, '$999,999.99') as "Total Income"
FROM employees
WHERE (commission_pct is null
OR department_id in (SELECT department_id
                 	FROM departments
                 	WHERE UPPER(department_name) = 'SALES'))
AND (salary + 1000 + (salary * NVL(commission_pct, 0)) > 15000)
ORDER BY salary DESC; 



-- Question 4 - Display Department_id, Job_id and the Lowest salary for this combination under the alias Lowest Dept/Job Pay, but only if that Lowest Pay falls in the range $6000 - $18000.

-- Q4 SOLUTION -

SELECT department_id AS "Department",
       job_id AS "Job Title",
       MIN(salary) AS "Job Pay"
FROM employees 
WHERE salary BETWEEN 6000 AND 18000
AND department_id NOT IN (60, 80) 
AND job_id NOT LIKE '%REP'
GROUP BY department_id, job_id
ORDER BY department_id, job_id;


-- Question 5 - Display last_name, salary and job for all employees who earn more than all lowest paid employees per department outside the US locations. -

-- Q5 SOLUTION - 

SELECT last_name AS "Last Name",
       salary AS "Salary",
       job_id AS "Job Title"
FROM employees
WHERE salary > ALL (SELECT MIN(salary)
                    FROM employees JOIN departments USING(department_id)
                    JOIN locations USING(location_id)
                    WHERE UPPER(country_id) <> 'US'
                    GROUP BY department_id
                   )
AND job_id NOT IN ('AD_PRES', 'AD_VP')
ORDER BY job_id ASC;


-- Question 6 - Who are the employees (show last_name, salary and job) who work either in IT or MARKETING department and earn more than the worst paid person in the ACCOUNTING department. -

-- Q6 SOLUTION -

SELECT last_name AS "Last Name",
       salary AS "Salary",
       job_id AS "Job Title"
FROM employees
WHERE department_id IN (20,60)
AND salary > (SELECT MIN(salary)
              FROM employees 
              WHERE department_id = 110)
ORDER BY last_name;  


-- Q7
--  	Display alphabetically the full name, job, salary (formatted as a currency amount incl. thousand separator, but no decimals) and department number 
--      for each employee who earns less than the best paid unionized employee (i.e. not the president nor any manager nor any VP), and who work in either SALES or MARKETING department.  
--  	Full name should be displayed as Firstname  Lastname and should have the heading Employee. Salary should be left-padded with the = symbol till the width of 12 characters. It should have an alias Salary.
-- 	    You should display ONE row per output line by limiting the width of the 	Employee to 25 characters.


SELECT 'Employee: ' || first_name || ' ' || last_name AS "Full Name", job_id AS "Job Title",LPAD(TO_CHAR(salary, 'FM$999,999,999'), 12, '=') AS "Salary", department_id AS "Dept Number"
FROM employees
WHERE salary < (SELECT MAX(salary)
                FROM employees
                WHERE job_id NOT LIKE '%PRES%' AND job_id NOT LIKE '%MAN%' AND job_id NOT LIKE '%MGR%' AND job_id NOT LIKE '%VP%')
AND department_id IN (20, 80)
ORDER BY first_name, last_name;

-- Q8
--  Display department name, city and number of different jobs in each department. If city is null, you should print Not Assigned Yet.
-- 	This column should have alias City.
-- 	Column that shows # of different jobs in a department should have the heading # of Jobs
-- 	You should display ONE row per output line by limiting the width of the City to 25 characters.
-- 	You need to show complete situation from the EMPLOYEE point of view, meaning include also employees who work for NO department (but do NOT display empty departments) and from the CITY point of view meaning you need to display all cities without departments as well.


SELECT departments.department_id, locations.city,
    CASE WHEN departments.department_id IS NULL THEN NULL 
    ELSE (SELECT COUNT (DISTINCT job_id) 
          FROM employees 
          WHERE departments.department_id = employees.department_id) END 
    AS "# of Jobs"
FROM departments FULL OUTER JOIN locations
ON departments.location_id = locations.location_id
ORDER BY departments.department_id;



--SELECT departments.department_id, locations.city,(
--    SELECT COUNT (DISTINCT job_id)
--    FROM employees
--    WHERE departments.department_id = employees.department_id) AS "# jobs"
--FROM departments FULL OUTER JOIN locations
--ON departments.location_id = locations.location_id
--ORDER BY departments.department_id;


