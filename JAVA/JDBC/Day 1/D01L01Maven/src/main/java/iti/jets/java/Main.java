package iti.jets.java;
import java.sql.*;

public class Main {
    public static void main(String[] args) {
        //open file listener.ora at location : C:\oraclexe\app\oracle\product\11.2.0\server\network\ADMIN
        String url = "jdbc:oracle:thin:@//DESKTOP-LD3712F:1521/XE"; //@//hostname:portNumber/service name
        String userName = "HR";
        String password = "ahmedsameh1510";
        try {
            //Try connecting to oracle database
            Class.forName("oracle.jdbc.driver.OracleDriver");
            Connection connection = DriverManager.getConnection(url, userName, password);
            Statement statement = connection.createStatement();
            String sqlQuery = "Select * FROM DEPARTMENTS";
            ResultSet resultSet = statement.executeQuery(sqlQuery);
            while (resultSet.next()){
                System.out.println("Department ID: "+resultSet.getInt(1)+", Department Name: "+resultSet.getString(2));
            }
            connection.close();
        } catch (SQLException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }

    }
}