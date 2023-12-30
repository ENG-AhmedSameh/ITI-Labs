package gov.iti.jets.java;

import java.sql.SQLException;

import javax.sql.rowset.JdbcRowSet;
import javax.sql.rowset.RowSetProvider;

/**
 * Hello world!
 *
 */
public class Main 
{
    public static void main( String[] args )
    {
        String jdbcUrl = "jdbc:mysql://localhost:3306/test_database";
		String username = "root";
		String password = "ahmedsameh1510";

        try {
            JdbcRowSet rowSet = RowSetProvider.newFactory().createJdbcRowSet();
            
            rowSet.setUrl(jdbcUrl);
            rowSet.setUsername(username);
            rowSet.setPassword(password);

            String sqlQuery = "SELECT * FROM Employee";
            rowSet.setCommand(sqlQuery);

            rowSet.execute();

            while (rowSet.next()) {
                String firstName = rowSet.getString("F_Name");
                String lastName = rowSet.getString("L_Name");

                System.out.println("First Name: " + firstName + ", last Name: " + lastName);
            }
            rowSet.close();

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
