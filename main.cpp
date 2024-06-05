#include <iostream>
#include <stdlib.h>
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


class MedicalRecord {
public:
    std::string ngay;
    std::string chuanDoan;
    std::string dieuTri;

    MedicalRecord(std::string ngay, std::string chuanDoan, std::string dieuTri) {
        this->ngay = ngay;
        this->chuanDoan = chuanDoan;
        this->dieuTri = dieuTri;
    }
};

class Patient {
public:
    int id;
    std::string ten;
    int tuoi;
    std::string gioiTinh;
    std::vector<MedicalRecord> hoSoBenhAn;

    Patient(int id, std::string ten, int tuoi, std::string gioiTinh) {
        this->id = id;
        this->ten = ten;
        this->tuoi = tuoi;
        this->gioiTinh = gioiTinh;
    }

    void themHoSoBenhAn(MedicalRecord record) {
        hoSoBenhAn.push_back(record);
    }

    void inHoSoBenhAn() {
        std::cout << "Ho so benh an cua " << ten << ":\n";
        for (auto &record : hoSoBenhAn) {
            std::cout << "Ngay: " << record.ngay << ", Chuan doan: " << record.chuanDoan << ", Dieu tri: " << record.dieuTri << "\n";
        }
    }
};
class HospitalManagementSystem {
private:
    std::vector<Patient> benhNhan;

public:
    void themBenhNhan(int id, std::string ten, int tuoi, std::string gioiTinh) {
        Patient newPatient(id, ten, tuoi, gioiTinh);
        benhNhan.push_back(newPatient);
    }

    void themHoSoBenhAn(int patientId, std::string ngay, std::string chuanDoan, std::string dieuTri) {
        for (auto &patient : benhNhan) {
            if (patient.id == patientId) {
                MedicalRecord newRecord(ngay, chuanDoan, dieuTri);
                patient.themHoSoBenhAn(newRecord);
                return;
            }
        }
        std::cout << "Không tìm thấy bệnh nhân với ID " << patientId << ".\n";
    }

    void inHoSoBenhAnBenhNhan(int patientId) {
        for (auto &patient : benhNhan) {
            if (patient.id == patientId) {
                patient.inHoSoBenhAn();
                return;
            }
        }
        std::cout << "Không tìm thấy bệnh nhân với ID " << patientId << ".\n";
    }
};


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

}

int main() {
    menu();
    return 0;
}
