#include<bits/stdc++.h>

using namespace std;


// contact class for single contact
class Contact{

public :
    string firstName ;
    string lastName ;
    string address ;
    string city ;
    string state ;
    string zip ;
    string phoneNumber ;
    string email ;

     // constructor 
    Contact (string fName, string lName, string addr, string cty, string st, string zp, string phone, string mail ){
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
    void display(){
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

int main()
{
    cout << "Welcome to Address-Book-Problem" << endl ;

    string fName, lName, addr, cty, st, zp, phone, mail;

    cout << "Enter First Name" << endl ;
    cin >> fName ;

    cout << "Enter Last Name" << endl ;
    cin >> lName;

    cout << "Enter Address: " << endl ;
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

    // create new Contact 
    Contact newContact(fName, lName, addr, cty, st, zp, phone, mail);

    // display contact
    newContact.display();


    return 0;
}
