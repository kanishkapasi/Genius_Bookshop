#include <iostream>   //input,output
#include <iomanip>    //formatting
#include<fstream>     //file handling
#include <windows.h>  //color support
#include <conio.h>  //console input/output functions
#include <thread> //std::this_thread::sleep_for function
#include <algorithm> // for std::transform
#include <chrono>
#include <ctime>
#include <algorithm>
#include <cctype>
#include <string>


using namespace std;

//define book structure
 struct Book
{   int isbn;
    string name;
    string author;
    float price;
    int quantity;
};

//books array
 const int maxSize = 12; // define the maximum number of books
    Book books[maxSize] = {
    {1000,"Harry Potter", "J.K.Rowling", 650, 20},
    {2003,"Sherlock Holmes", "Arthur Conan Doyle", 300, 25},
    {4012,"Physics-Grade 12","Dr.Rosa",400,30},
    {2032,"General Knowledge","Ariyarathna Perera",400,30},
    {7689,"Famous Five","Enid Blyton",500,12},
    {3000,"The Lost World","Chandana Mendis",400,14},
    {6543,"C++ Beginner","Dr.Roy",2000,5},
    {3258,"Dawala Wiyagaraya","Somachandra Silva",585,10}

};
    int size= 8;


     struct PendingOrder
{
    string date;
    string customer;
    string orderBook;
    string authorBook;
    int orderQuantity;
    int orderTotal;
};

const int maxPendingOrders = 10; // define the maximum number of orders
   PendingOrder pendingOrders[maxPendingOrders] = {
    {"2023/11/12","Gamunu College", "Famous Five", "Enid Blyton", 5, 2250},
    {"2023/11/13","ICBT Campus","C++ Beginner", "Dr.Roy", 2, 1800},
   };

   int penSize=2;



// Function declarations
void displayNethraBookShopASCIIArt();
void displayTopic();       //display topic
void login();        //handle user login detials
void showMenu();           //display the main menu
void clearConsole();       //clear the console screen
void manageBooks();        //manage books
void manageOrders();       //manage orders
void backManageBooks();    //back to manage books menu
void backManageOrders();   //back to manage orders menu
void tryAgain();           //prompt the user to try again
void showBooks(const Book books[], int size);
void addBook(Book books[], int& size);
void searchBook(Book books[],int& size);
void deleteBook(Book books[], int& size);
void prepareQuotation();
void setColor(int color);
void displayBookList(const Book books[], int size);
void showPendingOrders (const PendingOrder pendingOrders[], int penSize );
void addOrder(PendingOrder pendingOrders[], int& penSize);
void completePendingOrder(PendingOrder pendingOrders[], int& penSize, Book books[], int& size);
string getCurrentDate();
bool compareIgnoreCase(const std::string& str1, const std::string& str2); // Function to compare two strings ignoring case

//colors
const int GREEN = 10;
const int WHITE = 15;
const int YELLOW = 14;

//main function
int main()
{
    displayNethraBookShopASCIIArt();
    displayTopic(); //call function
    login();  //call function


    return 0;
}

//function definitions are start from here.

void displayNethraBookShopASCIIArt() {
    // Array of color codes for the animation
    const int colors[] = {14, 10, 12, 11, 13, 15};  // Yellow, Green, Red, Cyan, Purple, White

    // Loop through the colors to create an animation effect
    for (int i = 0; i < 3; ++i) {  // Change the loop count to adjust the animation speed
        for (int j = 0; j < 6; ++j) {
            setColor(colors[j]);
            std::cout << R"(







               _   _      _   _                ______             _      _____ _
              | \ | |    | | | |               | ___ \           | |    /  ___| |
              |  \| | ___| |_| |__  _ __ __ _  | |_/ / ___   ___ | | __ \ `--.| |__   ___  _ __
              | . ` |/ _ | __| '_ \| '__/ _` | | ___ \/ _ \ / _ \| |/ /  `--. | '_ \ / _ \| '_ \
              | |\  |  __| |_| | | | | | (_| | | |_/ | (_) | (_) |   <  /\__/ | | | | (_) | |_) |
              \_| \_/\___|\__|_| |_|_|  \__,_| \____/ \___/ \___/|_|\_\ \____/|_| |_|\___/| .__/
                                                                                          | |
                                                                                          |_|









    )" << std::endl;
     std::this_thread::sleep_for(std::chrono::milliseconds(100));  // Pause for a short duration
            system("cls");  // Clear the console
        }
    }

    setColor(7);  // Reset color to default
}


