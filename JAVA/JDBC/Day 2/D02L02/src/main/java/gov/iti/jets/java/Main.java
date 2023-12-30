package gov.iti.jets.java;

import java.sql.Connection;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.Scanner;

import javax.sql.DataSource;


public class Main 
{
    private static Connection con;
    private static Statement stmt;
    private static ResultSet rs;
    private static int currentRow = 1;
    static Scanner scanner = new Scanner(System.in);
    public static void main( String[] args )
    {
        DataSource ds = MyDataSourceFactory.getMySQLDataSource();
        try 
        {
            con = ds.getConnection();
            stmt = con.createStatement(ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_UPDATABLE);
            rs = stmt.executeQuery("SELECT * FROM employee_children");
            
        
            boolean flag = true;
            while (flag) {
                System.out.println("Current row: " + currentRow);
                System.out.println("Enter command (next, previous, first, last, insert, modify, exit):");
                String command = scanner.nextLine();

                switch (command) {
                    case "next":
                        next();
                        break;
                    case "previous":
                        previous();
                        break;
                    case "first":
                        first();
                        break;
                    case "last":
                        last();
                        break;
                    case "insert":
                        
                        insert();
                        break
                    case "modify":
                        modify();
                        break;
                    case "exit":
                        con.close();
                        flag = false;
                        break;
                    default:
                        System.out.println("Invalid command");
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
    private static void insert() throws SQLException {
        System.out.println("Enter Emloyee Id:");
        int employeeid = scanner.nextInt();
        System.out.println("Enter Child Name:");
        String childName = scanner.nextLine();
        scanner.nextLine();
        rs.moveToInsertRow();
        rs.updateInt("employee_ID", employeeid);
        rs.updateString("child_Name", childName);
        rs.insertRow();
        rs.moveToCurrentRow();
    }
    
    private static void next() throws SQLException {
        if (rs.next()) {
            currentRow++;
            displayCurrentRow();
        }
    }

    private static void previous() throws SQLException {
        if (rs.previous()) {
            currentRow--;
            displayCurrentRow();
        }
    }

    private static void first() throws SQLException {
        rs.first();
        currentRow = 1;
        displayCurrentRow();
    }

    private static void last() throws SQLException {
        rs.last();
        currentRow = rs.getRow();
        displayCurrentRow();
    }

    private static void modify() throws SQLException {
        System.out.println("Enter new Child name:");
        String newChildName = scanner.nextLine();
        rs.updateString("child_Name", newChildName);
        rs.updateRow();
    }

    private static void displayCurrentRow() throws SQLException {
        System.out.println("Employee ID=" + rs.getInt("employee_ID") + ", Child Name=" + rs.getString("child_Name"));
    }
}
