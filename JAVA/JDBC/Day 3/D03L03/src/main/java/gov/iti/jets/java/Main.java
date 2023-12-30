package gov.iti.jets.java;
import javax.sql.rowset.CachedRowSet;
import javax.sql.rowset.JoinRowSet;
import javax.sql.rowset.RowSetFactory;
import javax.sql.rowset.RowSetProvider;
import java.sql.SQLException;

public class Main 
{
    public static void main( String[] args )
    {
        String jdbcUrl = "jdbc:mysql://localhost:3306/test_database";
		String username = "root";
		String password = "ahmedsameh1510";
        try {
            RowSetFactory factory = RowSetProvider.newFactory();

            JoinRowSet joinRowSet = factory.createJoinRowSet();
            CachedRowSet rowSet1 =createRowSet(jdbcUrl, username, password, "employee");

            CachedRowSet rowSet2 =createRowSet(jdbcUrl, username, password, "employee_children");
            joinRowSet.addRowSet(rowSet1,"employee_ID");
            joinRowSet.addRowSet(rowSet2,"employee_ID");

            displayResultSet(joinRowSet);

        } catch (SQLException e) {
            e.printStackTrace();
        }
    }

    private static CachedRowSet createRowSet(String url, String username, String password, String tableName) throws SQLException {
        CachedRowSet rowSet = RowSetProvider.newFactory().createCachedRowSet();
        rowSet.setUrl(url);
        rowSet.setUsername(username);
        rowSet.setPassword(password);
        rowSet.setCommand("SELECT * FROM " + tableName);
        rowSet.execute();
        return rowSet;
    }

    private static void displayResultSet(JoinRowSet joinRowSet) throws SQLException {
        System.out.println("Joined Data:");
        while (joinRowSet.next()) {
            System.out.println("ID: " + joinRowSet.getInt("employee_ID") +
                    ", First Name: " + joinRowSet.getString("f_name") +
                    ", Child Name: " + joinRowSet.getString("child_Name"));
        }
        System.out.println();
    }
}