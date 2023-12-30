package model;

public class Contact{
    String id;
    String firstName;
    String lastName;
    String homePhone;
    String workPhone;
    String email;

    public Contact(String id, String firstName, String lastName, String homePhone, String workPhone, String email) {
        this.id = id;
        this.firstName = firstName;
        this.lastName = lastName;
        this.homePhone = homePhone;
        this.workPhone = workPhone;
        this.email = email;
    }
    public String getId() {
        return id;
    }

    @Override
    public String toString() {
        return "id: "+this.id+", firstName: "+this.firstName+", lastName: "+this.lastName+", homephone: "+this.homePhone;
    }
}