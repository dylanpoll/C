#include <stdio.h>
#include<string.h>

#define ListSize 10

#define PAUSE system("pause")
#define CLS system("cls")

typedef struct {

int streetNo;
char streetName[200];
char city[100];
char state[100];
int zipCode;

}Address;


typedef struct {

int employeeID;
char fName[50];
char lName[50];
float baseSalary;
Address address;
}Employee;


void fillEmployeeList(Employee* employee);
void printEmployeeList(Employee* employee, int employeeInList);
void employeeMenuItem();
void operateMainMenue(Employee* employee);
void editEmployeeMenuItem();
char getUserChoice();
void addEmployee(Employee* employee, int index);
void addEmployeeAddress(Employee* employee, int index);
void increaseEmpSalary(Employee* employee, int NoOfEmployee, int salaryIncreasedBy);
void editEmployeeInfo(Employee* employee, int NoOfEmployee, int employeeID);
void lookupEmployeeInfo(Employee* employee, int NoOfEmployee, int employeeID);

void main()
{

Employee employee[ListSize];
operateMainMenue(employee);

}

 

void fillEmployeeList(Employee* employee)
{
	int i;
for (i = 0; i < ListSize; i++)
{
printf("Please insert employee %i ID\n", i+1);
scanf_s(" %i", &employee[i].employeeID);
CLS;
printf("Please insert employee %i first name\n", i+1);
scanf_s(" %[^\n]%*c", &employee[i].fName,50);
CLS;
printf("Please insert employee %i last name\n", i + 1);
scanf_s(" %[^\n]%*c", &employee[i].lName, 50);
CLS;
printf("Please insert employee %i base salary\n", i + 1);
scanf_s(" %f", &employee[i].baseSalary);
CLS;
}
/*Explanation: Here, [] is the scanset character.^ \n tells to take input until newline doesn’t get encountered.Then,
with this%* c, it reads newline characterand here used* indicates that this newline character is discarded.*/

}

void addEmployee(Employee* employee, int index) {

printf("Please insert employee ID:\n");
scanf_s(" %i", &employee[index].employeeID);
CLS;
printf("Please insert employee first name:\n");
scanf_s(" %[^\n]%*c", &employee[index].fName, 50);
CLS;
printf("Please insert employee last name:\n");
scanf_s(" %[^\n]%*c", &employee[index].lName, 50);
CLS;
printf("Please insert employee base salary:\n");
scanf_s(" %f", &employee[index].baseSalary);
CLS;
addEmployeeAddress(employee,index);
}

void addEmployeeAddress(Employee* employee, int index) {
printf("Please insert employee Adress\n**************************\n\n");
printf("Please insert street number:\n");
scanf_s(" %i", &employee[index].address.streetNo);
CLS;

printf("Please insert employee Adress\n**************************\n\n");
printf("Please insert street name:\n");
scanf_s(" %[^\n]%*c", &employee[index].address.streetName,200);
CLS;

printf("Please insert employee Adress\n**************************\n\n");
printf("Please insert city:\n");
scanf_s(" %[^\n]%*c", &employee[index].address.city,100);
CLS;

printf("Please insert employee Adress\n**************************\n\n");
printf("Please insert state:\n");
scanf_s(" %[^\n]%*c", &employee[index].address.state,100);
CLS;

printf("Please insert employee Adress\n**************************\n\n");
printf("Please insert zip code:\n");
scanf_s(" %i", &employee[index].address.zipCode);
CLS;
}

void printEmployeeList(Employee* employee, int employeeInList)
{
	int i;
CLS;
for (i = 0; i < employeeInList; i++)
{
printf("Employee %i\n", i + 1);
printf("First name : %s\n", employee[i].fName);
printf("Last name : %s\n", employee[i].lName);
printf("ID : %i\n", employee[i].employeeID);
printf("Base salary: $%f\n", employee[i].baseSalary);
printf("Address: \n");
printf("\t%i %s\n", employee[i].address.streetNo, employee[i].address.streetName);
printf("\t%s, %s %i\n", employee[i].address.city, employee[i].address.state, employee[i].address.zipCode);
printf("************************************************\n\n");
}
PAUSE;
}

