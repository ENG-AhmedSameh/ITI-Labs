--################## Question 1 ######################
SELECT * FROM EMPLOYEES;
DECLARE
    CURSOR EMP_CURSOR IS
        SELECT * FROM EMPLOYEES;
     V_COMM EMPLOYEES.COMMISSION_PCT % TYPE;
BEGIN
    FOR V_EMP_RECORD IN EMP_CURSOR LOOP
        IF V_EMP_RECORD.SALARY < 7000 THEN
            V_COMM := 0.1;
        ELSIF V_EMP_RECORD.SALARY < 10000 THEN
            V_COMM := 0.15;
        ELSIF V_EMP_RECORD.SALARY < 15000 THEN
            V_COMM := 0.2;
        ELSE
            V_COMM := 0.25;
        END IF;
         
        UPDATE EMPLOYEES
        SET COMMISSION_PCT = V_COMM
        WHERE EMPLOYEE_ID = V_EMP_RECORD.EMPLOYEE_ID; 
         
     END LOOP;
END;
SELECT * FROM EMPLOYEES;

--################## Question 2 ######################

ALTER TABLE EMPLOYEES
ADD RETIRED_BOUNS NUMBER(12,2) default 0;


SELECT * FROM EMPLOYEES;
DECLARE
    CURSOR EMP_CURSOR IS
        SELECT * FROM EMPLOYEES;
     V_MONTHS NUMBER(4);
     V_YEARS NUMBER(2);
BEGIN
    FOR V_EMP_RECORD IN EMP_CURSOR LOOP
        V_MONTHS := TRUNC(MONTHS_BETWEEN(SYSDATE,V_EMP_RECORD.HIRE_DATE));
        V_YEARS := V_MONTHS /12;
        IF V_YEARS >= 18 THEN
            UPDATE EMPLOYEES
            SET RETIRED_BOUNS = V_MONTHS*0.1*V_EMP_RECORD.SALARY
            WHERE EMPLOYEE_ID = V_EMP_RECORD.EMPLOYEE_ID;
         END IF;
     END LOOP;
END;
SELECT * FROM EMPLOYEES;

--################## Question 3 ######################
DECLARE
         CURSOR EMP_CURSOR IS
            SELECT * FROM EMPLOYEES WHERE DEPARTMENT_ID IS NOT NULL;
         v_LAST_NAME varchar2(25);
         v_DEPARTMENT_ID number(4);
         v_LOCATION_ID number(4);
         v_DEPARTMENT_NAME  varchar2(30);
         v_CITY  varchar2(30);
         v_COUNTRY_ID  char(2);
         v_COUNTRY_NAME  varchar2(40);
    BEGIN
        FOR V_EMP_RECORD IN EMP_CURSOR LOOP
            SELECT LAST_NAME, DEPARTMENT_ID
            INTO v_LAST_NAME, v_DEPARTMENT_ID
            FROM EMPLOYEES e
            WHERE EMPLOYEE_ID = V_EMP_RECORD.EMPLOYEE_ID;
            
            
            SELECT DEPARTMENT_NAME, LOCATION_ID
            INTO v_DEPARTMENT_NAME, v_LOCATION_ID
            FROM DEPARTMENTS
            WHERE DEPARTMENT_ID = v_DEPARTMENT_ID;
            
            SELECT CITY, COUNTRY_ID
            INTO v_CITY, v_COUNTRY_ID
            FROM LOCATIONS
            WHERE LOCATION_ID = v_LOCATION_ID;
            
            SELECT COUNTRY_NAME
            INTO v_COUNTRY_NAME
            FROM COUNTRIES
            WHERE COUNTRY_ID = v_COUNTRY_ID;
        
            DBMS_OUTPUT.PUT_LINE('Last name = '||v_LAST_NAME||'Department name = '||v_DEPARTMENT_NAME
                                                    ||'City name = '||v_CITY||'Country name = '||v_COUNTRY_NAME);
            END LOOP;
END;    

--################## Question 4 ######################
SELECT E.EMPLOYEE_ID, E.SALARY ,D.DEPARTMENT_NAME
            FROM EMPLOYEES E
            INNER JOIN DEPARTMENTS D
                ON E.EMPLOYEE_ID = D.DEPARTMENT_ID
            WHERE D.DEPARTMENT_NAME = 'IT' ;
DECLARE 
    CURSOR EMP_CURSOR IS
            SELECT E.EMPLOYEE_ID, E.SALARY ,D.DEPARTMENT_NAME
            FROM EMPLOYEES E
            INNER JOIN DEPARTMENTS D
                ON E.EMPLOYEE_ID = D.DEPARTMENT_ID
            WHERE D.DEPARTMENT_NAME = 'IT' ;
    
BEGIN
    
    FOR V_EMP_RECORD IN EMP_CURSOR LOOP
            UPDATE EMPLOYEES E
            SET SALARY = V_EMP_RECORD.SALARY * 1.1
            WHERE E.EMPLOYEE_ID = V_EMP_RECORD.EMPLOYEE_ID;
    END LOOP;
END;
SELECT E.EMPLOYEE_ID, E.SALARY ,D.DEPARTMENT_NAME
            FROM EMPLOYEES E
            INNER JOIN DEPARTMENTS D
                ON E.EMPLOYEE_ID = D.DEPARTMENT_ID
            WHERE D.DEPARTMENT_NAME = 'IT' ;
