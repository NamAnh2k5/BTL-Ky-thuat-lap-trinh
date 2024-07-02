#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


typedef struct {
    int day;
    int month;
    int year;
} Date;

void setDate(Date* date, int d, int m, int y) {
    date->day = d;
    date->month = m;
    date->year = y;
}

typedef struct {
    char patientID[50];
    char patientName[100];
    char gender[10];
    Date birthday;
    char address[200];
    char phoneNumber[15];
} Patient;

void setPatientID(Patient* patient, const char* id) {
    strcpy(patient->patientID, id);
}

void setPatientName(Patient* patient, const char* name) {
    strcpy(patient->patientName, name);
}

void setGender(Patient* patient, const char* gender) {
    strcpy(patient->gender, gender);
}

void setBirthday(Patient* patient, Date* date) {
    patient->birthday = *date;
}

void setAddress(Patient* patient, const char* address) {
    strcpy(patient->address, address);
}

void setPhoneNumber(Patient* patient, const char* phone) {
    strcpy(patient->phoneNumber, phone);
}

void addPatient(Patient* patients, int* patientCount) {
    Patient newPatient;
    char input[200];
    int day, month, year;
    
    printf("Nhap ma so benh nhan: ");
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = '\0';
    setPatientID(&newPatient, input);
    for (int i = 0; i < *patientCount; i++) {
        if (strcmp(patients[i].patientID, input) == 0) {
            printf("Ma benh nhan da ton tai. Vui long nhap lai.\n");
            return;
        }
    }
    
    printf("Nhap ten benh nhan: ");
    //getchar(); // clear the buffer
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove the newline character
    setPatientName(&newPatient, input);

    printf("Nhap ngay sinh:\n");
    printf("  Ngay (dd): ");
    scanf("%d", &day);
    printf("  Thang (mm): ");
    scanf("%d", &month);
    printf("  Nam (yyyy): ");
    scanf("%d", &year);
    getchar(); // clear the buffer
    Date birthdate;
    setDate(&birthdate, day, month, year);
    setBirthday(&newPatient, &birthdate);

    printf("Nhap gioi tinh: ");
    fgets(input, 10, stdin);
    input[strcspn(input, "\n")] = '\0';
    setGender(&newPatient, input);

    printf("Nhap dia chi: ");
    fgets(input, 200, stdin);
    input[strcspn(input, "\n")] = '\0';
    setAddress(&newPatient, input);

    printf("Nhap so dien thoai: ");
    fgets(input, 15, stdin);
    input[strcspn(input, "\n")] = '\0';
    setPhoneNumber(&newPatient, input);



    patients[*patientCount] = newPatient;
    (*patientCount)++;
}

void displayPatients(const Patient* patients, int patientCount) {
    printf("%-20s %-15s %-10s %-30s %-15s %-15s\n", "Ho va ten", "Ngay sinh", "Gioi tinh", " Dia chi", "So dien thoai", "Ma benh nhan");
    for (int i = 0; i < 105; i++) printf("-");
    printf("\n");

    for (int i = 0; i < patientCount; i++) {
        const Patient* p = &patients[i];
        printf("%-20s %02d/%02d/%4d   %8s \t %-30s %-15s %-15s\n",
               p->patientName, p->birthday.day, p->birthday.month, p->birthday.year,
               p->gender, p->address, p->phoneNumber, p->patientID);
        for (int j = 0; j < 105; j++) printf("-");
        printf("\n");
    }
}

