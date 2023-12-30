package gov.iti.jets.java;

import java.sql.*;
import java.util.Random;


public class Main 
{
    public static void main( String[] args )
    {
        String url = "jdbc:mysql://localhost:3306/test_database";
		String username = "root";
		String pass = "ahmedsameh1510";
        
        try (Connection connection = DriverManager.getConnection(url,username,pass))
        {
            insertFiveEmployees(connection);
            modifyAttributes(connection);

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void insertFiveEmployees(Connection connection){
        
        String sqlQuery = "INSERT INTO employee (F_NAME, L_NAME, Gender, AGE, Address, Phone_Number) " +
                "VALUES (?, ?, ?, ?, ?, ?)";
        String[] fNames = {"Ahmed","omar","sayed","yousef","mohamed","Alaa","Salma","Sara","Eman","Ola"};
        String[] lNames = {"Sameh","Mamdouh","Ibrahim","Ali","osman"};
        String[] mobileCompanies = {"010","011","012","015"};
        String[] address = {"Alex","Cairo","Zagazig","Aswan","Giza"};
        Random random = new Random();
        int rowsAffected = 0;
        try (PreparedStatement preparedStatement = connection.prepareStatement(sqlQuery))
        {
            for(int i =0;i<5;i++){
                int randomFNameIndex = random.nextInt(10);
                String mobileNumber = mobileCompanies[random.nextInt(4)] + String.valueOf((long) (random.nextInt(89999999) + 10000000));
                int age = random.nextInt(40)+20;
                preparedStatement.setString(1, fNames[randomFNameIndex]);
                preparedStatement.setString(2, lNames[random.nextInt(5)]);
                preparedStatement.setString(3, randomFNameIndex<5?"Male":"Female");
                preparedStatement.setInt(4, age);
                preparedStatement.setString(5, address[random.nextInt(5)]);
                preparedStatement.setString(6, mobileNumber);
                rowsAffected+=preparedStatement.executeUpdate();
            }
            
            System.out.println(rowsAffected + " row(s) inserted successfully.");
            preparedStatement.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }
        
        
    }

    private static void  modifyAttributes(Connection connection) throws SQLException{
        String updateVacationBalanceSql = "UPDATE Employee" +
                                            " SET Vacation_Balance = 45" +
                                            " WHERE Age > 45";
        String updatetTitleQuery = "UPDATE Employee" +
                                    " SET F_Name = " +
                                        "CASE " +
                                            "WHEN Gender = 'Male'" +
                                                " THEN CONCAT('Mr. ', F_Name) " +
                                            "ELSE CONCAT('Mrs. ', F_Name)" +
                                        "END" +
                                        " WHERE AGE >= 45 And (F_Name NOT LIKE 'Mr.%' AND F_Name NOT LIKE 'Mrs.%')";

        try (Statement statement = connection.createStatement()){
            connection.setAutoCommit(false);
            statement.addBatch(updateVacationBalanceSql);
            statement.addBatch(updatetTitleQuery);

            int[] updateCounts = statement.executeBatch();
            for(int i = 0; i < updateCounts.length; i++) {
                System.out.println("Statement " + i + " affected " + updateCounts[i] + " rows");
            }
            connection.commit();
        } catch (SQLException e) {
            connection.rollback();
            throw e;
        } finally {
            connection.setAutoCommit(true);
        }
    }
}