void displayTopic()
{
    setColor(GREEN);
    cout<<"------------------------------------------------------------------------"<<endl;
    cout<<"|              Nethra Books - Management System                        |"<<endl;
    cout<<"------------------------------------------------------------------------"<<endl;
    setColor(WHITE);

    cout<<endl;
}

//this function clear the console screen and show the main topic.
void clearConsole()
{
    system("cls");
    displayTopic(); //function call
}

void login()
{
   //Hardcoded username and password, set as constants
   const string userName="admin";
   const string password="admin456";

   string user;
   string pass;

    bool isValidLogin = false;

    // Validate user login details
    // Execute the block of code repeatedly until the user enters the correct details.
    while (!isValidLogin) {
        cout<< "Enter correct usernme and password for login"<<endl;
        cout<<endl;
        cout << "User Name: ";
        cin >> user;
        cout << "Password: ";
        cin >> pass;

        if (user == userName && pass == password) {
            isValidLogin = true;
        } else {
            cout<<endl;
            cout << "Invalid login. Please try again." << endl;
            cout<<endl;
        }
    }

    showMenu(); //if user enter the correct details, this will show the Main menu.

}

void showMenu() //display Main menu
{
    clearConsole(); //function call to display main topic
    //print Main menu
    setColor(YELLOW);
    cout<<"*** Main Menu ****"<<endl;
    setColor(WHITE);
    cout<<endl;
    cout<<"1.Manage Books"<<endl;
    cout<<"2.Manage Orders"<<endl;
    cout<<"3.Logout"<<endl;
    cout<<"4.Exit"<<endl;
    cout<<endl;
    //get user choice
     int a;
    cout<<"Enter your choice: ";
    cin>>a;
    //switch for handle user's choice
    switch(a)
    {
        //user chose to mange books
        case 1:manageBooks();break;   //function call
        //user chose to manage ordes
        case 2:manageOrders();break;  //function call
        //user chose to logout
        case 3:
        clearConsole();
        login();break;
        case 4:
        cout<<endl;
         clearConsole();
        cout<<"Good Bye!"<<endl;
        exit(0);
        //// Invalid choice, prompt user to try again
        default:cout<<endl;
            cout<<"Invalid choice"<<endl;
        tryAgain();  //function call
    }
}

void manageBooks()
{
    clearConsole();
    //print the Manage Book menu
    setColor(YELLOW);
    cout<<"**** Manage Books ****"<<endl;
    setColor(WHITE);
    cout<<endl;
    cout<<"1.View book list"<<endl;
    cout<<"2.Search book"<<endl;
    cout<<"3.Add book"<<endl;
    cout<<"4.Delete book"<<endl;
    cout<<"5.Go to main menu"<<endl;
    cout<<endl;
    //get user choice
    int b;
    cout<<"Enter your choice: ";
    cin>>b;
    cout<<endl;

    //switch for handle user's choice
    switch(b)
    {
        case 1:{
             showBooks(books, size);

            break;
         }

        case 2: {

            searchBook(books,size);

        break; //break case 2
        }

        case 3:
            {
             addBook(books, size);

            break;}

        case 4: {
             deleteBook(books, size);
        }

        case 5:
        showMenu();  //function call, go to main menu
        break;

        default:cout<<"Invalid choice";
        cout<<endl;
        // Prompt user to exit to book management menu
        backManageBooks();

    }
}

void manageOrders()
{
   system("cls");

   //define the Order structure
    clearConsole();
    //display Manage orders menu
    setColor(YELLOW);
    cout<<"**** Manage Orders ****"<<endl;
    setColor(WHITE);
    cout<<endl;
    cout<<"1.View pending orders"<<endl;
    cout<<"2.Add orders"<<endl;
    cout<<"3.Complete pending orders"<<endl;
    cout<<"4.Prepare quotation"<<endl;
    cout<<"5.Go to main menu"<<endl;
    cout<<endl;
    //get user choice as input
    int c;
    cout<<"Enter your choice: ";
    cin>>c;
    cout<<endl;

    //switch for handle user's choice
    switch(c)
    {

    case 1:
        {
           showPendingOrders (pendingOrders, penSize );
        break;
        }

    case 2:
        {
           addOrder(pendingOrders, penSize);
        break;}

    case 3:
        {
        completePendingOrder(pendingOrders, penSize, books, size);
        break;}

    case 4:{

        prepareQuotation();

    break;}

    case 5:
        showMenu(); //go to main menu
        break;

    default: //show error
    cout<<"Invalid choice";
    cout<<endl;
    backManageOrders(); //call function

   }
}