void editPatientByID(Patient* patients, int patientCount) {
    printf("Nhap ID cua benh nhan ma ban muon sua:");
    char input[51];
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = '\0';
    int found=0;
    for(int i=0;i<patientCount;i++){
        if(strcmp(patients[i].patientID, input) == 0){
            found = 1; 
            Patient* p = &patients[i];
            char input[200];
            int day, month, year;
            printf("----- Thong tin benh nhan ----- \n");
            printf("Ho va ten: %s\n", patients[i].patientName);
            printf("Ngay sinh: %02d/%02d/%04d\n", patients[i].birthday.day, patients[i].birthday.month, patients[i].birthday.year);
            printf("Gioi tinh: %s\n", patients[i].gender);
            printf("Dia chi: %s\n", patients[i].address);
            printf("So dien thoai: %s\n", patients[i].phoneNumber);
            printf("Ma benh nhan: %s\n\n", patients[i].patientID);

            char choice;
            do {
                printf("Chon muc can sua:\n");
                printf("[1]. Ten benh nhan\n");
                printf("[2]. Ngay sinh\n");
                printf("[3]. Gioi tinh\n");
                printf("[4]. Dia chi\n");
                printf("[5]. So dien thoai\n");
                printf("[0]. Tro lai\n");

                choice = getchar();
                getchar(); // clear the buffer
                switch(choice) {
                    case '1': {
                        printf("Nhap ten benh nhan moi: ");
                        fgets(input, 100, stdin);
                        input[strcspn(input, "\n")] = '\0';
                        if (strlen(input) > 0) setPatientName(p, input);
                        break;
                    }
                    case '2': {
                        printf("Nhap ngay sinh (dd/mm/yyyy): ");
                        scanf("%d/%d/%d", &day, &month, &year);
                        getchar();
                        setDate(&p->birthday, day, month, year);
                        printf("Ngay sinh da duoc cap nhat.\n");
                        break;
                    }
                    case '3': {
                        printf("Nhap gioi tinh moi: ");
                        fgets(input, 10, stdin);
                        input[strcspn(input, "\n")] = '\0';
                        if (strlen(input) > 0) setGender(p, input);
                        break;
                    }
                    case '4': {
                        printf("Nhap dia chi moi: ");
                        fgets(input, 200, stdin);
                        input[strcspn(input, "\n")] = '\0';
                        if (strlen(input) > 0) setAddress(p, input);
                        break;
                    }
                    case '5': {
                        printf("Nhap so dien thoai moi: ");
                        fgets(input, 15, stdin);
                        input[strcspn(input, "\n")] = '\0';
                        if (strlen(input) > 0) setPhoneNumber(p, input);
                        break;
                    }
                    case '0': {
                        printf("Tro lai.\n");
                        break;
                    }
                    default: {
                        printf("Lua chon khong hop le. Vui long chon lai.\n");
                    }
                }
            } while (choice != '0');
            return;
        }
    }
    if(!found){
        printf("Khong tim thay benh nhan voi ID tren");
    }
}
void removePatientByID(Patient* patients, int* patientCount, const char* id) {
    int found = 0;
    for (int i = 0; i < *patientCount; i++) {
        if (strcmp(patients[i].patientID, id) == 0) {
            found = 1;
            for (int j = i; j < *patientCount - 1; j++) {
                patients[j] = patients[j + 1];
            }
            (*patientCount)--;
            printf("Da xoa benh nhan voi ma so %s\n", id);
            return;
        }
    }
    if (!found) {
        printf("Khong tim thay benh nhan voi ma so %s\n", id);
    }
}

void searchByName(const Patient* patients, int patientCount, const char* name) {
    int found = 0;
    for (int i = 0; i < patientCount; i++) {
        if (strcmp(patients[i].patientName, name) == 0) {
            found = 1;
            printf("Tim thay benh nhan voi ten %s:\n", name);
            printf("%-20s %-15s %-10s %-30s %-15s %-15s\n", "Ho va ten", "Ngay sinh", "Gioi tinh", "Dia chi", "So dien thoai", "Ma benh nhan");
            for (int i = 0; i < 105; i++) printf("-");
            printf("\n");
            printf("%-20s %02d/%02d/%4d   %-10s %-30s %-15s %-15s\n",
                   patients[i].patientName, patients[i].birthday.day, patients[i].birthday.month, patients[i].birthday.year,
                   patients[i].gender, patients[i].address, patients[i].phoneNumber, patients[i].patientID);
            for (int i = 0; i < 105; i++) printf("-");
            printf("\n");
        }
    }
    if (!found) {
        printf("Khong tim thay benh nhan voi ten %s\n", name);
    }
}

void searchByID(const Patient* patients, int patientCount, const char* ID) {
    int found = 0;
    for (int i = 0; i < patientCount; i++) {
        if (strcmp(patients[i].patientID, ID) == 0) {
            found = 1;
            printf("Tim thay benh nhan voi ID %s:\n", ID);
            printf("%-20s %-15s %-10s %-30s %-15s %-15s\n", "Ho va ten", "Ngay sinh", "Gioi tinh", "Dia chi", "So dien thoai", "Ma benh nhan");
            for (int i = 0; i < 105; i++) printf("-");
            printf("\n");
            printf("%-20s %02d/%02d/%4d   %-10s %-30s %-15s %-15s\n",
                   patients[i].patientName, patients[i].birthday.day, patients[i].birthday.month, patients[i].birthday.year,
                   patients[i].gender, patients[i].address, patients[i].phoneNumber, patients[i].patientID);
            for (int i = 0; i < 105; i++) printf("-");
            printf("\n");
        }
    }
    if (!found) {
        printf("Khong tim thay benh nhan voi ID %s\n", ID);
    }
}
// Hàm chuyển tên đầy đủ thành tên cuối cùng
void getLastName(const char* fullName, char* lastName) {
    const char* lastSpace = strrchr(fullName, ' ');
    if (lastSpace) {
        strcpy(lastName, lastSpace + 1);
    } else {
        strcpy(lastName, fullName);
    }
}