void employeeMenuItem() {
CLS;
printf("\n\n\tPlease choose an option from below by");
printf("\n\t[A]dd new employee");
printf("\n\t[D]isplay employees list");
printf("\n\t[I]ncrease employees base salary");
printf("\n\t[E]dit employee information by ID");
printf("\n\t[L]ookup employee information by ID");
printf("\n\t[T]erminate the program");
printf("\n\n\tEnter your choice: ");

}

void operateMainMenue(Employee * employee)
{
char choice = 'L';
int counter = 0;
while (choice != 'T') {
employeeMenuItem();
choice = getUserChoice();

switch (choice) {
case 'A':
CLS;
addEmployee(employee, counter);
counter++;
break;
case 'D':
CLS;
printEmployeeList(employee, counter);
break;
case 'I':
CLS;
int increase=0;
printf("Please insert the amount of employees salary increase:\n");
scanf_s(" %i", &increase);
increaseEmpSalary(employee, counter,increase);
break;
case 'E':
CLS;
int ID = 0;
printf("Please insert employee ID that you want to edit:\n");
scanf_s(" %i", &ID);
editEmployeeInfo(employee, counter, ID);
break;
case 'L':
CLS;
ID = 0;
printf("Please insert employee ID that you want to lookup:\n");
scanf_s(" %i", &ID);
lookupEmployeeInfo(employee, counter, ID);
break;
case'T':
break;
default:
printf("\n\n\tInvalid Choice. Try Again.");
PAUSE;
break;
}
CLS;
}
}


void lookupEmployeeInfo(Employee* employee, int NoOfEmployee, int employeeID)
{
	int i;
CLS;
for (i = 0; i < NoOfEmployee; i++)
{
if (employee[i].employeeID == employeeID) {
printf("First name : %s\n", employee[i].fName);
printf("Last name : %s\n", employee[i].lName);
printf("ID : %i\n", employee[i].employeeID);
printf("Base salary: $%f\n", employee[i].baseSalary);
printf("Address: \n");
printf("\t%i %s\n", employee[i].address.streetNo, employee[i].address.streetName);
printf("\t%s, %s %i\n", employee[i].address.city, employee[i].address.state, employee[i].address.zipCode);
printf("************************************************\n\n");
break;
}

}
PAUSE;
}

 

void editEmployeeMenuItem() {
CLS;
printf("\n\n\tPlease select the category you want to change");
printf("\n\t[F]irst Name");
printf("\n\t[L]ast Name");
printf("\n\t[A]ddress");
printf("\n\t[S]alary");
printf("\n\t[B]ack to the main menu");
printf("\n\n\tEnter your choice: ");

}


char getUserChoice() {

char choice = ' ';
scanf_s(" %c", &choice);

return toupper(choice);

}// end getChoice()

void increaseEmpSalary(Employee* employee, int NoOfEmployee, int salaryIncreasedBy)
{
	int i;
for (i= 0; i < NoOfEmployee; i++)
{
employee[i].baseSalary += salaryIncreasedBy;

}

}

void editEmployeeInfo(Employee* employee, int NoOfEmployee, int employeeID)
{
	int i;
char choice = 'L';
while (choice != 'B')
{
editEmployeeMenuItem();
choice = getUserChoice();
for (i = 0; i < NoOfEmployee; i++)
{
if (employee[i].employeeID == employeeID)
{
switch (choice) {
case 'F':
CLS;
printf("Please insert new First name:\n");
scanf_s(" %[^\n]%*c", &employee[i].fName, 50);
CLS;
break;
case 'L':
CLS;
printf("Please insert new Last name:\n");
scanf_s(" %[^\n]%*c", &employee[i].lName, 50);
break;
case 'A':
CLS;
addEmployeeAddress(employee, i);
break;
case 'S':
CLS;
float Salary = 0;
printf("Please insert employee new Salary:\n");
scanf_s(" %f", &employee[i].baseSalary);
break;
case 'B':
break;
default:
printf("\n\n\tInvalid Choice. Try Again.");
PAUSE;
break;
}
CLS;
break;
}

}

}

CLS;
}
