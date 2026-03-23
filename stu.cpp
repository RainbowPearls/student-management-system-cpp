#include<iostream>
#include<fstream>
using namespace std;

class temp{
    string rollNum,name,fName,address,search;

public:
    void addStu();
    void viewStu();
    void searchStu();
    void updateStu();
    void deleteStu();
}obj;

int main(){

    int choice;

    do{
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        cin.ignore();

        switch(choice){
            case 1: obj.addStu(); break;
            case 2: obj.viewStu(); break;
            case 3: obj.searchStu(); break;
            case 4: obj.updateStu(); break;
            case 5: obj.deleteStu(); break;
            case 6: cout<<"Exiting...\n"; break;
            default: cout<<"Invalid Choice!\n";
        }

    }while(choice != 6);

    return 0;
}


void temp::addStu(){
    ofstream file("stuData.txt", ios::app);

    if(!file){
        cout<<"File Error!\n";
        return;
    }

    cout<<"Enter Roll Number: ";
    getline(cin,rollNum);
    cout<<"Enter Name: ";
    getline(cin,name);
    cout<<"Enter Father Name: ";
    getline(cin,fName);
    cout<<"Enter Address: ";
    getline(cin,address);

    file<<rollNum<<"*"<<name<<"*"<<fName<<"*"<<address<<endl;

    file.close();
    cout<<"Student Added!\n";
}


void temp::viewStu(){
    ifstream file("stuData.txt");

    if(!file){
        cout<<"No Data Found!\n";
        return;
    }

    while(getline(file,rollNum,'*')){
        getline(file,name,'*');
        getline(file,fName,'*');
        getline(file,address,'\n');

        cout<<"\n----------------\n";
        cout<<"Roll: "<<rollNum<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Father: "<<fName<<endl;
        cout<<"Address: "<<address<<endl;
    }

    file.close();
}


void temp::searchStu(){
    cout<<"Enter Roll Number: ";
    getline(cin,search);

    ifstream file("stuData.txt");

    if(!file){
        cout<<"No Data Found!\n";
        return;
    }

    bool found=false;

    while(getline(file,rollNum,'*')){
        getline(file,name,'*');
        getline(file,fName,'*');
        getline(file,address,'\n');

        if(rollNum==search){
            cout<<"\nFound:\n";
            cout<<"Roll: "<<rollNum<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Father: "<<fName<<endl;
            cout<<"Address: "<<address<<endl;
            found=true;
        }
    }

    if(!found) cout<<"Not Found!\n";

    file.close();
}


void temp::updateStu(){
    cout<<"Enter Roll Number to Update: ";
    getline(cin,search);

    ifstream file("stuData.txt");
    ofstream tempFile("temp.txt");

    if(!file || !tempFile){
        cout<<"File Error!\n";
        return;
    }

    bool found=false;

    while(getline(file,rollNum,'*')){
        getline(file,name,'*');
        getline(file,fName,'*');
        getline(file,address,'\n');

        if(rollNum==search){
            cout<<"Enter New Data:\n";
            cout<<"Name: "; getline(cin,name);
            cout<<"Father: "; getline(cin,fName);
            cout<<"Address: "; getline(cin,address);
            found=true;
        }

        tempFile<<rollNum<<"*"<<name<<"*"<<fName<<"*"<<address<<endl;
    }

    file.close();
    tempFile.close();

    remove("stuData.txt");
    rename("temp.txt","stuData.txt");

    if(found) cout<<"Updated Successfully!\n";
    else cout<<"Record Not Found!\n";
}


void temp::deleteStu(){
    cout<<"Enter Roll Number to Delete: ";
    getline(cin,search);

    ifstream file("stuData.txt");
    ofstream tempFile("temp.txt");

    if(!file || !tempFile){
        cout<<"File Error!\n";
        return;
    }

    bool found=false;

    while(getline(file,rollNum,'*')){
        getline(file,name,'*');
        getline(file,fName,'*');
        getline(file,address,'\n');

        if(rollNum!=search){
            tempFile<<rollNum<<"*"<<name<<"*"<<fName<<"*"<<address<<endl;
        } else {
            found=true;
        }
    }

    file.close();
    tempFile.close();

    remove("stuData.txt");
    rename("temp.txt","stuData.txt");

    if(found) cout<<"Deleted Successfully!\n";
    else cout<<"Record Not Found!\n";
}
