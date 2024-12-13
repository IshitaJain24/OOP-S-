#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    static int count;
    static int bookID;

public:
    Book(string t, string a) : title(t), author(a) {
        count++;
        bookID++;
    }

    static int getCount() {
        return count;
    }

    static int getBookID() {
        return bookID;
    }

    void displayInfo() {
        cout << "Book ID: " << getBookID() << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
    }
};

int Book::count = 0;
int Book::bookID = 1001;

int main() {
    Book b1("Advance Engineering Mathematics", "abc");
    Book b2("1984", "Def");
   
    cout << "Total Books Created: " << Book::getCount() << endl;
    cout << endl;

    b1.displayInfo();
    cout << endl;
    b2.displayInfo();
    cout << endl;
    

    return 0;
}
