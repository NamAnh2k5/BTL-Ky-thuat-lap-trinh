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
    char symbol;
    cout << "-------------------------------------------" << endl;
    cout << "=============QUẢN LÍ BỆNH NHÂN=============" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "1. Them thong tin benh nhan." << endl;
    cout << "2. Sua thong tin benh nhan." << endl;
    cout << "3. Xoa thong tin benh nhan." << endl;
    cout << "4. Tim kiem ho so benh nhan." << endl;
    cout << "5. " << endl;
    cout << "6. Thêm hồ sơ bệnh án của bệnh nhân." << endl;
    cout << "7. Sửa thông tin hồ sơ bệnh án của bệnh nhân." << endl;
    cout << "8. Tìm kiếm vị trí hồ sơ bệnh án của bệnh nhân." << endl;
    cin >> symbol;

    switch(symbol) {
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

}

int main() {
    menu();
    return 0;
}
