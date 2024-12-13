#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h>

// classes
class student
{
private:
    //
    std::string name, Adm_no, course, address, email_id, contact_no;

public:
    void menu();
    void insert();
    void display();
    void modify();
    void search();
    void deleted();
};

void student::menu() // simple window menu function
{                    // display menu
menustart:
    int choice;
    char x;
    // char* ptr_x = &x;
    system("cls");

    std::cout << "\t\t\t------------------------------------------" << std::endl;
    std::cout << "\t\t\t|        STUDENT MANAGMENT SYSTEM        |" << std::endl;
    std::cout << "\t\t\t------------------------------------------" << std::endl;
    std::cout << "\n";
    // choices offered
    std::cout << "\t\t\t 1. Enter New Record" << std::endl;
    std::cout << "\t\t\t 2. Display Record" << std::endl;
    std::cout << "\t\t\t 3. Modify Record" << std::endl;
    std::cout << "\t\t\t 4. Search Record" << std::endl;
    std::cout << "\t\t\t 5. Delete Record" << std::endl;
    std::cout << "\t\t\t 6. Exit" << std::endl;

    std::cout << "\t\t\t------------------------------------------" << std::endl;
    std::cout << "\t\t\t|  Choose an Option [1, 2, 3, 4, 5, 6]   |" << std::endl;
    std::cout << "\t\t\t------------------------------------------" << std::endl;
    std::cout << "Enter choice: " << std::endl;
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        do
        {
            insert();
            std::cout << "\n\t\t\t Add Another Student (Y,N): ";
            std::cin >> x;
            // std::cout<< *ptr_x;
        } while (x == 'y' || x == 'Y');
        break;
    case 2:
        display();
        break;
    case 3:
        modify();
        break;
    case 4:
        search();
        break;
    case 5:
        deleted();
        break;
    case 6:
        exit(0);
    default:
        std::cout << "\n\t\t Invalid choice ... Please try again" << std::endl;
        break;
    }
    getch();
    goto menustart;
};

void student::insert() // function to add student details
{
    system("cls"); // clear console screen
    std::fstream file;

    std::cout << "\n\t\t --------------------------------------------------------------";
    std::cout << "\n\t\t --------------------Add Student Details-----------------------" << std::endl;
    // input new details
    std::cout << "\t\t\t Enter name: ";
    std::cin >> name;
    std::cout << "\t\t\t Enter Adm_no: ";
    std::cin >> Adm_no;
    std::cout << "\t\t\t Enter Course: ";
    std::cin >> course;
    std::cout << "\t\t\t Enter Address: ";
    std::cin >> address;
    std::cout << "\t\t\t Enter Email: ";
    std::cin >> email_id;
    std::cout << "\t\t\t Enter Contact: ";
    std::cin >> contact_no;
    // file system to store information
    file.open("studentRecords.txt", std::ios::app | std::ios::out);
    file << " " << name << " " << Adm_no << " " << course << " " << address << " " << email_id << " " << contact_no << "\n";
    file.close();
};

// function to display records
void student::display()
{
    system("cls");
    std::fstream file;
    int total = 0;
    // int* ptotal = &total;
    std::cout << "\n\t\t --------------------------------------------------------------";
    std::cout << "\n\t\t --------------------Display Student Records--------------------" << std::endl;
    // opem file with records
    file.open("studentRecords.txt", std::ios::in);

    if (!file)
    {
        std::cout << "\n\t\t\tThere is no data Available ...";
        file.close();
    }
    else
    {
        file >> name >> Adm_no >> course >> address >> email_id >> contact_no;
        // file formating
        while (!file.eof())
        {
            std::cout << "\n\n\t\t\t Student No. " << total++ << std::endl;
            std::cout << "\t\t\t Student Name. " << name << std::endl;
            std::cout << "\t\t\t Student Adm_no. " << Adm_no << std::endl;
            std::cout << "\t\t\t Student Course. " << course << std::endl;
            std::cout << "\t\t\t Student address. " << address << std::endl;
            std::cout << "\t\t\t Student email_id. " << email_id << std::endl;
            std::cout << "\t\t\t Student Contact. " << contact_no << std::endl;
            file >> name >> Adm_no >> course >> address >> email_id >> contact_no;
        }
        if (total == 0)
        {
            std::cout << "\n\t\t\tThere is no data Available ...";
        }
    }
    file.close();
};

