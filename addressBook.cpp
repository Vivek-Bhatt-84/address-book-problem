#include <bits/stdc++.h>

using namespace std;

// contact class for single contact
class Contact
{

public:
    string firstName;
    string lastName;
    string address;
    string city;
    string state;
    string zip;
    string phoneNumber;
    string email;

    // constructor
    Contact(string fName, string lName, string addr, string cty, string st, string zp, string phone, string mail)
    {
        firstName = fName;
        lastName = lName;
        address = addr;
        city = cty;
        state = st;
        zip = zp;
        phoneNumber = phone;
        email = mail;
    }

    // display function
    void display()
    {
        cout << "-----------------------------------" << endl;
        cout << "Name       : " << firstName << " " << lastName << endl;
        cout << "Address    : " << address << endl;
        cout << "City       : " << city << endl;
        cout << "State      : " << state << endl;
        cout << "Zip Code   : " << zip << endl;
        cout << "Phone No.  : " << phoneNumber << endl;
        cout << "Email      : " << email << endl;
        cout << "-----------------------------------" << endl;
    }
};

class AddressBook
{
public:
    vector<Contact> contacts;

    void add(Contact &contact)
    {
        contacts.push_back(contact);
        cout << "Contact added successfully !! " << endl;
    }

    void displayAll()
    {
        if (contacts.empty())
        {
            cout << "No Contacts available..." << endl;
        }

        for (auto &c : contacts)
        {
            c.display();
        }
    }

    void editContact(string phNo)
    {
        for (auto &contact : contacts)
        {
            if (contact.phoneNumber == phNo)
            {
                cout << "Contact found. Enter new details:" << endl;
                cout << "Enter First Name: ";
                cin >> contact.firstName;
                cout << "Enter Last Name: ";
                cin >> contact.lastName;
                cin.ignore();
                cout << "Enter Address: ";
                getline(cin, contact.address);
                cout << "Enter City: ";
                getline(cin, contact.city);
                cout << "Enter State: ";
                getline(cin, contact.state);
                cout << "Enter Zip Code: ";
                cin >> contact.zip;
                cout << "Enter Phone Number: ";
                cin >> contact.phoneNumber;
                cout << "Enter Email: ";
                cin >> contact.email;

                cout << "Contact updated successfully!" << endl;
                return;
            }
        }
        cout << "Contact with phone number " << phNo << " not found!" << endl;
    }

   void deleteContact(string phNo) {
    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->phoneNumber == phNo) {
            contacts.erase(it); 
            cout << "Contact with phone number " << phNo << " deleted successfully!" << endl;
            return; 
        }
    }
    cout << "Contact with phone number " << phNo << " not found!" << endl;
}

};

int main()
{
    AddressBook addressBook;
    cout << "Welcome to Address Book" << endl;

    while (true)
    {
        cout << "\nChoose an option:" << endl;
        cout << "1. Add a new contact" << endl;
        cout << "2. Display all contacts" << endl;
        cout << "3. Edit a contact" << endl;
        cout << "4. Delete a contact" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            string fName, lName, addr, cty, st, zp, phone, mail;

            cout << "Enter First Name: ";
            cin >> fName;

            cout << "Enter Last Name: ";
            cin >> lName;
            cin.ignore();

            cout << "Enter Address: ";
            getline(cin, addr);

            cout << "Enter City: ";
            getline(cin, cty);

            cout << "Enter State: ";
            getline(cin, st);

            cout << "Enter Zip Code: ";
            cin >> zp;

            cout << "Enter Phone Number: ";
            cin >> phone;

            cout << "Enter Email: ";
            cin >> mail;

            // Create a new contact
            Contact newContact(fName, lName, addr, cty, st, zp, phone, mail);

            // Add contact to address book
            addressBook.add(newContact);
        }
        else if (choice == 2)
        {
            addressBook.displayAll();
        }
        else if (choice == 3)
        {
            cout << "Enter the phone number of the contact you want to edit: ";
            string editPhone;
            cin >> editPhone;
            addressBook.editContact(editPhone);
        }
        else if (choice == 4)
        {
            cout << "Enter the phone number of the contact you want to delete: ";
            string deletePhone;
            cin >> deletePhone;
            addressBook.deleteContact(deletePhone);
        }
        else if (choice == 5)
        {
            cout << "Exiting Address Book." << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again!" << endl;
        }
    }

    return 0;
}