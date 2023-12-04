--################## Question 1 SQL ######################
GRANT CREATE PUBLIC SYNONYM TO HR;
CREATE PUBLIC SYNONYM EMP_VU_SYNONYM FOR EMP_VU;

--################## Question 2 SQL ######################

SELECT * FROM ALL_TAB_COMMENTS;
SELECT * FROM ALL_COL_COMMENTS;
SELECT * FROM DBA_TAB_COMMENTS;
SELECT * FROM DBA_COL_COMMENTS;

--############################## PLSQL ################################
--################## Question 1 ######################

select COMMISSION_PCT from employees where employee_id = 105;

declare
        v_salary number(8, 2);
        v_comm_perc number(2,2);
begin
    select salary
    into  v_salary
    from employees
    where employee_id = 105;  
    if v_salary < 7000 then
         v_comm_perc  := 0.1;
    elsif v_salary < 10000 then
         v_comm_perc  := 0.15;
    elsif v_salary < 15000 then
         v_comm_perc  := 0.2;
    else
           v_comm_perc := 0.25;
     end if;
    UPDATE employees
    SET COMMISSION_PCT =  v_comm_perc 
    where employee_id = 105; 
    
end;

select COMMISSION_PCT from employees where employee_id = 105;


--################## Question 2 ######################
DECLARE
    v_salary number(10);
    v_no_months number(4);
    v_retired_salary number(10);
BEGIN
     SELECT salary , TRUNC(MONTHS_BETWEEN(SYSDATE, hire_date))
     INTO v_salary, v_no_months
     FROM EMPLOYEES
     WHERE EMPLOYEE_ID = 105;
     
     v_retired_salary := v_no_months * 0.1* v_salary;
     DBMS_OUTPUT.PUT_LINE('Retired Salary = '||v_retired_salary);
END;

--################## Question 3 ######################
DECLARE
         v_LAST_NAME varchar2(25);
         v_DEPARTMENT_ID number(4);
         v_LOCATION_ID number(4);
         v_DEPARTMENT_NAME  varchar2(30);
         v_CITY  varchar2(30);
         v_COUNTRY_ID  char(2);
         v_COUNTRY_NAME  varchar2(40);
    BEGIN
        SELECT LAST_NAME, DEPARTMENT_ID
        INTO v_LAST_NAME, v_DEPARTMENT_ID
        FROM EMPLOYEES e
        WHERE EMPLOYEE_ID = 105;
        
        
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
    
        DBMS_OUTPUT.PUT_LINE('Last name = '||v_LAST_NAME);
        DBMS_OUTPUT.PUT_LINE('Department name = '||v_DEPARTMENT_NAME);
        DBMS_OUTPUT.PUT_LINE('City name = '||v_CITY);
        DBMS_OUTPUT.PUT_LINE('Country name = '||v_COUNTRY_NAME);  
END;  
