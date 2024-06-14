#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include<string>
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
    getline(cin, input);
    newPatient.setPatientName(input);

    cout << "Nhap ngay sinh:" << endl;
    cout << "  Ngay (dd): ";
    cin >> day;
    cout << "  Thang (mm): ";
    cin >> month;
    cout << "  Nam (yyyy): ";
    cin >> year;
    cin.ignore();
    newPatient.setBirthday(Date(day, month, year));

    cout << "Nhap gioi tinh: ";
    getline(cin, input);
    newPatient.setGender(input);

    cout << "Nhap dia chi: ";
    getline(cin, input);
    newPatient.setAddress(input);

    cout << "Nhap so dien thoai: ";
    getline(cin, input);
    newPatient.setPhoneNumber(input);

    cout << "Nhap ma so benh nhan: ";
    getline(cin, input);
    newPatient.setPatientID(input);

    patients.push_back(newPatient);
}

//Ham hien thi benh nhan theo dong voi cac cot la cac muc
void Patient::displayPatients(const vector<Patient>& patients) {
    cout << left << setw(20) << "Ho va ten"
         << setw(15) << "Ngay sinh"
         << setw(10) << "Gioi tinh"
         << right<< setw(30) << "Dia chi"
         << setw(15) << "So dien thoai"
         << setw(15) << "Ma benh nhan" << endl;

    cout << setfill('-') << setw(105) << "-" << endl;
    cout << setfill(' ');

    for (const auto& patient : patients) {
        cout << left << setw(20) << patient.getPatientName()
             << setw(2) << patient.getBirthday().getDay() << "/"
             << setw(2) << patient.getBirthday().getMonth() << "/"
             << setw(4) << patient.getBirthday().getYear() << setfill(' ') << setw(11)
             << right << setw(10) << patient.getGender()
             << right << setw(30) << patient.getAddress()
             << right << setw(15) << patient.getPhoneNumber()
             << right<< setw(15) << patient.getPatientID() << endl;
        cout << setfill('-') << setw(105) << "-" << endl;
        cout << setfill(' ');
    }
}

//ham xoa benh nha
void Patient::deletePatient(vector<Patient>& patients){
    cout<<"\nNhap id ma ban muon xoa: ";
    string id;
    cin.ignore();
    getline(cin,id);

    bool found=false;
    for(int i=0;i<patients.size();i++){
        if(patients[i].getPatientID() == id){
            patients.erase(patients.begin()+i);
            found=true;
            cout<<"Da xoa thanh cong benh nhan voi ID: "<<id<<endl;
            break;
        }
    }

    if(!found){
        cout<<"Khong tim thay benh nhan co ID: "<<id<<endl;
    }
}

//hàm sửa
void Patient::editPatient(vector<Patient>& patients){
    cout<<"Nhap id cua benh nhan ma ban muon sua: ";
    string id;
    cin.ignore();
    getline(cin,id);

    bool found=false;
    for(int i=0;i<patients.size();i++){
        if(patients[i].getPatientID() == id){
            found = true;
            cout << "Chon muc can sua:" << endl;
            cout << "[1]. Ten benh nhan" << endl;
            cout << "[2]. Ngay sinh" << endl;
            cout << "[3]. Gioi tinh" << endl;
            cout << "[4]. Dia chi" << endl;
            cout << "[5]. So dien thoai" << endl;
            cout << "[0]. Quay lai menu" << endl;

            char choice;
            do{
            cin >> choice;
            cin.ignore(); 

            switch (choice) {
                case '1': {
                    string newName;
                    cout << "Nhap ten benh nhan moi: ";
                    getline(cin, newName);
                    patients[i].setPatientName(newName);
                    cout << "Da sua ten benh nhan thanh cong." << endl;
                    break;
                }
                case '2': {
                    int day, month, year;
                    cout << "Nhap ngay sinh moi:" << endl;
                    cout << "  Ngay (dd): ";
                    cin >> day;
                    cout << "  Thang (mm): ";
                    cin >> month;
                    cout << "  Nam (yyyy): ";
                    cin >> year;
                    cin.ignore(); 
                    patients[i].setBirthday(Date(day, month, year));
                    cout << "Da sua ngay sinh thanh cong." << endl;
                    break;
                }
                case '3': {
                    string newGender;
                    cout << "Nhap gioi tinh moi: ";
                    getline(cin, newGender);
                    patients[i].setGender(newGender);
                    cout << "Da sua gioi tinh thanh cong." << endl;
                    break;
                }
                case '4': {
                    string newAddress;
                    cout << "Nhap dia chi moi: ";
                    getline(cin, newAddress);
                    patients[i].setAddress(newAddress);
                    cout << "Da sua dia chi thanh cong." << endl;
                    break;
                }
                case '5': {
                    string newPhone;
                    cout << "Nhap so dien thoai moi: ";
                    getline(cin, newPhone);
                    patients[i].setPhoneNumber(newPhone);
                    cout << "Da sua so dien thoai thanh cong." << endl;
                    break;
                }
                case '0':
                    cout << "Quay lai menu chinh." << endl;
                    break;
                default:
                    cout << "Lua chon khong hop le." << endl;
                    break;
            }
            }while(choice!='0');
        }
    }
    if(!found){
        cout<<"Khong tim thay benh nhan co ID: "<<id<<endl;
    }
}

void menu() {
    vector<Patient> patients;

    char number;
    do {
        cout << "-------------------------------------------" << endl;
        cout << "=============QUAN LI BENH NHAN=============" << endl;
        cout << "-------------------------------------------" << endl;
        cout << "[1]. Them thong tin benh nhan." << endl;
        cout << "[2]. Hien thi danh sach benh nhan." << endl;
        cout << "[3]. Sua thong tin benh nhan." << endl;
        cout << "[4]. Xoa thong tin benh nhan." << endl;
        cout << "[5]. Tim kiem ho so benh nhan." << endl;
        cout << "[6]. Sap xep ho so benh nhan." << endl;
        cout << "[7]. Thong ke ho so benh nhan." << endl;
        cout << "[0]. Thoat chuong trinh" << endl;
        cin >> number;

        switch (number) {
            case '1':
                system("cls");
                Patient::addPatient(patients);
                break;
            case '2':
                system("cls");
                Patient::displayPatients(patients);
                break;
            case '3':
                system("cls");
                cout << " sua ." << endl;
                break;
            case '4':
                system("cls");
                Patient::deletePatient(patients);
                break;
            case '5':
                system("cls");
                cout << "tim kiem." << endl;
                break;
            case '6':
                system("cls");
                cout << "sap xep " << endl;
                break;
            case '7':
                system("cls");
                cout << " thong ke " << endl;
                break;
            case '0':
                cout << "Thoat chuong trinh." << endl;
                break;
            default:
                system("cls");
                cout << "Khong tim thay hanh dong phu hop!" << endl;
                break;
        }
    } while (number != '0');
}

int main() {
    menu();
    return 0;
}
