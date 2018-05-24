-- ***********************
-- Name: Shweyin Than  
-- ID: 115675175
-- Date: 5/10/2018
-- Purpose: Lab 1 DBS301 SAAL
-- ***********************

-- Question 1 – Which one of these tables appeared to be the widest? or longest? 
-- The employees table is both the longest and the widest with 20 rows and 11 columns

SELECT * FROM employees;
SELECT * FROM departments;
SELECT * FROM job_history;

-- Question 2
-- b) Choosing the widest table from question 1, rerun the SELECT. Did it have an effect to improve the look of the display?
-- Setting the page size to 200 stops the display from repeating the column names for 200 lines and increases readability
-- c) Do the same for the longest table.
-- The widest table is the same as the longest table thus had the same results as b).
-- d) You should try to find a SET command that will increase the length of each line to improve readability and remove the word wrap effect. 
-- Increase length of each line: set linesize 100
-- Remove word wrap: set wrap off

-- Question 3
-- If the following SELECT statement does NOT execute successfully, how would you fix it?
-- SELECT last_name "LName", job_id "Job Title", 
--      Hire Date "Job Start"
--      FROM employees;

SELECT last_name AS "LName", job_id AS "Job_Title", hire_date AS "Job Start" 
FROM employees;

-- Question 4
-- There are THREE coding errors in this statement. Can you identify them?
-- SELECT employee_id, last name, commission_pct Emp Comm,
-- FROM employees;

SELECT employee_id, last_name, commission_pct AS "Emp Comm"
FROM employees;

-- Question 5
-- What command would show the structure of the LOCATIONS table?

DESC locations;

-- Question 6
-- Create a query to display the output shown below.
--   City# 		City 			Province with Country Code 
--   -------------------------------------------------------------------------------
--       1000 	Roma 			IN THE IT 
--       1100 	Venice 			IN THE IT

SELECT location_ID AS "City #", city, state_province || ' IN THE ' || country_id AS "Province with Country Code"
FROM locations;









