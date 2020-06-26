#include <iostream>
#include "User.h"
#include "Book.h"

using namespace std;

//nicolle

int login(User*,int);
void register_user(User*,int*);
int menu_user();
int menu_admin();
void add_book(Book*,int*);
void modify_book(Book*,int*);
void delete_book(Book*,int*);
void buy_book(User*,Book*, int);
void find_autor(User*,Book*, int);
void find_title(User*,Book*, int);
void update_password(User*);
void sort_books_title(Book*,int);

int main(){
    User users[10];
    Book books[10];
    int number_users = 1;
    int number_books = 0;
    User administrator("n.duron","sybase","Nicolle Duron",20,1000);
    users[0] = administrator;

    int respuesta = 1;
    while (true){
        cout<<" *BOOKSTORE* "<<endl;
        cout<<"1) Log-in"<<endl;
        cout<<"2) Registrarse"<<endl;
        cout<<"0) Salir"<<endl;
        cout<<"-> Ingrese su opcion:";
        cin>>respuesta;

        if (respuesta == 0){
            break;
        }
        
        if(respuesta == 1){
            int login_flag = login(&users[0],number_users);
            if(login_flag == 0){    
                int flag_menu_admin = 0;
                do{          
                    flag_menu_admin = menu_admin();
                    switch (flag_menu_admin){
                        case 1:
                            add_book(&books[number_books],&number_books);
                            sort_books_title(&books[0],number_books);
                            break;
                        case 2:
                            modify_book(&books[0],&number_books);
                            break;
                        case 3:
                            delete_book(&books[0],&number_books);
                            break;
                        case 4:
                            number_books = 0;
                            cout<<" #Registros eliminados "<<endl;                           
                        default:
                            break;
                    }
                } while (flag_menu_admin != 0);                                
            }else if(login_flag == -1){
                cout<<"Intente de nuevo"<<endl;
            }else{                
                int flag_menu_user = 0;
                do{          
                    flag_menu_user = menu_user();
                    switch (flag_menu_user){
                        case 1:
                            buy_book(&users[login_flag],&books[0], number_books);
                            break;
                        case 2:
                            find_autor(&users[login_flag],&books[0], number_books);
                            break;
                        case 3:
                            find_title(&users[login_flag],&books[0], number_books);
                            break;
                        case 4:
                            {   
                                double money = 0;
                                cout<<" *AGREGAR DINERO*"<<endl;
                                cout<<"->Ingrese el monto a agregar: ";
                                cin>>money;
                                users[login_flag].addMoney(money);
                                cout<<"#Dinero agregado"<<endl;
                            }
                            break;
                        case 5:
                            update_password(&users[login_flag]);                            
                        case 6:
                            for (size_t i = login_flag; i < number_users; i++){        
                                users[i] = users[i+1];
                            }
                            cout<<"#Usuario eliminado"<<endl;
                            flag_menu_user = 0;   
                        default:
                            break;
                    }
                } while (flag_menu_user != 0);
            }        
        }else{
            register_user(&users[number_users],&number_users);
        }                
    }
    cout<<endl;
    cout<<"Ha salido."<<endl;
    cout<<endl;
}

int login(User* users, int number_users){
    string user;
    string password;

    cout<<" *LOG IN* "<<endl;
    cout<<"->Usuario: ";
    cin>>user;
    cout<<"->Password: ";
    cin>>password;
        
    for (size_t i = 0; i < number_users; i++){        
        if(users[i].getUser() == user){
            if(users[i].getPassword() == password){                
                return i;                
            }else{
                return -1;
            }
        }
    }
    
    return -1;
}

void register_user(User* users, int* number_users){
    string user;
    string password;
    string name;
    int age;
    double money;

    cout<<" *REGISTRAR USUARIOS* "<<endl;
    cout<<"->Usuario: ";
    cin>>user;
    cout<<"->Password: ";
    cin>>password;
    cout<<"->Nombre: ";
    cin>>name;
    cout<<"->Edad: ";
    cin>>age;
    cout<<"->Dinero: ";
    cin>>money;

    User new_user(user,password,name,age,money);
    *(number_users) = *(number_users)+1;
    *(users) = new_user;    

    cout<<" #Registrado "<<endl;
}

int menu_user(){
    int respuesta = 0;
    cout<<" *MENU USUARIO* "<<endl;
    cout<<"1) Comprar libro"<<endl;
    cout<<"2) Buscar por autor"<<endl;    
    cout<<"3) Buscar por titulo"<<endl;   
    cout<<"4) Agregar dinero a mi cuenta"<<endl;
    cout<<"5) Restablecer contraseña"<<endl;
    cout<<"6) Borrar cuenta"<<endl;
    cout<<"0) Salir"<<endl;
    cout<<"-> Ingrese su opcion: "; 
    cin>>respuesta;
    return respuesta;
}

int menu_admin(){
    int respuesta = 0;
    cout<<" *MENU ADMIN* "<<endl;
    cout<<"1) Agregar libro"<<endl;
    cout<<"2) Modificar libro"<<endl;
    cout<<"3) Eliminar libro"<<endl;
    cout<<"4) Borrar registro de libros"<<endl;
    cout<<"0) Salir"<<endl; 
    cout<<"-> Ingrese su opcion: "; 
    cin>>respuesta;
    return respuesta;
}

