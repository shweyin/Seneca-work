-- ***********************
-- Name: Shweyin Than
-- ID: 115675175
-- Date: 5/24/2018
-- Purpose: Lab 3 DBS301
-- ***********************

-- Question 1 --
-- Write a query to display the tomorrow’s date in the following format: September 28th of year 2016

SELECT TO_CHAR(SYSDATE + 1, 'fmMonth ddth "of year" YYYY') AS "Tomorrow"
FROM dual;

-- Question 2 --
-- For each employee in departments 20, 50 and 60 display last name, first name, salary, and salary increased by 5% and expressed as a whole number.  
--Label the column Good Salary. Also add a column that subtracts the old salary from the new salary and multiplies by 12. Label the column "Annual Pay Increase".

SELECT first_name AS "First Name", last_name AS "Last Name", salary AS "Salary", TRUNC(salary*1.05) AS "Good Salary", (salary*1.05 - salary) * 12 AS "Annual Pay Increase"
FROM employees
WHERE department_id in(20, 50, 60);

-- Question 3 --
-- Write a query that displays the employee’s Full Name and Job Title in the following format:
-- DAVIES, CURTIS is ST_CLERK 
-- Only employees whose last name ends with S and first name starts with C or K.  
-- Give this column an appropriate label like Person and Job.  Sort the result by the employees’ last names.

SELECT last_name || ', ' || first_name || ' is ' || job_id AS "Person and Job" 
FROM employees
WHERE UPPER(last_name) LIKE '%S' AND (UPPER(first_name) LIKE 'C%' OR UPPER(first_name) LIKE 'K%')
ORDER BY last_name;

-- Question 4 --
-- For each employee hired before 1992, display the employee’s last name, hire date and calculate the number of YEARS between TODAY and the date the employee was hired.
-- Label the column Years worked. 
-- Order your results by the number of years employed.  Round the number of years employed up to the closest whole number.

SELECT last_name, hire_date, TRUNC((SYSDATE - hire_date) / 365.25) AS "Years worked"
FROM employees
WHERE hire_date < TO_DATE('1992/01/01', 'YYYY/MM/DD')
ORDER BY "Years worked";

-- Question 5 --
-- Create a query that displays the city names, country codes and state province names, but only for those cities that starts with S and has at least 8 characters in their name. 
-- If city does not have a province name assigned, then put Unknown Province.  Be cautious of case sensitivity!

SELECT city AS "City", country_id AS "Country Code", (CASE WHEN state_province IS NULL THEN 'Unknown Province' ELSE state_province END) AS "State"
FROM locations
WHERE UPPER(city) LIKE 'S%' AND LENGTH(city) >= 8;

-- OR --

SELECT city AS "City", country_id AS "Country Code", nvl(state_province, 'Unknown Province') AS "State"
FROM locations
WHERE UPPER(city) LIKE 'S%' AND LENGTH(city) >= 8;

-- Question 6 --
-- Display each employee’s last name, hire date, and salary review date, which is the first Thursday after a year of service, but only for those hired after 1997.  
-- Label the column REVIEW DAY. 
-- Format the dates to appear in the format like:
-- THURSDAY, August the Thirty-First of year 1998
-- Sort by review date

SELECT last_name AS "Last Name", hire_date AS "Hire Date",
    (CASE
    when to_char(add_months(hire_date, 12), 'fmday') = 'friday' then
        hire_date + 6
    when to_char(add_months(hire_date, 12), 'fmday') = 'saturday' then
        hire_date + 5
    when to_char(add_months(hire_date, 12), 'fmday') = 'sunday' then
        hire_date + 4
    when to_char(add_months(hire_date, 12), 'fmday') = 'monday' then
        hire_date + 3
    when to_char(add_months(hire_date, 12), 'fmday') = 'tuesday' then
        hire_date + 2
    when to_char(add_months(hire_date, 12), 'fmday') = 'wednesday' then
        hire_date + 1
    end
    ) AS "REVIEW DAY"
FROM employees
WHERE hire_date > TO_DATE('1997/01/01', 'YYYY/MM/DD')
ORDER BY "REVIEW DAY";