void backManageBooks()
{
    //boolean for check if the input is valid
    bool isValidChoice = false;

    // Continue looping until a valid input(5) is received
    while (!isValidChoice) {
    int x;
    cout<<endl;
    cout<<"Enter 5 to Back: ";
    cin>>x;

    if (x == 5)
        {
            isValidChoice = true;
            manageBooks();  //call function
        }
    else
       {
      cout<<endl;
      //display error msg
      cout << "Please enter a valid input" << endl;
      cout<<endl;
       }
 }
}

void backManageOrders()
{
    //boolean for check if the input is valid
     bool isValidExit = false;

    // Continue looping until a valid input(5) is receive
    while (!isValidExit) {
    int y;
    cout<<endl;
    cout<<"Enter 5 to Back: ";
    cin>>y;

    if (y == 5)
        {
            isValidExit = true;
            manageOrders();
        }
    else
       {
      cout<<endl;
      cout << "Please enter a valid input" << endl;
      cout<<endl;
       }
 }
}

void tryAgain()
{
    //boolean for check if the input is valid
    bool isValidTry = false;

    // Continue looping until a valid input(5) is received
    while (!isValidTry) {
    int z;
    cout<<endl;
    cout<<"Enter 5 to Try Again: ";
    cin>>z;

    if (z == 5)
        {
            isValidTry = true;
            showMenu();
        }
    else
       {
      cout<<endl;
      //display error msg
      cout << "Please enter a valid input" << endl;
      cout<<endl;
       }
 }
}

void showBooks(const Book books[], int size)
{
    clearConsole();
            cout<<"**Book List**"<<endl;
            cout<<endl;

            //I want to make table like arrangement for user friendliness
            // Set column headers with specified width and alignment
            cout << left << setw(20) << "ISBN" << setw(20) << "Name" << setw(20) << "Author" << setw(15)<<internal<< "Price(Rs.)" << setw(15)<<internal << "Quantity" << endl;
             // Create a line separator for better readability
            cout << setfill('-') << setw(90) << "-" << setfill(' ') << endl; // Line separator

            //array
            for (int i = 0; i < maxSize; ++i)
                {
                   // Display each book's details with specified width and alignment
                   cout << left << setw(20) << books[i].isbn<< setw(20) << books[i].name << setw(20) << books[i].author << setw(15) << internal << books[i].price << setw(15) << internal << books[i].quantity << endl;
                }
                // Create a line separator after displaying the books
                cout << setfill('-') << setw(90) << "-" << setfill(' ') << endl;

                backManageBooks();  //function call
}

void searchBook(Book books[], int& size) {
    clearConsole();
    cout << "**Search Book**" << endl;
    cout << endl;
    string searchBook;
    cout << "Enter the book name or ISBN to search: ";
    cin.ignore(); // Ignore the newline character from the previous input
    getline(cin, searchBook); // Get the entire line as an input
    cout << endl;

    bool bookFound = false;

    for (int i = 0; i < maxSize; ++i) {
        // Compare ignoring case
        if (compareIgnoreCase(books[i].name, searchBook) || compareIgnoreCase(to_string(books[i].isbn), searchBook)) {
            bookFound = true;
            clearConsole();
            cout << "Book found" << endl;
            cout << endl;
            cout << "ISBN: " << books[i].isbn << "\tName: " << books[i].name << "\tAuthor: " << books[i].author << "\tPrice(Rs.): " << books[i].price << "\t\tQuantity: " << books[i].quantity << endl;

            backManageBooks();
            break;
        }
    }

    if (!bookFound) {
        clearConsole();
        cout << "Book not found." << endl;
        backManageBooks();
    }


}


