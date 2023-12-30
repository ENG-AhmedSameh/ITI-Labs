package addressbook;

import util.ContactUtil;
import model.Contact;
import util.SortUtil;

import java.util.List;

public class Main{
    public static void main(String[] args) {
        ContactUtil contacts = new ContactUtil();
        List<Contact> contactsList= contacts.getContacts();
        contactsList = SortUtil.sortList(contactsList);

        contactsList.forEach(System.out::println);
    }
}