// Hàm so sánh cho qsort
int comparePatientsByName(const void* a, const void* b) {
    const Patient* patientA = (const Patient*)a;
    const Patient* patientB = (const Patient*)b;
    
    char lastNameA[100], lastNameB[100];
    getLastName(patientA->patientName, lastNameA);
    getLastName(patientB->patientName, lastNameB);
    
    // Chuyển tên thành chữ thường để so sánh
    for (char* p = lastNameA; *p; ++p) *p = tolower(*p);
    for (char* p = lastNameB; *p; ++p) *p = tolower(*p);
    
    return strcmp(lastNameA, lastNameB);
}

// Hàm sắp xếp bệnh nhân theo tên
void sortPatientsByName(Patient* patients, int patientCount) {
    qsort(patients, patientCount, sizeof(Patient), comparePatientsByName);
}
int comparePatientsByID(const void* a, const void* b) {
    const Patient* patientA = (const Patient*)a;
    const Patient* patientB = (const Patient*)b;
    return strcmp(patientA->patientID, patientB->patientID);
}
// Hàm sắp xếp bệnh nhân theo ID
void sortPatientsByID(Patient* patients, int patientCount) {
    qsort(patients, patientCount, sizeof(Patient), comparePatientsByID);
}

int main() {
    Patient patients[100];
    int patientCount = 0;
    int choice;
    char input[100];
    int year;

    while (1) {        
        printf("-------------------------------------------\n");
        printf("=============QUAN LI BENH NHAN=============\n");
        printf("-------------------------------------------\n");
        printf("[1]. Them thong tin benh nhan.\n");
        printf("[2]. Hien thi danh sach benh nhan.\n");
        printf("[3]. Sua thong tin benh nhan.\n");
        printf("[4]. Xoa thong tin benh nhan.\n");
        printf("[5]. Tim kiem ho so benh nhan.\n");
        printf("[6]. Sap xep ho so benh nhan.\n");
        printf("[7]. Thong ke ho so benh nhan.\n");
        printf("[0]. Thoat chuong trinh\n");
        printf("-------------------------------------------\n");
        printf("Nhap lua chon cua ban: ");

        scanf("%d", &choice);
        getchar(); // clear the buffer


        switch (choice) {
            case 1:
                system("cls");
                addPatient(patients, &patientCount);
                break;
            case 2:
                system("cls");
                displayPatients(patients, patientCount);
                break;
            case 3:
                editPatientByID(patients,patientCount);
                break;
            case 4:
                printf("Nhap ID benh nhan can xoa: ");
                fgets(input, 50, stdin);
                input[strcspn(input, "\n")] = '\0';
                removePatientByID(patients, &patientCount, input);
                break;
            case 5:
                system("cls");
                char searchOption;
                printf("Tim kiem theo (1) ID hoac (2) Ten? \n");
                scanf("%c",&searchOption);
                switch(searchOption) {
                    case '1':
                        printf("Nhap ID benh nhan can tim: ");
                        getchar(); //clear buffer
                        fgets(input, 100, stdin);
                        input[strcspn(input, "\n")] = '\0';
                        searchByID(patients, patientCount, input);
                        break;
                    case '2':
                        printf("Nhap ten benh nhan can tim: ");
                        getchar(); //clear buffer
                        fgets(input, 100, stdin);
                        input[strcspn(input, "\n")] = '\0';
                        searchByName(patients, patientCount, input);
                        break;
                    default:
                        printf("Khong tim thay chuc nang phu hop!\n");
                        break;
                }
                break;
            case 6:
                system("cls");
                int sortOption;
                printf("Chon kieu sap xep (1: Ten, 2: ID): ");
                scanf("%d", &sortOption);
                getchar(); // clear the buffer
                if (sortOption == 1) {
                    sortPatientsByName(patients, patientCount);
                } else if (sortOption == 2) {
                    sortPatientsByID(patients, patientCount);
                } else {
                    printf("Lua chon khong hop le.\n");
                }
                break;
                
            case 0:
                printf("Thoat chuong trinh.\n");
                return 0;
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    }

    return 0;
}
