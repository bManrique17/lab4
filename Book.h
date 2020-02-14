#include <string>

using namespace std;

class Book{
private:
    string title;
    string author;
    string status;
    int year;
    double price;
public:
    Book(string,string,string,int,double);
    Book();
    
    void toString();
    void update(string,string,string,int,double);
    string getStatus();
    string getAuthor();
    string getTitle();
    double getPrice();
    void buy();

    ~Book();
};
