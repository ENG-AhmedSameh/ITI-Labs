package gov.iti.jets.java;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.util.Random;

import javax.sql.rowset.CachedRowSet;
import javax.sql.rowset.RowSetProvider;


public class Main 
{
    public static void main( String[] args )
    {
        String jdbcUrl = "jdbc:mysql://localhost:3306/test_database";
		String username = "root";
		String password = "ahmedsameh1510";

        try (Connection connection = DriverManager.getConnection(jdbcUrl, username, password)) {
                CachedRowSet cachedRowSet = RowSetProvider.newFactory().createCachedRowSet();
                
                String selectQuery = "SELECT * FROM EMPLOYEE";
                cachedRowSet.setCommand(selectQuery);
                cachedRowSet.execute(connection);

                displayResultSet(cachedRowSet);

                updateRow(cachedRowSet);

                deleteRow(cachedRowSet);

            } catch (SQLException e) {
                e.printStackTrace();
            }    
            

    }

    private static void displayResultSet(CachedRowSet cachedRowSet) throws SQLException {
        cachedRowSet.first();
        while (cachedRowSet.next()) {
            String firstName = cachedRowSet.getString("F_Name");
            String lastName = cachedRowSet.getString("L_Name");
            System.out.println("First Name: " + firstName + ", last Name: " + lastName);
        }
    }

    private static void updateRow(CachedRowSet cachedRowSet) throws SQLException {

        cachedRowSet.first();
        cachedRowSet.updateString("f_Name", "Ahmed");
        cachedRowSet.updateString("l_Name","Sameh");
        cachedRowSet.updateString("Gender","Male");
        cachedRowSet.updateInt("Age", 24);
        cachedRowSet.updateString("Address","Zagazig");
        cachedRowSet.updateString("Phone_Number","01121184437");
        
        cachedRowSet.updateRow();

        System.out.println("\nFirst row updated Successfully");

    }

    private static void insertRow(CachedRowSet cachedRowSet) throws SQLException {

        String[] fNames = {"Ahmed","omar","sayed","yousef","mohamed","Alaa","Salma","Sara","Eman","Ola"};
        String[] lNames = {"Sameh","Mamdouh","Ibrahim","Ali","osman"};
        String[] mobileCompanies = {"010","011","012","015"};
        String[] address = {"Alex","Cairo","Zagazig","Aswan","Giza"};
        Random random = new Random();
        int randomFNameIndex = random.nextInt(10);
        String mobileNumber = mobileCompanies[random.nextInt(4)] + String.valueOf((long) (random.nextInt(89999999) + 10000000));
        int age = random.nextInt(40)+20;

        cachedRowSet.setReadOnly(false);
        cachedRowSet.moveToInsertRow();

        cachedRowSet.updateString("F_NAME", fNames[randomFNameIndex]);
        cachedRowSet.updateString("L_NAME", lNames[random.nextInt(5)]);
        cachedRowSet.updateString("Gender", randomFNameIndex < 5 ? "Male" : "Female");
        cachedRowSet.updateInt("AGE", age);
        cachedRowSet.updateString("Address", address[random.nextInt(5)]);
        cachedRowSet.updateString("Phone_Number", mobileNumber);

        cachedRowSet.insertRow();
        cachedRowSet.moveToCurrentRow();
        System.out.println("\nrow added successfully");
    }

    private static void deleteRow(CachedRowSet cachedRowSet) throws SQLException {

        cachedRowSet.absolute(1);

        cachedRowSet.deleteRow();
        System.out.println("\nDelete First Row Successfuly");
    }
}
