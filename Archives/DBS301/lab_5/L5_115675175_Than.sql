-- ***********************
-- Name: Shweyin Than  
-- ID: 115675175
-- Date: 6/10/2018
-- Purpose: Lab 5 DBS301 SAAL
-- ***********************

--Part-A - Simple Joins
--1.	Display the department name, city, street address and postal code for departments sorted by city and department name.

SELECT d.department_name AS "Department", l.city AS "City", l.street_address as "Address", l.postal_code AS "Postal Code"
FROM departments d INNER JOIN locations l
ON d.location_id = l.location_id
ORDER BY l.city, d.department_name;

--2.	Display full name of employees as a single field using format of Last, First, their hire date, salary, department name and city, 
--      but only for departments with names starting with an A or S sorted by department name and employee name.

SELECT e.last_name || ' ' || e.first_name AS "Employee Name", e.hire_date AS "Hire Date", TO_CHAR(e.salary, '$999,999.99') AS "Salary", d.department_name AS "Department", l.city AS "City"
FROM (departments d INNER JOIN locations l
    ON d.location_id = l.location_id)
    INNER JOIN employees e
    ON e.department_id  = d.department_id
WHERE (UPPER(d.department_name) LIKE ('S%')) OR (UPPER(d.department_name) LIKE ('A%'))
ORDER BY d.department_name, e.last_name, e.first_name;

--3.	Display the full name of the manager of each department in states/provinces of Ontario, California and Washington along with the department name, city, postal code and province name.   
--      Sort the output by city and then by department name.

SELECT e.last_name || ' ' || e.first_name AS "Manager", d.department_name AS "Department", l.city AS "City", l.postal_code AS "Postal Code", l.state_province AS "State/Province"
FROM (departments d INNER JOIN locations l
    ON d.location_id = l.location_id)
    INNER JOIN employees e
    ON e.manager_id  = d.manager_id
WHERE l.state_province IN ('Ontario', 'California', 'Washington')
ORDER BY l.city, d.department_name;
    

--4.	Display employee's last name and employee number along with their manager’s last name and manager number. Label the columns Employee, Emp#, Manager, and Mgr# respectively.

SELECT e.last_name AS "Employee", e.employee_id AS "Emp#", e2.last_name AS "Manager", e2.manager_id AS "Mgr#"
FROM employees e INNER JOIN employees e2
    ON e2.EMPLOYEE_ID = e.manager_id
ORDER BY "Emp#";
    
    
    
-- Part-B - Non-Simple Joins --


--5.	Display the department name, city, street address, postal code and country name for all Departments. Use the JOIN and USING form of syntax.  Sort the output by department name descending.

SELECT departments.department_name AS "Department", locations.city AS "City", locations.street_address AS "Address", locations.postal_code AS "Postal Code", countries.country_name AS "Country"
FROM (departments INNER JOIN locations USING (location_id))
    INNER JOIN countries USING (country_id)
    ORDER BY "Department" desc;

--6.	Display full name of the employees, their hire date and salary together with their department name, but only for departments which names start with A or S. Full name should be in format of:
--a.	First / Last. Use the JOIN and ON form of syntax.

SELECT employees.first_name || ' / ' || employees.last_name AS "Employee", employees.hire_date AS "Hire Date", TO_CHAR(employees.salary, '$999,999.99') AS "Salary", departments.department_name AS "Department"
FROM employees INNER JOIN departments
     ON employees.department_id = departments.department_id
WHERE (UPPER(departments.department_name) LIKE ('S%')) OR (UPPER(departments.department_name) LIKE ('A%'));

--b.	Sort the output by department name and then by last name.

SELECT employees.first_name || ' / ' || employees.last_name AS "Employee", employees.hire_date AS "Hire Date", TO_CHAR(employees.salary, '$999,999.99') AS "Salary", departments.department_name AS "Department"
FROM employees INNER JOIN departments
     ON employees.department_id = departments.department_id
WHERE (UPPER(departments.department_name) LIKE ('S%')) OR (UPPER(departments.department_name) LIKE ('A%'))
ORDER BY departments.department_name, employees.last_name;

