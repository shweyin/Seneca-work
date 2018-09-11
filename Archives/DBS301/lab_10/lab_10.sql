--Shweyin Than DBS301 LAB 10 File

--Q1
CREATE VIEW DepartmentEmployeeCount_View AS
    SELECT department_name AS "Department", COUNT(employee_id) AS "# of Employees"
    FROM employees INNER JOIN departments ON employees.department_id = departments.department_id
    GROUP BY department_name
    ORDER BY department_name;


--Q2
CREATE VIEW DepartmentEmployeeCount_View AS
SELECT NVL((department_name), 'Not Yet Assigned') AS "Department", COUNT(employee_id) AS "# of Employees"
FROM employees LEFT OUTER JOIN departments ON employees.department_id = departments.department_id
GROUP BY department_name
ORDER BY department_name;

--Q3
CREATE VIEW DepartmentEmployees_View AS
SELECT NVL((department_name), 'Not Yet Assigned') AS "Department", first_name || ' ' || last_name AS "Employee"
FROM employees LEFT OUTER JOIN departments ON employees.department_id = departments.department_id
ORDER BY department_name;