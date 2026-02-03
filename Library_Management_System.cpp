#include <iostream>
#include <fstream>
#include <string>
#include <fstream>

using namespace std;

class User{
    protected:
    string lib_ID, name, email;         
    //lib_ID is the ID assigned to user of any category(teacher, student, librarian) by library and is different than their respective ID
    public:
    User(){}
    User(string s1, string s2, string s3){
        lib_ID = s1;
        name = s2;
        email = s3;
    }
    virtual void read(ifstream &in, int id){
        getline(in, lib_ID);
        getline(in, name);
        getline(in, email);
    }
    virtual void show(){
        cout << lib_ID << "\t\t" << name << "\t\t" << email << endl;
    }
    virtual bool get_limit(){
        return false;
    }
    virtual void issued(){}
    virtual void returned(){}
    string getname(){
        return name;
    }
};
class Student:public User{
    int student_ID;      //student_ID refers to student roll no
    int issued_books;
    int borrow_limit;
    public:
    Student(){}
    Student(string s1, string s2, string s3, int s4):User(s1, s2, s3)
    {
        issued_books = 0;
        borrow_limit = 1;
        s4 += 210;
        student_ID = s4;
    }
    void read(ifstream &in, int id){
        getline(in, lib_ID);
        getline(in, name);
        getline(in, email);
        borrow_limit = 1;
        issued_books = 0;
        id += 500;
        student_ID = id;
    }
    void show(){
        cout << lib_ID << "\t\t" << name << "\t\t" << student_ID << "\t\t" << email << endl;
    }
    bool get_limit(){
        if (issued_books >= borrow_limit)
        {
            return false;
        }
        else{
            return true;
        }
    }
    void issued(){
        issued_books ++;
    }
    void returned(){
        issued_books -= 1;
    }
    string getname(){
        return name;
    }
};
class Faculty:public User{
    int faculty_ID;
    int issued_books;
    int borrow_limit;
    public:
    Faculty(){}
    Faculty(string s1, string s2, string s3, int s4):User(s1, s2, s3)
    {
        s4 += 700;
        faculty_ID = s4;
        issued_books = 0;
        borrow_limit = 5;
    }
    void read(ifstream &in, int id){
        getline(in, lib_ID);
        getline(in, name);
        getline(in, email);
        borrow_limit = 5;
        issued_books = 0;
        id += 700;
        faculty_ID = id;
    }
    void show(){
        cout << lib_ID << "\t\t" << name << "\t\t" << faculty_ID << "\t\t" << email << endl;
    }
    bool get_limit(){
        if (issued_books >= borrow_limit)
        {
            return false;
        }
        else{
            return true;
        }
    }
    void issued(){
        issued_books ++;
    }
    void returned(){
        issued_books -= 1;
    }
    string getname(){
        return name;
    }
};
class Librarian:public User{
    int librarian_ID;
    public:
    Librarian(){}
    Librarian(string s1, string s2, string s3, int s4):User(s1, s2, s3)
    {
        librarian_ID = s4;
    }
    void read(ifstream &in, int id){
        getline(in, lib_ID);
        getline(in, name);
        getline(in, email);
        id += 100;
        librarian_ID = id;
    }
    void show(){
        cout << lib_ID << "\t\t" << name << "\t\t" << librarian_ID << "\t\t" << email << endl;
    }
};
class Material{
    protected:
    string title, author;
    int ID;
    int available;
    int number;
    public:
    Material(){}
    Material(string s1, string s2, int id, int n){
        ID = id;
        title = s1;
        author = s2;
        number = available = n;
    }
    virtual void readbooks(ifstream &in, int id)
    {
        in >> title;
        in >> author;
        number = available = 10;
        ID = id;
    }
    virtual void show(){
        cout << title << "\tby" << author << endl;
    }
    string get_title(){
        return title;
    }
    void borrow(){
        if (available > 0)
        {
            available -= 1;
        }
        else{
            cout << "All books have been borrowed.\n";
        }
    }
    void Mreturn(){
        available += 1;
    }
    void showborrowed(){
        cout << title << "\tby " << author << "\t" << (number - available) << " borrowed" << "\t" << available << " Available" << endl;
    }
    virtual Material& operator=(const Material &M)
    {
        ID = M.ID;
        title = M.title;
        author = M.author;
        number = M.number;
        available = M.available;
        return *this;
    }
};
class Book:public Material{
    string ISBN;
    public:
    Book(){}
    Book(string s1, string s2, int id, int n, string s4):Material(s1, s2, id, n)
    {
        ISBN = s4;
    }
    virtual Book& operator=(const Book &M)
    {
        ID = M.ID;
        title = M.title;
        author = M.author;
        number = M.number;
        available = M.available;
        ISBN = M.ISBN;
        return *this;
    }
    void readbooks(ifstream &in, int id)
    {
        getline(in, title);
        getline(in, author);
        getline(in, ISBN);
        number = available = 10;
        ID = (id + 1000);
    }
    void show(){
        cout << "\"" << title << "\"" << "\t\tby " << author << "\t\tISBN: " << ISBN << endl;
    }
    string get_title(){
        return title;
    }
};
class Magazine:public Material{
    string genre;
    public:
    Magazine(){}
    Magazine(string s1, string s2, int id, int n, string s4):Material(s1, s2, id, n)
    {
        genre = s4;
    }
    void readbooks(ifstream &in, int id)
    {
        getline(in, title);
        getline(in, author);
        getline(in, genre);
        number = available = 10;
        ID = (id + 5000);
    }
    void show(){
        cout << "\"" << title << "\"" << "\t\t\t\tby " << author << "\t\t\tGenre: " << genre << endl;
    }
    string get_title(){
        return title;
    }
};
class CD:public Material{
    string artist;
    public:
    CD(){}
    CD(string s1, string s2, int id, int n, string s4):Material(s1, s2, id, n)
    {
        artist = s4;
    }
    void readbooks(ifstream &in, int id)
    {
        getline(in, title);
        getline(in, author);
        getline(in, artist);
        number = available = 10;
        ID = (id + 7000);
    }
    void show()
    {
        cout << "\"" << title << "\"" << "\t\t\tby " << author << "\t\tSung by: " << artist << endl;
    }
    string get_title(){
        return title;
    }
};
class Library{
    Material **borrowed;
    int total_borrowed;
    int total_user;
    int total_material;
    User **U;
    Material **M;
    public:
    Library(){
        total_borrowed = 0;
        total_material = 9;
        int i, n;
        ifstream f1;
        M = new Material*[9];
        f1.open("Books.txt");
        f1 >> n;
        for (i = 0; i < n; i++)
        {
            M[i] = new Book();
            M[i]->readbooks(f1, i+1);
        }
        f1.close();
        f1.open("Magazines.txt");
        f1 >> n;
        f1.clear();
        n += i;
        for (i = i; i < n; i++)
        {
            M[i] = new Magazine();
            M[i]->readbooks(f1, i+1);
        }
        f1.close();
        f1.open("CDs.txt");
        f1 >> n;
        n += i;
        f1.clear();
        for (i = i; i < n; i++)
        {
            M[i] = new CD();
            M[i]->readbooks(f1, i+1);
        }
        f1.close();
        f1.open("Users.txt");
        f1 >> n;
        total_user = n;
        U = new User*[n];
        for (i = 0; i < n; i++)
        {
            if (i == 0){
                U[i] = new Librarian();
                U[i]->read(f1, i+1);
            }
            else if (i <= 2){
                U[i] = new Student();
                U[i]->read(f1, i+1);
            }
            else{
                U[i] = new Faculty();
                U[i]->read(f1, i+1);
            }
        }
    }
    void add_Material(Material &m)
    {
        int i;
        total_material += 1;
        Material **temp;
        temp = new Material*[total_material];
        for (i = 0; i < (total_material - 1); i++)
        {
            temp[i] = M[i];
        }
        temp[i] = &m;
        M = temp;
    }
    void add_User(User &u)
    {
        int i;
        total_user += 1;
        User **temp;
        temp = new User*[total_user];
        for (i = 0; i < (total_user - 1); i++)
        {
            temp[i] = U[i];
        }
        temp[i] = &u;
        U = temp;
    }
    void displayAllMaterial(){
        cout << "All Material: \n";
        for (int i = 0; i < total_material; i++)
        {
            M[i]->show();
        }
    }
    void displayAllUsers(){
        cout << "All User: \n";
        for (int i = 0; i < total_user; i++)
        {
            U[i]->show();
        }
    }
    void to_borrow(User &u, string s){
        int x = -1;
        cout << u.getname() << " asks to borrow \"" << s << "\".\n";
        if (u.get_limit()){
            for (int i = 0; i < total_material; i++)
            {
                if (M[i]->get_title() == s)
                {
                    u.issued();
                    x = i;
                    total_borrowed++;
                    M[i]->borrow();
                    M[i]->showborrowed();
                    break;
                }
                else if (i == (total_material - 1)){
                    cout << "This book is not available.\n";
                }
            }
        }
        else{
                cout << "User limit has been exceeded. Return a book to borrow a new one.\n";
        }
        if (x > -1){
            int i, j = 0;
            Material **temp;
            temp = new Material*[total_borrowed];
            for (i = 0; i < (total_borrowed - 1); i++)
            {
                temp[j++] = borrowed[i];
            }
            temp[j] = M[x];
            borrowed = temp;
        }
    }
    void to_return(User &u, string s){
        int x = -1;
        for (int i = 0; i < total_material; i++)
        {
            if (M[i]->get_title() == s)
            {
                u.returned();
                x = i;
                M[i]->Mreturn();
                cout << "\"" << s << "\"" << " is returned by" << u.getname() << endl; 
                break;
            }
        }
        if (x > -1){
            int i, j;
            Material **temp = new Material*[(total_borrowed - 1)];
            for (i = 0, j = 0; i < total_borrowed; i++)
            {
                if (x != i){
                    temp[j++] = borrowed[i];
                }
            }
            total_borrowed -= 1;
            delete borrowed;
            borrowed = temp;
        }
    }
    void displayBorrowed(){
        cout << "Total books Borrowed: \n";
        if (total_borrowed == 0){
            cout << "No books has been borrowed till now or are returned by now.\n";
        }
        for (int i = 0; i < total_borrowed; i++)
        {
            borrowed[i]->showborrowed();
        }
    }
};
int main()
{
    Library library;
    Material *m = new Book("The C++ Programming Language", "Bjarne Stroustrup", 1004, 5, "9780321563842");
    User *u = new Faculty("lib-fc-303", "Aleem Dar", "aleem@gmail.com", 3);
    library.add_Material(*m);
    library.displayAllMaterial();
    library.displayAllUsers();
    library.add_User(*u);
    library.to_borrow(*u, "The C++ Programming Language");
    library.displayBorrowed();
    library.to_return(*u, "The C++ Programming Language");
    library.displayBorrowed();
    return 0;
}