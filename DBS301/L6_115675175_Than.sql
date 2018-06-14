-- ***********************
-- Name: Shweyin Than  
-- ID: 115675175
-- Date: 6/14/2018
-- Purpose: Lab 6 DBS301 SAAL
-- ***********************

--1.	SET AUTOCOMMIT ON (do this each time you log on) so any updates, deletes and inserts are automatically committed before you exit from Oracle.

SET AUTOCOMMIT ON;

--2.	Create an INSERT statement to do this.  Add yourself as an employee with a NULL salary, 0.2 commission_pct, in department 90, and Manager 100.  You started TODAY-.

INSERT INTO employees VALUES
(777, 'Shweyin', 'Than', 'shweyin@gmail.com', 'None', sysdate, 'KING', NULL, 0.2, 100, 90);

--3.	Create an Update statement to: Change the salary of the employees with a last name of Matos and Whalen to be 2500.

UPDATE employees
SET salary = 2500
WHERE last_name IN ('Matos','Whalen');

--You must use subqueries for these questions (must minimize the number of tables being used in the main query)--
--4.	Display the last names of all employees who are in the same department as the employee named Abel.

SELECT last_name
FROM employees
WHERE department_id = (
    SELECT department_id
    FROM employees
    WHERE UPPER(last_name) = 'ABEL');

--5.	Display the last name of the lowest paid employee(s)

SELECT last_name
FROM employees
WHERE salary = (
    SELECT MIN(salary)
    FROM employees);

--6.	Display the city that the lowest paid employee(s) are located in.

SELECT city
FROM locations
WHERE location_id = (
    SELECT location_id
    FROM departments
    WHERE department_id = (
        SELECT department_id
        FROM employees
        WHERE salary = (
            SELECT MIN(salary)
            FROM employees)));
            
--7.	Display the last name, department_id, and salary of the lowest paid employee(s) in each department.  Sort by Department_ID. (HINT: careful with department 60)

SELECT last_name, departmen



SELECT employee_id
FROM employees
WHERE 

--8.	Display the last name of the lowest paid employee(s) in each city
--9.	Display last name and salary for all employees who earn less than the lowest salary in ANY department.  Sort the output by top salaries first and then by last name.

--10.	Display last name, job title and salary for all employees whose salary matches any of the salaries from the IT Department. Do NOT use Join method.
