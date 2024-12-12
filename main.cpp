#include<iostream>
#include<fstream>
#include<cstdlib>
#include<stdlib.h>
#include<conio.h>

//classes
class student{
    private:
        //
        std::string name, Adm_no, course, address, email_id, contact_no;
    public:
        void menu();
        void insert();

};

void student::menu()    //simple window menu function
// display menu
{
    menustart:
    int choice;
    char x;
    // char* ptr_x = &x;
    system("cls");

    std::cout<< "\t\t\t------------------------------------------"<<std::endl;
    std::cout<< "\t\t\t|        STUDENT MANAGMENT SYSTEM        |"<<std::endl;
    std::cout<< "\t\t\t------------------------------------------"<<std::endl; std::cout<<"\n";
    //choices offered
    std::cout<<"\t\t\t 1. Enter New Record"<<std::endl;
    std::cout<<"\t\t\t 2. Display Record"<<std::endl;
    std::cout<<"\t\t\t 3. Modify Record"<<std::endl;
    std::cout<<"\t\t\t 4. Search New Record"<<std::endl;
    std::cout<<"\t\t\t 5. Delete New Record"<<std::endl;
    std::cout<<"\t\t\t 6. Exit"<<std::endl;

    std::cout<< "\t\t\t------------------------------------------"<<std::endl;
    std::cout<< "\t\t\t|  Choose an Option [1, 2, 3, 4, 5, 6]   |"<<std::endl;
    std::cout<< "\t\t\t------------------------------------------"<<std::endl;
    std::cout<<"Enter choice: "<<std::endl;
    std::cin>>choice;

    switch(choice){
        case 1:
            do{
                insert();
                std::cout<<"\n\t\t\t Add Another Student (Y,N): ";
                std::cin>>x;
                // std::cout<< *ptr_x;
            }while (x=='y' || x=='Y');
            break;
        case 6:
            exit(0);
        default:
            std::cout<< "\n\t\t Invalid choice ... Please try again"<<std::endl;
            break;
    }
    getch();
    goto menustart;
};

void student::insert()  //function to add student details
{
    system("cls"); //clear console screen
    std::fstream file;

    std::cout<<"\n\t\t --------------------------------------------------------------";
    std::cout<<"\n\t\t --------------------Add Student Details-----------------------"<<std::endl;
    //input new details
    std::cout<<"\t\t\t Enter name: ";
    std::cin>>name;
    std::cout<<"\t\t\t Enter Adm_no: ";
    std::cin>>Adm_no;
    std::cout<<"\t\t\t Enter Course: ";
    std::cin>>course;
    std::cout<<"\t\t\t Enter Address: ";
    std::cin>>address;
    std::cout<<"\t\t\t Enter Email: ";
    std::cin>>email_id;
    std::cout<<"\t\t\t Enter Contact: ";
    std::cin>>contact_no;
    // file system to store information
    file.open("studentRecords.txt", std::ios::app | std::ios::out);
    file<<" "<< name<< " "<<Adm_no<<" "<<course<<" "<<address<<" "<<email_id<<" "<<contact_no<<"\n";
    file.close();

};

int main(){

    student project;
    project.menu();

    return(0);
}
