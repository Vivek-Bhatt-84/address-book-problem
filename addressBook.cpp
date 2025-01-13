#include <bits/stdc++.h>
using namespace std;

// Contact class for a single contact
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

    // Constructor
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

    // Display function
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

// AddressBook class to manage contacts
class AddressBook
{
public:
    string name; // Unique name of the address book
    vector<Contact> contacts;

    AddressBook(string name) : name(name) {}

    void add(Contact &contact)
    {
        contacts.push_back(contact);
        cout << "Contact added successfully to Address Book: " << name << "!" << endl;
    }

    void displayAll()
    {
        if (contacts.empty())
        {
            cout << "No contacts available in Address Book: " << name << "..." << endl;
            return;
        }

        cout << "Contacts in Address Book: " << name << endl;
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
                cout << "Contact found in Address Book: " << name << ". Enter new details:" << endl;
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
        cout << "Contact with phone number " << phNo << " not found in Address Book: " << name << "!" << endl;
    }

    void deleteContact(string phNo)
    {
        for (auto it = contacts.begin(); it != contacts.end(); ++it)
        {
            if (it->phoneNumber == phNo)
            {
                contacts.erase(it);
                cout << "Contact with phone number " << phNo << " deleted successfully from Address Book: " << name << "!" << endl;
                return;
            }
        }
        cout << "Contact with phone number " << phNo << " not found in Address Book: " << name << "!" << endl;
    }
};

// System class to manage multiple address books
class System
{
public:
    unordered_map<string, AddressBook> addressBooks;

    void addAddressBook(string name)
    {
        if (addressBooks.find(name) != addressBooks.end())
        {
            cout << "Address Book with name '" << name << "' already exists!" << endl;
            return;
        }

        addressBooks[name] = AddressBook(name);
        cout << "Address Book '" << name << "' created successfully!" << endl;
    }

    AddressBook *getAddressBook(string name)
    {
        if (addressBooks.find(name) == addressBooks.end())
        {
            cout << "Address Book '" << name << "' not found!" << endl;
            return nullptr;
        }
        return &addressBooks[name];
    }

    void displayAllAddressBooks()
    {
        if (addressBooks.empty())
        {
            cout << "No Address Books available..." << endl;
            return;
        }

        cout << "Available Address Books:" << endl;
        for (auto &pair : addressBooks)
        {
            cout << "- " << pair.first << endl;
        }
    }
};

int main()
{
    System system;
    cout << "Welcome to the Address Book Management System!" << endl;

    while (true)
    {
        cout << "\nChoose an option:" << endl;
        cout << "1. Add a new Address Book" << endl;
        cout << "2. Display all Address Books" << endl;
        cout << "3. Select an Address Book" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter the name of the new Address Book: ";
            string name;
            cin >> name;
            system.addAddressBook(name);
        }
        else if (choice == 2)
        {
            system.displayAllAddressBooks();
        }
        else if (choice == 3)
        {
            cout << "Enter the name of the Address Book to select: ";
            string name;
            cin >> name;
            AddressBook *selectedBook = system.getAddressBook(name);

            if (selectedBook == nullptr)
            {
                continue;
            }

            while (true)
            {
                cout << "\nManaging Address Book: " << name << endl;
                cout << "1. Add a new contact" << endl;
                cout << "2. Display all contacts" << endl;
                cout << "3. Edit a contact" << endl;
                cout << "4. Delete a contact" << endl;
                cout << "5. Go back to main menu" << endl;

                int subChoice;
                cin >> subChoice;

                if (subChoice == 1)
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

                    Contact newContact(fName, lName, addr, cty, st, zp, phone, mail);
                    selectedBook->add(newContact);
                }
                else if (subChoice == 2)
                {
                    selectedBook->displayAll();
                }
                else if (subChoice == 3)
                {
                    cout << "Enter the phone number of the contact to edit: ";
                    string phNo;
                    cin >> phNo;
                    selectedBook->editContact(phNo);
                }
                else if (subChoice == 4)
                {
                    cout << "Enter the phone number of the contact to delete: ";
                    string phNo;
                    cin >> phNo;
                    selectedBook->deleteContact(phNo);
                }
                else if (subChoice == 5)
                {
                    break;
                }
                else
                {
                    cout << "Invalid choice. Please try again!" << endl;
                }
            }
        }
        else if (choice == 4)
        {
            cout << "Exiting Address Book Management System. Goodbye!" << endl;
            break;
        }
        else
        {
            cout << "Invalid choice. Please try again!" << endl;
        }
    }

    return 0;
}