void student::modify() //modify details by overwriting files and replacing
{
    system("cls");
    std::fstream file, file1;
    std::string adm_no;
    int found = 0;
    std::cout << "\n\t\t --------------------------------------------------------------";
    std::cout << "\n\t\t --------------------Modify Student Records--------------------" << std::endl;
    file.open("studentRecords.txt", std::ios::in);
    if (!file)
    {
        std::cout << "\n\t\t\tThere is no data Available ...";
        file.close();
    }
    else
    {
        std::cout << "\n Enter Admission number of student you want to modify: ";
        std::cin >> adm_no;
        file1.open("Records.txt", std::ios::app | std::ios::out);
        file >> name >> Adm_no >> course >> address >> email_id >> contact_no;
        while (!file.eof())
        {
            if (adm_no != Adm_no)
            {
                file1 << " " << name << " " << Adm_no << " " << course << " " << address << " " << email_id << " " << contact_no << "\n";
            }
            else
            {
                std::cout << "\t\t\t Enter name: ";
                std::cin >> name;
                std::cout << "\t\t\t Enter Adm_no: ";
                std::cin >> Adm_no;
                std::cout << "\t\t\t Enter Course: ";
                std::cin >> course;
                std::cout << "\t\t\t Enter Address: ";
                std::cin >> address;
                std::cout << "\t\t\t Enter Email: ";
                std::cin >> email_id;
                std::cout << "\t\t\t Enter Contact: ";
                std::cin >> contact_no;
                file1 << " " << name << " " << Adm_no << " " << course << " " << address << " " << email_id << " " << contact_no << "\n";
                found++;
            }
        file >> name >> Adm_no >> course >> address >> email_id >> contact_no;
        if (found == 0)
        {
            std::cout << "\n\t\t\tStudent Admission No. not found ...";
        }
        }
        file1.close();
        file.close();
        remove("studentRecords.txt");
        rename("Records.txt", "studentRecords.txt");
    }
};


void student::search() //search for record by comparing admission numbers in the file
{
    system("cls");
    std::fstream file;
    int found=0;
    file.open("studentRecords.txt", std::ios::in);
    if (!file)
    {
        std::cout << "\n\t\t --------------------------------------------------------------";
        std::cout << "\n\t\t --------------------Modify Search Records---------------------" << std::endl;
        std::cout<< "\n\t\t\t No Data present ...";
    }else
    {
        std::string adm_no_temp;
        std::cout << "\n\t\t --------------------------------------------------------------";
        std::cout << "\n\t\t --------------------Modify Student Records--------------------" << std::endl;
        std::cout<< "\n Enter Admission number of Student you want to seach: ";
        std::cin>>adm_no_temp;
        file >> name >> Adm_no >> course >> address >> email_id >> contact_no;
        while(!file.eof())
        {
            if (adm_no_temp == Adm_no)
            {
                std::cout << "\n\t\t\t Student Name. " << name << std::endl;
                std::cout << "\t\t\t Student Adm_no. " << Adm_no << std::endl;
                std::cout << "\t\t\t Student Course. " << course << std::endl;
                std::cout << "\t\t\t Student address. " << address << std::endl;
                std::cout << "\t\t\t Student email_id. " << email_id << std::endl;
                std::cout << "\t\t\t Student Contact. " << contact_no << std::endl;
                found++;
            }
        file >> name >> Adm_no >> course >> address >> email_id >> contact_no;
        }
        if (found ==0)
        {
            std::cout<<"\n\t\t\t Information not found Confirm the admission No and try again!";
        }
        file.close();
    }
};


void student::deleted()
{
    system("cls");
    std::fstream file, file1;
    std::string tempA;
    int found =0;
    std::cout << "\n\t\t --------------------------------------------------------------";
    std::cout << "\n\t\t --------------------Delete Student Details--------------------" << std::endl;
    file.open("studentRecords.txt", std::ios::in);
    if (!file)
    {
        std::cout<<"\n\t\t\tNo Data present ...";
    }else 
    {
        std::cout<<"\n\t\t\t Enter Admission No. of student you want to delete: ";
        std::cin>>tempA;
        file1.open("Records.txt", std::ios::app | std::ios::out);
        file >> name >> Adm_no >> course >> address >> email_id >> contact_no;
        while(!file.eof())
        {
            if (tempA != Adm_no)
            { //copy the data
                file1 << " " << name << " " << Adm_no << " " << course << " " << address << " " << email_id << " " << contact_no << "\n";
            }else
            {
                found++;
                std::cout<<"\n\t\t\t Student Detaials deleted successfully ...";
            }
            file >> name >> Adm_no >> course >> address >> email_id >> contact_no;
        }
        if (found==0)
        {
            std::cout<<"\n\t\t\t Student details not found, Confirm the Admission No. ...";
        }
        file1.close();
        file.close();
        remove("studentRecords.txt");
        rename("Records.txt", "studentRecords.txt");
    }

};

int main()
{

    student project;
    project.menu();

    return (0);
}