void addBook(Book books[], int& size) {
    if (size < maxSize) {
        clearConsole();

        int newISBN;
        cout << "Enter ISBN: ";
        cin >> newISBN;

        // Check if a book with the same ISBN already exists
        int existingIndex = -1;
        for (int i = 0; i < size; ++i) {
            if (books[i].isbn == newISBN) {
                existingIndex = i;
                break;
            }
        }

        if (existingIndex != -1) {
            // Book with the same ISBN already exists, update quantity
            int additionalQuantity;
            cout << "Enter additional quantity: ";
            cin >> additionalQuantity;
            cout<<endl;

            books[existingIndex].quantity += additionalQuantity;

            cout << "Quantity updated for existing book with ISBN " << newISBN << "." << endl;
        } else {
            // Book with the given ISBN doesn't exist, add a new book
            books[size].isbn = newISBN;
            cout << "Enter book name: ";
            cin.ignore();
            getline(cin, books[size].name);
            cout << "Enter author name: ";
            getline(cin, books[size].author);
            cout << "Enter price: ";
            cin >> books[size].price;
            cout << "Enter quantity: ";
            cin >> books[size].quantity;
            cout<<endl;

            cout << "Successfully added '" << books[size].name << "' to the book list." << endl;

            ++size;
        }

        backManageBooks();
    } else {
        clearConsole();
        cout<<endl;
        cout << "Cannot add more books. Maximum limit reached." << endl;
        backManageBooks();
    }
}

void deleteBook(Book books[], int& size) {
    clearConsole();

    displayBookList(books, size);

    // Prompt user for the ISBN of the book to be deleted
    int deleteISBN;
    cout << "Enter the ISBN of the book to delete: ";
    cin >> deleteISBN;

    // Find the index of the book with the given ISBN
    int deleteIndex = -1;
    for (int i = 0; i < size; ++i) {
        if (books[i].isbn == deleteISBN) {
            deleteIndex = i;
            break;
        }
    }

    if (deleteIndex != -1) {
        // Shift elements to fill the gap caused by the deleted book
        for (int i = deleteIndex; i < size; ++i) {
            books[i] = books[i + 1];
        }

        --size;

        //print msg
        cout<<endl;
        cout << "Book with ISBN " << deleteISBN << " has been deleted." << endl;
    } else {
        cout<<endl;
        cout << "Book with ISBN " << deleteISBN << " not found." << endl;
    }

    backManageBooks(); // Go back to the book management menu
}


