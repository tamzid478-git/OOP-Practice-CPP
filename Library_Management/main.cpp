#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class LibraryItem
{
public:
    int itemID;
    string title;
    int year;

    LibraryItem(int itemID, string title, int year)
    {
        this->itemID = itemID;
        this->title = title;
        this->year = year;
    }

    virtual void displayInfo()
    {
        cout << "Item ID : " << itemID << endl;
        cout << "Title : " << title << endl;
        cout << "Published Year : " << year << endl;
    }

    virtual int calculateFine(int daysLate) = 0; //pure virtual function 
};

class Book : public LibraryItem
{
public:
    string author;

    Book(int itemID, string title, int year, string author): LibraryItem(itemID, title, year)
    {
        this->author = author;
    }

    void displayInfo() override
    {
        cout << "\n----- Book -----" << endl;
        cout << "Item ID : " << itemID << endl;
        cout << "Title : " << title << endl;
        cout << "Published Year : " << year << endl;
        cout << "Author : " << author << endl;
    }

    int calculateFine(int daysLate) override
    {
        return daysLate * 2;
    }
};

class Magazine : public LibraryItem
{
public:
    int issueNumber;

    Magazine(int itemID, string title, int year, int issueNumber) : LibraryItem(itemID, title, year)
    {
        this->issueNumber = issueNumber;
    }

    void displayInfo() override
    {
        cout << "\n----- Magazine -----" << endl;
        cout << "Item ID : " << itemID << endl;
        cout << "Title : " << title << endl;
        cout << "Published Year : " << year << endl;
        cout << "Issue Number : " << issueNumber << endl;
    }

    int calculateFine(int daysLate) override
    {
        return daysLate;
    }
};

class Library
{
public:
    vector <LibraryItem* > v;

    // Method Overloading
    void addItem(Book b)
    {
        v.push_back(new Book(b));
    }

    void addItem(Magazine m)
    {
        v.push_back(new Magazine(m));
    }

    void displayAll()
    {
        for (auto x : v)
        {
            x->displayInfo();
            cout << endl;
        }
    }

    void searchByTitle(string searchTitle)
    {
        bool found = false;

        for (auto x : v)
        {
            if (x->title == searchTitle)
            {
                x->displayInfo();
                found = true;
            }
        }

        if (!found)
        {
            cout << "Item Not Found." << endl;
        }
    }

    void calculateTotalFine()
    {
        int totalFine = 0;

        for (auto x : v)
        {
            int days;

            cout << "Enter overdue days for \"" << x->title << "\" : ";
            cin >> days;

            int fine = x->calculateFine(days);

            cout << "Fine : " << fine << " taka" << endl;

            totalFine += fine;
        }

        cout << "\nTotal Fine : " << totalFine << " taka" << endl;
    }
};

int main()
{
    Library l1;

    int n;

    cout << "How many library v : ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int choice;

        cout << "\n1. Book\n2. Magazine\n";
        cout << "Enter Choice : ";
        cin >> choice;

        if (choice == 1)
        {
            int id, year;
            string title, author;

            cout << "Item ID : ";
            cin >> id;

            cout << "Title : ";
            cin >> title;

            cout << "Published Year : ";
            cin >> year;

            cout << "Author : ";
            cin >> author;

            Book b(id, title, year, author);

            l1.addItem(b);
        }

        else if (choice == 2)
        {
            int id, year, issue;

            string title;

            cout << "Item ID : ";
            cin >> id;

            cout << "Title : ";
            cin >> title;

            cout << "Published Year : ";
            cin >> year;

            cout << "Issue Number : ";
            cin >> issue;

            Magazine m(id, title, year, issue);

            l1.addItem(m);
        }

        else
        {
            cout << "Invalid Choice!" << endl;
            i--;
        }
    }

    cout << "\n========== All Library v ==========\n";

    l1.displayAll();

    string searchTitle;

    cout << "\nEnter Title to Search : ";
    cin >> searchTitle;

    l1.searchByTitle(searchTitle);

    cout << "\n========== Fine Calculation ==========\n";

    l1.calculateTotalFine();

    return 0;
}
