#include <iostream> 
#include <unistd.h>//Use Delay
#include <fstream>
//#include <cstdlib>
/*#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/statement.h>
#include <mysql_driver.h>
#include <mysql_connection.h>*/

using namespace std;
//using namespace sql::mysql;
//#define EXIT_SUCCESS 0

class Menu{
public:
    void MainMenu();
    string choice;
private:
     
};

class Login{
public:
    int UserLogin();
private:
    char Password[20];
    char User[20];
};

class Register{
public:
    int UserRegister();
private:
    char RegisUserPassWord[20];
    char RegisUserId[20];
};

class ForgotPassword{
public:
    void UserForgotPassword();
    string option;
private:
    char ForgotUserId[20];
    string suserId, sId, spass;
};

class DataBase{
public:
    //int DataBase();
    void SQLDataBase();
};

int main(){
    Menu myMenu;
    //DataBase MyDataBase;
    //MyDataBase.SQLDataBase();
    myMenu.MainMenu();
    return 0;
}

/*void DataBase::SQLDataBase(){
    cout << endl;
    cout << "Running 'SELECT 'Successfull' »AS _message'..." << endl;

    try {
        sql::Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        ///* Create a connection
        driver = sql::mysql::get_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "root");
        ///* Connect to the MySQL test database 
        con->setSchema("test");

        stmt = con->createStatement();
        res = stmt->executeQuery("SELECT 'Successfull' AS _message"); // replace with your statement
        while (res->next()) {
            cout << "\t... MySQL replies: ";
            ///* Access column data by alias or column name 
            cout << res->getString("_message") << endl;
            cout << "\t... MySQL says it again: ";
            ///* Access column fata by numeric offset, 1 is the first column 
            cout << res->getString(1) << endl;
        }
        delete res;
        delete stmt;
        delete con;
    }
    catch (sql::SQLException &e) {
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }

    cout << endl;

    //return 0;
}*/

void Menu::MainMenu(){
    Login myLogin;
    Register myRegister;
    ForgotPassword MyForgotPassword;
#if defined(_WIN32)
    system("cls"); //Only for windows
#endif
    cout<< u8"\033[2J\033[1;1H"; //Only for linux
    cout << "\t\t\t*****************************************\n";
    cout << "\t\t\t              Login System               \n";
    cout << "\t\t\t*****************************************\n";
    cout << "\t\t\t*  Press 1 to login                     *\n";
    cout << "\t\t\t*  Press 2 to register                  *\n";
    cout << "\t\t\t*  Press 3 if you forgot your password  *\n";
    cout << "\n\t\t\t Please enter your choice : ";
    cin >> choice;
    if(choice == "1"){
        myLogin.UserLogin();
    }
    else if(choice == "2"){
        myRegister.UserRegister();
    }
    else if(choice == "3"){
        MyForgotPassword.UserForgotPassword();
    }
    else{
#if defined(_WIN32)
        system("cls"); //Only for windows
#endif
        cout<< u8"\033[2J\033[1;1H"; //Only for linux
        cout<< "\n\t\t\t Please enter your choice again! \n";
#if defined(_WIN32)
        sleep(3000); //Only for windows
#endif
        usleep(3000000); //Microsec
        MainMenu();
    }
}

int Login::UserLogin(){
    string id;
    string pass;
    int count = 0;
#if defined(_WIN32)
        system("cls"); //Only for windows
#endif
    cout<< u8"\033[2J\033[1;1H"; //Only for linux
    cout << "\t\t\t Enter the username : ";
    cin >> User;
    cout << "\t\t\t Enter the password : ";
    cin >> Password;
    ifstream inputFile("/home/facom/develop/kernel/heaven_os/records.txt",ios::in);
    while (inputFile >> id >> pass){
        if (id == User && pass == Password){
            count = 1;
        }
    }
    /*if (!inputFile){
        cerr << "\n\t\t\t Error opening file!" << endl;
        return 1;
    }*/
    inputFile.close();
    if (count == 1){
        cout << "\n\t\t\t Your login is successfull \n";
#if defined(_WIN32)
        sleep(3000); //Only for windows
#endif
        usleep(3000000); //Microsec
        main();
    }
    else{
        cout << "\n\t\t\t\t Login error! \n \t\t\tPlease check your username and password\n";
#if defined(_WIN32)
        sleep(3000); //Only for windows
#endif
        usleep(3000000); //Microsec
        main();
    }
    //main();
}

int Register::UserRegister(){
#if defined(_WIN32)
        system("cls"); //Only for windows
#endif
    cout<< u8"\033[2J\033[1;1H"; //Only for linux
    cout << "\t\t\t Enter the username : ";
    cin >> RegisUserId;
    cout << "\t\t\t Enter the password : ";
    cin >> RegisUserPassWord;

    ofstream OutputFile("/home/facom/develop/kernel/heaven_os/records.txt",ios::app);
    OutputFile << RegisUserId << " " << RegisUserPassWord << endl;
    OutputFile.close();
#if defined(_WIN32)
        system("cls"); //Only for windows
#endif
    cout<< u8"\033[2J\033[1;1H"; //Only for linux
    cout << "\n\t\t\t Registrationis succesfull! \n";
#if defined(_WIN32)
        sleep(3000); //Only for windows
#endif
    usleep(3000000); //Microsec
    main();
}

void ForgotPassword::UserForgotPassword(){
#if defined(_WIN32)
        system("cls"); //Only for windows
#endif
    cout<< u8"\033[2J\033[1;1H"; //Only for linux
    cout << "\n\t\t\t Press 1 to search your id by username \n";
    cout << "\n\t\t\t Press 2 back to the main menu \n";
    cout << "\n\t\t\t Enter your choice : ";
    cin >> option;
    if(option == "1"){
        int count = 0;
#if defined(_WIN32)
        system("cls"); //Only for windows
#endif
        cout<< u8"\033[2J\033[1;1H"; //Only for linux
        cout << "\n\t\t\t Enter the username which you remembered : ";
        cin >> suserId;
        ifstream f1("/home/facom/develop/kernel/heaven_os/records.txt",ios::in);
        while (f1 >> sId >> spass){
            if (sId == suserId){
                count = 1;
            }
        }
        f1.close();
        if (count == 1){
            cout << "\n\t\t\t Your account is found \n";
            cout << "\n\t\t\t Your password is : " << spass << endl;
#if defined(_WIN32)
            sleep(3000); //Only for windows
#endif
            usleep(10000000); //Microsec
            main();
        }
        else{
#if defined(_WIN32)
            system("cls"); 
#endif
            cout<< u8"\033[2J\033[1;1H"; //Only for linux
            cout << "\n\t\t\t Your account is not found! \n";
#if defined(_WIN32)
            sleep(3000); 
#endif
            usleep(3000000); //Microsec
            main();
        }
    }
    else if(option == "2"){
        main();
    }
    else{
#if defined(_WIN32)
        system("cls"); 
#endif
        cout<< u8"\033[2J\033[1;1H"; //Only for linux
        cout << "\n\t\t\t Please enter your choice again! " << endl;
#if defined(_WIN32)
         sleep(3000); 
#endif
        usleep(1000000); //Microsec
        UserForgotPassword();
    }
    main();
}