void prepareQuotation() {
    clearConsole();
    // Display the quotation header
    cout << "** Quotation **" << endl;
    cout << endl;

    // Declare variables for quotation details
    string date, customer, book, author;
    float price, discount, subTotal, total;
    int quantity;

    bool validBook = false;

    // Prompt user for quotation details
    cout << "Customer: ";
    cin.ignore();
    getline(cin, customer);

    while (!validBook) {
        // Prompt user for book details
        cout << "Book: ";
        getline(cin, book);

        // Find the book in the book array using case-insensitive comparison
        int bookIndex = -1;
        for (int i = 0; i < size; ++i) {
            // Compare ignoring case
            if (compareIgnoreCase(book, books[i].name)) {
                bookIndex = i;
                break;
            }
        }

        if (bookIndex != -1) {
            // Book found, directly use information from the book list
            author = books[bookIndex].author;
            price = books[bookIndex].price;

            validBook = true;

            // Prompt user for quantity
            bool validQuantity = false;
            while (!validQuantity) {
                cout << "Enter quantity: ";
                cin >> quantity;

                if (quantity > 0 && quantity <= books[bookIndex].quantity) {
                    validQuantity = true;
                } else {
                    cout << "Sorry, not enough stock" << endl;
                    backManageOrders();
                }
            }

            // Calculate subtotal
            subTotal = quantity * price;

            cout << endl;
            // Display subtotal
            cout << "Subtotal: Rs." << subTotal << endl;
            cout << endl;

            // Determine discount based on subtotal
            if (subTotal >= 5000) {
                discount = 25; // 25% discount
            } else if (subTotal >= 3000) {
                discount = 20; // 20% discount
            } else if (subTotal >= 1000) {
                discount = 10; // 10% discount
            } else {
                discount = 0; // No discount for less than 1000 subtotal
            }

            // Calculate total with discount
            total = subTotal - (subTotal * (discount / 100));

            // Display details with discount
            cout << discount << "% Discount added to the total bill" << endl;
            cout << "Discount: Rs." << subTotal * (discount / 100) << endl;
            cout << endl;
            cout << "Total = Rs." << subTotal << " - Rs." << subTotal * (discount / 100) << " = Rs." << total << "/=" << endl;

            // Open a text file for writing a quotation
            ofstream outputFile("quotation.txt");

            // Check if the file is successfully opened
            if (outputFile.is_open()) {
                // Write information to the file
                outputFile << "********************************************" << endl;
                outputFile << "            Nethra Book Shop - Kandy        " << endl;
                outputFile << "********************************************" << endl;
                outputFile << endl;
                outputFile << getCurrentDate() << endl;
                outputFile << "Customer: " << customer << endl;
                outputFile << endl;
                outputFile << "Book: " << book << endl;
                outputFile << "Author: " << author << endl;
                outputFile << "Price: Rs." << price << endl;
                outputFile << "Quantity: " << quantity << endl;
                outputFile << endl;
                outputFile << "Subtotal: Rs." << subTotal << endl;
                outputFile << endl;
                outputFile << discount << "% Discount added to the bill" << endl;
                outputFile << "Discount: Rs." << subTotal * (discount / 100) << endl;
                outputFile << endl;
                outputFile << "Total : Rs." << subTotal << " - Rs." << subTotal * (discount / 100) << " = Rs." << total << "/=" << endl;
                outputFile << endl;
                outputFile << "----------------------------------------------" << endl;
                outputFile << "   Thank you for choosing Nethra Book Shop!   " << endl;
                outputFile << "**********************************************" << endl;
                // Close the file
                outputFile.close();

                cout << endl;
                // Inform the user that the quotation has been successfully written
                setColor(YELLOW);
                cout << "Quotation has been written to the file 'quotation.txt'" << endl;
                setColor(WHITE);
            } else {
                // Display a message if writing the quotation fails
                cout << "Quotation has not been written" << endl;
            }
        } else {
            cout << "Book not found. Press 1 to try again or press 5 to back: ";

            int userChoice;
            cin >> userChoice;

            if (userChoice == 1) {
                // Clear the input buffer to prevent infinite loop on invalid input
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else if (userChoice == 5) {
                manageOrders();
            }
        }
    }
    backManageOrders();
}


void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void displayBookList(const Book books[], int size) {
    // Display the book list
    cout << "** Book List **" << endl;
    cout << endl;

    cout << left << setw(20) << "ISBN" << setw(20) << "Name" << setw(20) << "Author" << setw(15)<<internal<< "Price(Rs.)" << setw(15)<<internal << "Quantity" << endl;
             // Create a line separator for better readability
            cout << setfill('-') << setw(90) << "-" << setfill(' ') << endl; // Line separator

    for (int i = 0; i < size; ++i)
        {
                // Display each book's details with specified width and alignment
          cout << left << setw(20) << books[i].isbn<< setw(20) << books[i].name << setw(20) << books[i].author << setw(15) << internal << books[i].price << setw(15) << internal << books[i].quantity << endl;
        }
                // Create a line separator after displaying the books
            cout << setfill('-') << setw(90) << "-" << setfill(' ') << endl;


    cout << endl;
}

void showPendingOrders (const PendingOrder pendingOrders[], int penSize )
{
     clearConsole(); //function call
        //display the order list header
        cout<<"**Pending Orders**"<<endl;
        cout<<endl;

        // Set column headers with specified width and alignment
        cout << left << setw(12) << "Date" << setw(20) << "Customer" << setw(25)<< "Book" << setw(25)<< "Author"<<setw(15) <<internal << "Quantity" <<setw(15) <<internal << "Total (Rs.)"<< endl;
        cout << setfill('-') << setw(115) << "-" << setfill(' ') << endl; // Line separator

        // Loop through the array of orders and display their information
        for (int i = 0; i < maxPendingOrders; ++i)
            {
              //Display each book's details with specified width and alignment
              cout << left << setw(12) << pendingOrders[i].date << setw(20) << pendingOrders[i].customer << setw(25) << pendingOrders[i].orderBook << setw(25) << pendingOrders[i].authorBook << setw(15) << internal << pendingOrders[i].orderQuantity << setw(15) << internal << pendingOrders[i].orderTotal<< endl;}

            cout << setfill('-') << setw(115) << "-" << setfill(' ') << endl; //line seperator

        backManageOrders(); //call function to exit to order management menu

}

void addOrder(PendingOrder pendingOrders[], int& penSize) {
    if (penSize < maxPendingOrders) {
        clearConsole();


        pendingOrders[penSize].date = getCurrentDate();
        cout << "Customer: ";
        cin.ignore();
        getline(cin, pendingOrders[penSize].customer);

// Check if the book exists in the current book array
bool validBook = false;
do {
    cout << "Book: ";
    getline(cin, pendingOrders[penSize].orderBook);

    // Check if the book exists in the current book array
    for (int i = 0; i < size; ++i) {
        if (compareIgnoreCase(books[i].name, pendingOrders[penSize].orderBook)) {
            validBook = true;

            // Auto-generate author based on the existing book array
            pendingOrders[penSize].authorBook = books[i].author;

            // Auto-generate price based on the existing book array
            float price = books[i].price;

            // Prompt user for quantity
            cout << "Enter quantity: ";
            cin >> pendingOrders[penSize].orderQuantity;

            if (pendingOrders[penSize].orderQuantity > 0 && pendingOrders[penSize].orderQuantity <= books[i].quantity) {
                // Calculate subtotal
                float subTotal = pendingOrders[penSize].orderQuantity * price;

                // Determine discount based on subtotal
                float discount;
                if (subTotal >= 5000) {
                    discount = 25; // 25% discount
                } else if (subTotal >= 3000) {
                    discount = 20; // 20% discount
                } else if (subTotal >= 1000) {
                    discount = 10; // 10% discount
                } else {
                    discount = 0; // No discount for less than 1000 subtotal
                }

                // Calculate total with discount
                pendingOrders[penSize].orderTotal = subTotal - (subTotal * (discount / 100));

                // Display details with discount
                cout<<endl;
                cout << discount << "% Discount added to the total bill" << endl;
                cout << "Discount: Rs." << subTotal * (discount / 100) << endl;
                cout << endl;
                cout << "Total = Rs." << subTotal << " - Rs." << subTotal * (discount / 100) << " = Rs." << pendingOrders[penSize].orderTotal << "/=" << endl;

                cout << endl;
                cout << "Successfully added to the pending order." << endl;

                ++penSize;

                backManageOrders();
            } else {
                cout << "Sorry, out of stock or not enough stock. Available quantity: " << books[i].quantity << endl;
                backManageOrders();
            }

            break;
        }
    }

    if (!validBook) {
        cout << "Book not found. Press 1 to try again or press 5 to back:";

        int userChoice;
        cin >> userChoice;

        if (userChoice == 5) {
            manageOrders();
        } else {
            // Clear the input buffer to prevent infinite loop on invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }

   } while (!validBook);
  }
}


void completePendingOrder(PendingOrder pendingOrders[], int& penSize, Book books[], int& size) {
    clearConsole();

    // Check if there are no pending orders
    if (penSize == 0) {
        cout << "No pending orders." << endl;
        backManageOrders(); // You might want to handle this case appropriately
        return;
    }

    // Display pending orders
    cout << "Pending Orders:" << endl;
    cout << endl;
    for (int i = 0; i < penSize; ++i) {
        cout << i + 1 << ". " << pendingOrders[i].orderBook << " - " << pendingOrders[i].customer << endl;
        cout << endl;
    }

    // Prompt user to enter the index number to complete the order
    int selectedIndex;
    cout << "Enter the order number to complete: ";
    cin >> selectedIndex;
    selectedIndex -= 1;

    // Check if the entered index is valid
    if (selectedIndex >= 0 && selectedIndex < penSize) {
        // Get the index of the selected pending order
        int arrayIndex = selectedIndex;

        // Find the book in the books array
        int bookIndex = -1;
        for (int j = 0; j < size; ++j) {
         // Compare ignoring case
        if (compareIgnoreCase(books[j].name, pendingOrders[arrayIndex].orderBook)) {
        bookIndex = j;
         break;
    }
        }

        // Check if the book exists
        if (bookIndex != -1) {
            // Update the quantity of the completed order in the books array
            books[bookIndex].quantity -= pendingOrders[arrayIndex].orderQuantity;

            // Remove the order from the pending order list
            for (int j = arrayIndex; j < penSize; ++j) {
                pendingOrders[j] = pendingOrders[j + 1];
            }
            --penSize;

            // Display success message
            cout << endl;
            cout << "Order #" << selectedIndex + 1 << " completed successfully!" << endl;
        } else {
            // Display error message for book not found
            cout << "Error: Book not found in the book list." << endl;
        }
    } else {
        // Display error message for invalid index
        cout << "Error: Invalid number" << endl;
    }

    backManageOrders(); // Call function
}


// Function to get the current date
string getCurrentDate() {
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);

    // Convert the current time to a string in the format YYYY-MM-DD
    struct tm* timeinfo;
    char buffer[80];
    timeinfo = localtime(&currentTime);
    strftime(buffer, sizeof(buffer), "%Y/%m/%d", timeinfo);

    return string(buffer);
}

// Function to compare two strings ignoring case
bool compareIgnoreCase(const std::string& str1, const std::string& str2) {
    return std::equal(str1.begin(), str1.end(), str2.begin(), str2.end(), [](char c1, char c2) {
        return std::tolower(c1) == std::tolower(c2);
    });
}
