SELECT *
FROM employees
WHERE employee_id in (105,106);


SELECT last_name,
            salary
FROM emCOMMISSION_PCTCOMMISSION_PCTCOMMISSION_PCTCOMMISSION_PCTCOMMISSION_PCTCOMMISSION_PCTployees
WHERE salary NOT BETWEEN 1500 AND 7000;

SELECT last_name,
            salary,
            commission_pct
FROM employees
ORDER BY salary DESC, commission_pct DESC;

SELECT last_name,
            job_id,
            salary
FROM employees
WHERE job_id IN ('SA_REP' , 'PU_MAN' )
            AND salary NOT IN (9500, 9000, 8000);
            

SELECT *
FROM employees
WHERE LOWER(last_name) LIKE LOWER( 's%');

SELECT *
FROM employees
WHERE LOWER(first_name) LIKE LOWER( '%e_');

SELECT substr(first_name,1,3),
            length(first_name) + length(last_name) as "Full Name"
FROM employees;

SELECT *
FROM employees
WHERE MOD(employee_id,2) <> 0;

SELECT TRUNC(176 / 6,0) AS "Filled boxes",
            MOD(176,6) AS "Remaining bottles"
FROM DUAL;

SELECT employee_id,case upper(job_id)
                            when  'AD_ASST' then 'A'
                            when 'IT_PROG' then 'B'
                            when 'SA_REP' then 'C'
                            when 'FI_MGR' then 'D'
                            else 'F'
                            end
            AS "Grade"
FROM employees;


SELECT employee_id,decode (upper(job_id),
                            'AD_ASST' , 'A',
                            'IT_PROG' , 'B',
                            'SA_REP' , 'C',
                            'FI_MGR' , 'D',
                            'F')
            AS "Grade"
FROM employees;