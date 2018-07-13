-- ***********************
-- Name: Shweyin Than
-- ID: 115675175
-- Date: 6/20/2018
-- Purpose: Lab 2 DBS301
-- ***********************

--1.	Display the employee_id, last name and salary of employees earning in the range of $8,000 to $15,000.  Sort the output by top salaries first and then by last name.

SELECT employee_id, last_name, TO_CHAR(salary, 'FM$999,999,999') AS "Salary"
FROM employees
WHERE salary BETWEEN 8000 AND 15000
ORDER BY salary desc, last_name;

--2.	Modify previous query (#1) so that additional condition is to display only if they work as Programmers or Sales Representatives. Use same sorting as before.

SELECT employee_id, last_name, TO_CHAR(salary, 'FM$999,999,999') AS "Salary"
FROM employees
WHERE (salary BETWEEN 8000 AND 15000) AND (UPPER(job_id) IN ('IT_PROG', 'SA_REP'))
ORDER BY salary desc, last_name;

--3.	The Human Resources department wants to find high salary and low salary employees. Modify previous query (#2) so that it displays the same job titles but for people who earn outside the given salary range from question 1. Use same sorting as before.

SELECT employee_id, last_name, TO_CHAR(salary, 'FM$999,999,999') AS "Salary"
FROM employees
WHERE (salary NOT BETWEEN 8000 AND 15000) AND (UPPER(job_id) IN ('IT_PROG', 'SA_REP'))
ORDER BY salary desc, last_name;

--4.	The company needs a list of long term employees, in order to give them a thank you dinner. Display the last name, job_id and salary of employees hired before 1998. List the most recently hired employees first.

SELECT last_name, job_id, TO_CHAR(salary, 'FM$999,999,999') AS "Salary"
FROM employees
WHERE hire_date < TO_DATE('01/01/1998', 'dd/mm/yyyy')
ORDER BY hire_date desc;

--5.	Modify previous query (#4) so that it displays only employees earning more than $10,000. List the output by job title alphabetically and then by highest paid employees.

SELECT last_name, job_id, TO_CHAR(salary, 'FM$999,999,999') AS "Salary"
FROM employees
WHERE (hire_date < TO_DATE('01/01/1998', 'dd/mm/yyyy')) AND
      (salary > 10000)
ORDER BY job_id, salary desc;

--6.	Display the job titles and full names of employees whose first name contains an ‘e’ or ‘E’ anywhere.

SELECT job_id, first_name || ' ' || last_name "Name"
FROM employees
WHERE UPPER(first_name) LIKE '%E%';
