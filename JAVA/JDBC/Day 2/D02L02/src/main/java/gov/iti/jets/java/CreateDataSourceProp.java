package gov.iti.jets.java;

import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.Properties;

public class CreateDataSourceProp {
    public static void main(String[] args) {
        Properties prop = new Properties();
        OutputStream output = null;
        try {
        output = new FileOutputStream("db.properties");
        // set the properties value
        prop.setProperty("MYSQL_DB_URL", 
        "jdbc:mysql://localhost:3306/test_database");
        prop.setProperty("MYSQL_DB_USERNAME", "root");
        prop.setProperty("MYSQL_DB_PASSWORD", "ahmedsameh1510");
        prop.store(output, null);
        } catch (IOException io) {
        io.printStackTrace();
        } finally {
            if (output != null) {
                try {
                output.close();
                } catch (IOException e) {
                e.printStackTrace();
                }
            }
        }
    }

}