void add_book(Book* books,int* number_books){
    string title;
    string author;
    string status = "Disponible";
    int year;
    double price;

    cout<<" *AGREGAR LIBRO* "<<endl;
    cout<<"->Titulo: ";
    cin>>title;
    cout<<"->Autor: ";
    cin>>author;
    cout<<"->Año: ";
    cin>>year;
    cout<<"->Precio: ";
    cin>>price;

    Book new_user(title,author,status,year,price);
    *(number_books) = *(number_books)+1;
    *(books) = new_user; 

    cout<<" #Agregado "<<endl;
}

void modify_book(Book* books,int* number_books){
    string title;
    string author;
    string status;
    int year;
    double price;

    int index = 0;
    cout<<" *MODIFICAR LIBRO* "<<endl;
    for (size_t i = 0; i < *number_books; i++){        
        cout<<"No. "<<i<<endl;
        books[i].toString();
    }
    cout<<"->Ingrese el indice del libro a modificar: ";
    cin>>index;

    cout<<"Ingrese sus nuevos datos:"<<endl;
    cout<<"->Titulo: ";
    cin>>title;
    cout<<"->Autor: ";
    cin>>author;
    cout<<"->Año: ";
    cin>>year;
    cout<<"->Precio: ";
    cin>>price;

    books[index].update(title,author,books[index].getStatus(),year,price);

    cout<<" #Modificado "<<endl;
}

void delete_book(Book* books,int* number_books){
    int index = 0;
    cout<<" *ELIMINAR LIBRO* "<<endl;
    for (size_t i = 0; i < *number_books; i++){        
        cout<<"No. "<<i<<endl;
        books[i].toString();
    }  
    cout<<"->Ingrese el indice del libro a eliminar: ";
    cin>>index;
    for (size_t i = index; i < *number_books; i++){        
        books[i] = books[i+1];
    }
    
    *(number_books) = *(number_books)-1;

    cout<<" #Eliminado "<<endl;
}

void buy_book(User* user,Book* books, int number_books){
    int index = 0;
    cout<<" *COMPRAR LIBRO* "<<endl;
    for (size_t i = 0; i < number_books; i++){        
        cout<<"No. "<<i<<endl;
        books[i].toString();
    }
    cout<<"->Ingrese el indice del libro a comprar: ";
    cin>>index;
    if(books[index].getStatus() != "Disponible")
        cout<<"X-Libro no disponible"<<endl;
    else if(books[index].getPrice() > user->getMoney()){
        cout<<"X-No tiene suficiente dinero"<<endl;
    }else{
        user->buy(books[index].getPrice());
        books[index].buy();
        cout<<"#Comprado"<<endl;
    }    
}

void find_autor(User* user,Book* books, int number_books){
    int index = 0;
    string autor = "";

    cout<<" *BUSCAR POR AUTOR* "<<endl;
    cout<<"->Ingrese el autor: ";
    cin>>autor;    

    bool flag = true;
    for (size_t i = 0; i < number_books; i++){        
        if(books[i].getAuthor() == autor){        
            cout<<"No. "<<i<<endl;
            books[i].toString();
            flag = false;
        }
    }

    if(flag){
        cout<<"X-No se encontraron resultados"<<endl;        
        return;
    }

    cout<<"->Ingrese el indice del libro a comprar: ";
    cin>>index;
    if(books[index].getStatus() != "Disponible")
        cout<<"X-Libro no disponible"<<endl;
    else if(books[index].getPrice() > user->getMoney()){
        cout<<"X-No tiene suficiente dinero"<<endl;
    }else{
        user->buy(books[index].getPrice());
        books[index].buy();
        cout<<"#Comprado"<<endl;
    }    
}

void find_title(User* user,Book* books, int number_books){
    int index = 0;
    string title = "";

    cout<<" *BUSCAR POR TITULO* "<<endl;
    cout<<"->Ingrese el autor: ";
    cin>>title;    

    bool flag = true;
    for (size_t i = 0; i < number_books; i++){        
        if(books[i].getTitle() == title){        
            cout<<"No. "<<i<<endl;
            books[i].toString();
            flag = false;
        }
    }

    if(flag){
        cout<<"X-No se encontraron resultados"<<endl;        
        return;
    }

    cout<<"->Ingrese el indice del libro a comprar: ";
    cin>>index;
    if(books[index].getStatus() != "Disponible")
        cout<<"X-Libro no disponible"<<endl;
    else if(books[index].getPrice() > user->getMoney()){
        cout<<"X-No tiene suficiente dinero"<<endl;
    }else{
        user->buy(books[index].getPrice());
        books[index].buy();
        cout<<"#Comprado"<<endl;
    }    
}

void update_password(User* user){
    string password = "";
    cout<<" *RESTABLECER PASSWORD* "<<endl;
    cout<<"->Ingrese contraseña anterior: ";
    cin>>password;
    if(user->getPassword() != password){
        cout<<"X-Contraseña incorrecta"<<endl;
        return;
    }else{
        cout<<"->Ingrese nueva contraseña: ";
        cin>>password;
        user->setPassword(password);
        cout<<"#Actualizado con exito";
    }
}    

void sort_books_title(Book* books ,int number_books){    
    bool swapped; 
    for (int i = 0; i < number_books-1; i++) { 
        swapped = false; 
        for (int j = 0; j < number_books-i-1; j++) { 
            if (books[j].getTitle() > books[j+1].getTitle()) {
                Book temporal = books[j];
                books[j] = books[j+1];
                books[j+1] = temporal;
                swapped = true; 
            } 
        }         
        if (swapped == false) 
            break; 
    } 
}