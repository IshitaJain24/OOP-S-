#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    int book_id;
    string title;
    string author;
    bool is_available;

    Book(int id, string t, string a)
        : book_id(id), title(t), author(a), is_available(true) {}

    void display() const {
        cout << "ID: " << book_id << ", Title: " << title << ", Author: " << author
             << ", Available: " << (is_available ? "Yes" : "No") << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void add_book(int id, string title, string author) {
        books.push_back(Book(id, title, author));
        cout << "Book added: " << title << endl;
    }

    void remove_book(int id) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->book_id == id) {
                books.erase(it);
                cout << "Book removed." << endl;
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void borrow_book(int id) {
        for (auto& book : books) {
            if (book.book_id == id && book.is_available) {
                book.is_available = false;
                cout << "You have borrowed: " << book.title << endl;
                return;
            }
        }
        cout << "Book not available or not found." << endl;
    }

    void return_book(int id) {
        for (auto& book : books) {
            if (book.book_id == id && !book.is_available) {
                book.is_available = true;
                cout << "You have returned: " << book.title << endl;
                return;
            }
        }
        cout << "This book was not borrowed or not found." << endl;
    }

    void list_available_books() const {
        cout << "\nAvailable Books:" << endl;
        for (const auto& book : books) {
            if (book.is_available) {
                book.display();
            }
        }
    }

    void list_borrowed_books() const {
        cout << "\nBorrowed Books:" << endl;
        for (const auto& book : books) {
            if (!book.is_available) {
                book.display();
            }
        }
    }
};

int main() {
    Library library;

    library.add_book(1, "The Great Gatsby", "F. Scott Fitzgerald");
    library.add_book(2, "1984", "George Orwell");
    library.add_book(3, "To Kill a Mockingbird", "Harper Lee");

    library.list_available_books();

    library.borrow_book(2);  
    library.list_available_books();
    library.list_borrowed_books();

    library.return_book(2);  
    library.list_available_books();
    library.list_borrowed_books();

    library.remove_book(3);  
    library.list_available_books();
    library.list_borrowed_books();

    return 0;
}