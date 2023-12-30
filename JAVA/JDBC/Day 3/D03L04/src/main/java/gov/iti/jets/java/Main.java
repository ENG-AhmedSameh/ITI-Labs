package gov.iti.jets.java;

import javax.sql.rowset.WebRowSet;
import javax.sql.rowset.RowSetProvider;
import java.io.FileOutputStream;
import java.sql.SQLException;

public class Main 
{
    public static void main( String[] args )
    {
        String jdbcUrl = "jdbc:mysql://localhost:3306/test_database";
		String username = "root";
		String password = "ahmedsameh1510";
        try {

            WebRowSet webRowSet = RowSetProvider.newFactory().createWebRowSet();

            try {

                String selectQuery = "SELECT * FROM Employee";
                webRowSet.setCommand(selectQuery);
                webRowSet.setUrl(jdbcUrl);
                webRowSet.setUsername(username);
                webRowSet.setPassword(password);
                webRowSet.execute();

                displayResultSet(webRowSet);

                saveToXML(webRowSet, "result.xml");

            } catch (SQLException e) {
                e.printStackTrace();
            }

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static void displayResultSet(WebRowSet webRowSet) throws SQLException {
        System.out.println("Joined Data:");
        while (webRowSet.next()) {
            System.out.println("ID: " + webRowSet.getInt("employee_ID") +
                    ", First Name: " + webRowSet.getString("f_name"));
        }
        System.out.println();
    }

    private static void saveToXML(WebRowSet webRowSet, String fileName) {
        try (FileOutputStream fops = new FileOutputStream(fileName)) {
            webRowSet.writeXml(fops);
            System.out.println("Data saved to " + fileName);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}