#include <string>

using namespace std;

class User{
    private:
        string user;
        string password;
        string name;
        int age;
        double money;
    public:
        User(string,string,string,int,double);
        User();

        string getName();        
        string getUser();        
        string getPassword();
        void setPassword(string);
        double getMoney();
        void addMoney(double);
        void buy(double);

        ~User();
};