--7.	Rewrite the previous question by using Standard (Old -- prior to Oracle9i) Join method.

SELECT employees.first_name || ' / ' || employees.last_name AS "Employee", employees.hire_date AS "Hire Date", TO_CHAR(employees.salary, '$999,999.99') AS "Salary", departments.department_name AS "Department"
FROM employees, departments
WHERE (employees.department_id = departments.department_id) AND ((UPPER(departments.department_name) LIKE ('S%')) OR (UPPER(departments.department_name) LIKE ('A%')))
ORDER BY departments.department_name, employees.last_name;

--8.	Display full name of the manager of each department in provinces Ontario, California and Washington plus department name, city, postal code and province name. Full name should be in format as follows:
--a.	Last, First.  Use the JOIN and ON form of syntax.

SELECT CASE WHEN employees.last_name is null then '**No Manager**' else employees.last_name || ', ' || employees.first_name end   AS "Manager", departments.department_name AS "Department", locations.city AS "City", locations.postal_code AS "Postal Code", locations.state_province AS "Province/State"
FROM (departments LEFT OUTER JOIN employees
    ON (departments.manager_id = employees.employee_id))
    INNER JOIN locations
    ON (departments.location_id = locations.location_id)
ORDER BY "Department";

--b.	Sort the output by city and then by department name. 

SELECT CASE WHEN employees.last_name is null then '**No Manager**' else employees.last_name || ', ' || employees.first_name end   AS "Manager", departments.department_name AS "Department", locations.city AS "City", locations.postal_code AS "Postal Code", locations.state_province AS "Province/State"
FROM (departments LEFT OUTER JOIN employees
    ON (departments.manager_id = employees.employee_id))
    INNER JOIN locations
    ON (departments.location_id = locations.location_id)
ORDER BY locations.city, "Department";

--9.	Rewrite the previous question by using Standard (Old -- prior to Oracle9i) Join method.

SELECT CASE WHEN employees.last_name is null then '**No Manager**' else employees.last_name || ', ' || employees.first_name end   AS "Manager", departments.department_name AS "Department", locations.city AS "City", locations.postal_code AS "Postal Code", locations.state_province AS "Province/State"
FROM departments, employees, locations
WHERE departments.manager_id = employees.employee_id(+) AND departments.location_id = locations.location_Id
ORDER BY locations.city, "Department";

--10.	Display the department name and Highest, Lowest and Average pay per each department. Name these results High, Low and Avg.
--a.	Use- JOIN and ON form- of the syntax.

SELECT departments.department_name AS "Department", TO_CHAR(MAX(employees.salary), '$999,999.99') AS "High", TO_CHAR(MIN(employees.salary), '$999,999.99') AS "Low", TO_CHAR(AVG(employees.salary), '$999,999.99') AS "Avg"
FROM departments INNER JOIN employees
    ON departments.department_ID = employees.department_id
GROUP BY departments.department_name;

--b.	Sort the output so that department with highest average salary are shown first.

SELECT departments.department_name AS "Department", TO_CHAR(MAX(employees.salary), '$999,999.99') AS "High", TO_CHAR(MIN(employees.salary), '$999,999.99') AS "Low", TO_CHAR(AVG(employees.salary), '$999,999.99') AS "Avg"
FROM departments INNER JOIN employees
    ON departments.department_ID = employees.department_id
GROUP BY departments.department_name
ORDER BY "Avg" desc;

--11.	Display the employee last name and employee number along with their manager’s last name and manager number. Label the columns Employee, 
--  	Emp#, Manager, and Mgr#, respectively. Include also employees who do NOT have a manager and also employees who do NOT supervise anyone (or you could say managers without employees to supervise).

SELECT e.last_name AS "Employee", e.employee_id AS "Emp#", e2.last_name AS "Manager", e2.manager_id AS "Mgr#"
FROM employees e FULL OUTER JOIN employees e2
    ON e2.EMPLOYEE_ID = e.manager_id
ORDER BY "Emp#";
