--############ Question 1 #####################
SELECT (FIRST_NAME||LAST_NAME) AS "Employee Name",
       NVL(TO_CHAR(COMMISSION_PCT),'no commission')
FROM EMPLOYEES
ORDER BY COMMISSION_PCT;


--############ Question 2 #####################
SELECT TO_CHAR(NEXT_DAY(LAST_DAY(SYSDATE),'SUNDAY'),'fmdd-month-yyyy')
FROM DUAL;


--############ Question 3 #####################
SELECT TO_CHAR(last_day(add_months(sysdate, 3)),'fmdd-month-yyyy')
FROM DUAL;

--############ Question 4 #####################
SELECT (FIRST_NAME||LAST_NAME) AS "Employee Name",
       TO_CHAR(HIRE_DATE,'fmDAY, "The" ddspth "of" Month, yyyy'),
       SALARY,
       TO_CHAR(NEXT_DAY(add_months(HIRE_DATE, 6),'MONDAY'),'fmDAY, "The" ddspth "of" Month, yyyy')
FROM EMPLOYEES;

--############ Question 5 #####################
SELECT DEPARTMENT_ID,
       MAX(SALARY)-MIN(SALARY) AS"Dfference"
FROM EMPLOYEES
GROUP BY DEPARTMENT_ID
HAVING DEPARTMENT_ID IS NOT NULL ;


--############ Question 6 #####################
SELECT DEPARTMENT_NAME,
       CITY,
       (SELECT count(*) FROM EMPLOYEES WHERE EMPLOYEES.DEPARTMENT_ID=DEPARTMENTS.DEPARTMENT_ID) AS "No of Employees",
       (SELECT ROUND(AVG(NVL(SALARY,0)),2) FROM EMPLOYEES WHERE EMPLOYEES.DEPARTMENT_ID=DEPARTMENTS.DEPARTMENT_ID  ) AS "Avg Salary"
FROM DEPARTMENTS
LEFT JOIN LOCATIONS
    ON DEPARTMENTS.LOCATION_ID = LOCATIONS.LOCATION_ID;

--############ another solution #####################
SELECT DEPARTMENT_NAME,
       CITY,
       count(e.EMPLOYEE_ID) AS "No of employees",
       ROUND(AVG(NVL(SALARY,0)),2)AS "Avg Salary"
FROM DEPARTMENTS
LEFT JOIN LOCATIONS
    ON DEPARTMENTS.LOCATION_ID = LOCATIONS.LOCATION_ID
LEFT JOIN EMPLOYEES e
    ON e.DEPARTMENT_ID = DEPARTMENTS.DEPARTMENT_ID
GROUP BY DEPARTMENTS.DEPARTMENT_NAME , LOCATIONS.CITY;


--############ Question 7 #####################
SELECT *
FROM EMPLOYEES
WHERE DEPARTMENT_ID=260;

SELECT EMPLOYEE_ID,
       (FIRST_NAME||LAST_NAME) AS "Employee Name",
       SALARY
FROM EMPLOYEES
WHERE SALARY > (SELECT AVG(NVL(SALARY,0)) FROM EMPLOYEES);

--############ Question 8 #####################
SELECT (e.FIRST_NAME||e.LAST_NAME) AS "Employee",
       e.EMPLOYEE_ID AS "Emp #",
       (m.FIRST_NAME||m.LAST_NAME) AS "Manager",
       m.EMPLOYEE_ID AS "Mgr #"
FROM EMPLOYEES e
LEFT JOIN EMPLOYEES m
    ON e.MANAGER_ID = m.EMPLOYEE_ID;

--############ Question 9 #####################
SELECT *
FROM EMPLOYEES
WHERE SALARY > ALL (SELECT SALARY FROM EMPLOYEES WHERE JOB_ID='IT_PROG')
ORDER BY SALARY DESC ;


--############ Question 10 #####################
SELECT MANAGER_ID,MIN(SALARY)
FROM EMPLOYEES
WHERE MANAGER_ID IS NOT NULL
GROUP BY (MANAGER_ID)
HAVING MIN(SALARY) >= 1000
ORDER BY MIN(SALARY) desc;


--############ Question 11 #####################
SELECT DEPARTMENT_ID,MIN(SALARY)
FROM EMPLOYEES
GROUP BY DEPARTMENT_ID
HAVING MIN(SALARY) != (SELECT MIN(SALARY) FROM EMPLOYEES);

--############Question 12#####################
SELECT e.EMPLOYEE_ID,
       e.LAST_NAME,
       e.SALARY,
       e.DEPARTMENT_ID,
       d.DEPARTMENT_NAME,
       e.JOB_ID,
       j.JOB_TITLE,
       l.city,
       l.STREET_ADDRESS,
       l.COUNTRY_ID,
       c.COUNTRY_NAME,
       c.REGION_ID,
       r.REGION_NAME
FROM EMPLOYEES e
LEFT JOIN DEPARTMENTS d
    ON e.DEPARTMENT_ID= d.DEPARTMENT_ID
LEFT JOIN JOBS j
    ON e.JOB_ID = j.JOB_ID
LEFT JOIN LOCATIONS l
    ON d.LOCATION_ID = l.LOCATION_ID
LEFT JOIN COUNTRIES c
    ON l.COUNTRY_ID=c.COUNTRY_ID
LEFT JOIN REGIONS r
    ON r.REGION_ID = c.REGION_ID;
