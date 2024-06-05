#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
struct Users{
    string mahoso;
    string username;
    string password;
};
vector <Users> users;
void add(); //hàm nhập dữ liệu
void remove(); //hàm xoá dữ liệu
void modify(); //hàm sửa dữ liệu
void find(); //hàm tìm kiếm dữ liệu
void arrange(); //hàm sắp xếp dữ liệu
void statistic(); //hàm thống kê

void addUsers(){
    Users user;
    cout << "Nhap ma ho so: ";
    cin.ignore();
    getline(cin,user.mahoso);

    cout << "Nhap ten dang nhap: ";
    cin.ignore();
    getline(cin,user.username);

    cout << "Nhap mat khau: ";
    cin.ignore();
    getline(cin,user.password);

    users.push_back(user);
    cout << "Da them nguoi dung thanh cong!";
}

bool Login(){
    Users user;
    string username, password;

    cout << "Nhap ten dang nhap: ";
    cin.ignore();
    getline(cin,username);

    cout << "Nhap mat khau: ";
    cin.ignore();
    getline(cin,password);
   
    for(const Users &user : users){
        if(user.username == username && user.password == password){
            cout << "Dang nhap thanh cong!";
            return 1;
        }
        else cout << "Dang nhap khong thanh cong!";
        return 0;
    }
}

bool UsersLevel(string level){
    
}




void menu() {
    do{
        char number;
        cout << "-------------------------------------------" << endl;
        cout << "=============QUẢN LÍ BỆNH NHÂN=============" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "[1]. Them thong tin benh nhan." << endl;
        cout << "[2]. Sua thong tin benh nhan." << endl;
        cout << "[3]. Xoa thong tin benh nhan." << endl;
        cout << "[4]. Tim kiem ho so benh nhan." << endl;
        cout << "[5]. Sap xep ho so benh nhan." << endl;
        cout << "[6]. Thong ke ho so benh nhan." << endl;
        cout << "[7]. Them nguoi dung." << endl;
        cout << "[0]. Thoat chuong trinh"<<endl;
        cin >> number;

        switch(number) {
            case '1':
                system("cls");
                cout << "add" << endl;
                break;
            case '2':
                system("cls");
                cout << "remove" << endl;
                break;
            case '3':
                system("cls");
                cout << "modify" << endl;
                break;
            case '4':
                system("cls");
                cout << "find" << endl;
                break;
            case '5':
                system("cls");
                cout << "arrange" << endl;
                break;
            case '6':
                system("cls");
                cout << "statistic" << endl;
                break;
            default:
                system("cls");
                cout << "khong tim thay hanh dong phu hop!";
                break;
        }
    }while(number!='0');
}

int main() {
    menu();
    return 0;
}
