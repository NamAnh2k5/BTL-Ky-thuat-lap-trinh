#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Date {
public:
    int day;
    int month;
    int year;

    Date(int d = 1, int m = 1, int y = 1900) : day(d), month(m), year(y) {}

    int getDay() const { return day; }
    int getMonth() const { return month; }
    int getYear() const { return year; }

    void setDay( int d) { day = d; }
    void setMonth( int m) { month = m; }
    void setYear( int y) { year = y; }
    
    void setDate(int d, int m, int y) {
        day = d;
        month = m;
        year = y;
    }
};

class Patient {
private:
    string patientID;
    string patientName;
    string gender;
    Date birthday;
    string address;
    string phoneNumber;

public:
    Patient(string id = "", string name = "", string g = "", Date b = Date(), string addr = "", string phone = "")
        : patientID(id), patientName(name), gender(g), birthday(b), address(addr), phoneNumber(phone) {}

    string getPatientID() const { return patientID; }
    string getPatientName() const { return patientName; }
    string getGender() const { return gender; }
    Date getBirthday() const { return birthday; }
    string getAddress() const { return address; }
    string getPhoneNumber() const { return phoneNumber; }

    void setPatientID(const string& id) { patientID = id; }
    void setPatientName(const string& name) { patientName = name; }
    void setGender(const string& g) { gender = g; }
    void setBirthday(const Date& b) { birthday = b; }
    void setAddress(const string& addr) { address = addr; }
    void setPhoneNumber(const string& phone) { phoneNumber = phone; }

    static void addPatient(Patient*& patients, int& count, int& capacity);
    static void displayPatients(Patient* patients, int count);
};

//Thêm bệnh án
void Patient::addPatient(Patient*& patients, int& count, int& capacity) {
    if (count == capacity) {
        capacity += 5;
        Patient* newPatients = new Patient[capacity];
        for (int i = 0; i < count; i++) {
            newPatients[i] = patients[i];
        }
        delete[] patients;
        patients = newPatients;
    }//thêm vị trí trong bộ nhớ động

    Patient newPatient;
    string input;
    int day, month, year;

    cout << "Nhap ten benh nhan: ";
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

    patients[count] = newPatient;
    count++;
}

//Hiển thị danh sách bệnh án
void Patient::displayPatients(Patient* patients, int count) {
    cout << left << setw(20) << "Ho va ten"
         << setw(15) << "Ngay sinh"
         << setw(10) << "Gioi tinh"
         << right<< setw(30) << "Dia chi"
         << setw(15) << "So dien thoai"
         << setw(15) << "Ma benh nhan" << endl;

    cout << setfill('-') << setw(105) << "-" << endl;
    cout << setfill(' ');

    for (int i = 0; i < count; i++) {
        cout << left << setw(20) << patients[i].getPatientName()
             << setw(2) << setfill('0') << patients[i].getBirthday().getDay() << "/"
             << setw(2) << setfill('0') << patients[i].getBirthday().getMonth() << "/"
             << setw(4) << setfill('0') << patients[i].getBirthday().getYear() << setfill(' ') << setw(11)
             << right << setw(10) << patients[i].getGender()
             << right << setw(30) << patients[i].getAddress()
             << right << setw(15) << patients[i].getPhoneNumber()
             << right<< setw(15) << patients[i].getPatientID() << endl;
        cout << setfill('-') << setw(105) << "-" << endl;
        cout << setfill(' ');
    }
}
/*vector <Users> users;
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
    
}*/




void menu() {
    int capacity = 1;
    int count = 0;
    Patient* patients = new Patient[capacity];

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
                Patient::addPatient(patients, count, capacity);
                break;
            case '2':
                system("cls");
                Patient::displayPatients(patients, count);
                break;
            case '3':
                system("cls");
                cout << "sua" << endl;
                break;
            case '4':
                system("cls");
                cout << "xoa" << endl;
                break;
            case '5':
                system("cls");
                cout << "Tim kiem" << endl;
                break;
            case '6':
                system("cls");
                cout << "sap xep" << endl;
                break;
            case '7':
                system("cls");
                cout << "Thong ke" << endl;
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

    delete[] patients;
}

int main() {
    menu();
    return 0;
}
