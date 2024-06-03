#include <iostream>
#include <stdlib.h>
using namespace std;

void add(); //hàm nhập dữ liệu
void remove(); //hàm xoá dữ liệu
void modify(); //hàm sửa dữ liệu
void find(); //hàm tìm kiếm dữ liệu
void arrange(); //hàm sắp xếp dữ liệu
void statistic(); //hàm thống kê

void menu() {
    char symbol;
    cout << "[1] Nhap du lieu" << endl;
    cout << "[2] Xoa du lieu" << endl;
    cout << "[3] Sua du lieu" << endl;
    cout << "[4] Tim kiem du lieu" << endl;
    cout << "[5] Sap xep du lieu" << endl;
    cout << "[6] Thong ke du lieu" << endl;
    cout << "Nhap ky tu tuong ung voi hanh dong ban muon thuc hien: ";
    cout << "test";
    cout << "test2";
    cin >> symbol;

    switch(symbol) {
        case '+':
            system("cls");
            cout << "add" << endl;
            break;
        case '-':
            system("cls");
            cout << "remove" << endl;
            break;
        case '~':
            system("cls");
            cout << "modify" << endl;
            break;
        case '/':
            system("cls");
            cout << "find" << endl;
            break;
        case '#':
            system("cls");
            cout << "arrange" << endl;
            break;
        case '=':
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
