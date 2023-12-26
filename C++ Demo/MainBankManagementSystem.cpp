#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
using namespace std;

struct Account
{
	int acc_no;
	char name[50];
	int deposit;
	char type;
};

void write_account();
void display_all();
void display_specific(int);
void modify_acc(int);
void delet_acc(int);
void deposit_withdraw(int, int);
void intro();

Account ac;

int main(){
	system("color 5E");
	char ch;
	int num;
	intro();
	system("cls");

	do
	{
		system("cls");
		cout<<"\n\n\n\tMAIN MENU";
		cout<<"\n\n\t1. NEW ACCOUNT";
		cout<<"\n\n\t2. DEPOSIT AMOUNT";
		cout<<"\n\n\t3. WITHDRAW AMOUNT";
		cout<<"\n\n\t4. BALANCE ENQUIRY";
		cout<<"\n\n\t5. ALL ACCOUNT HOLDERS LIST";
		cout<<"\n\n\t6. DELETE AN ACCOUNT";
		cout<<"\n\n\t7. MODIFY AN ACCOUNT";
		cout<<"\n\n\t8. EXIT";
		cout<<"\n\n\tGive me you choise (1-8) : ";
		cin>>ch;

		switch(ch)
		{
			case '1' :
				write_account();
				break;

			case '2' : 
				cout<<"\n\n\tEnter Account number of depositer : ";
				cin>>num;
				deposit_withdraw(num, 1);
				break;

			case '3' :
				cout<<"\n\n\tEnter withdrawal Account : ";
				cin>>num;
				deposit_withdraw(num, 2);
				break;

			case '4' :
				cout<<"\n\n\tEnter Accont number : ";
				cin>>num;
				display_specific(num);
				break;

			case '5' :
				display_all();
				break;

			case '6' :
				cout<<"\n\n\tEnter Accont number : ";
				cin>>num;
				delet_acc(num);
				break;

			case '7' :
				cout<<"\n\n\tEnter Account number : ";
				cin>>num;
				modify_acc(num);
				break;

			case '8' :
				cout<<"\n\n\tThank you for using our Bank!!";
				break;

			default:
				cout<<"\a\a\a\a\a\a\a\a\a\a\a";
		}
		
		cin.ignore();
		cin.get();

	}while(ch != '8');

	return 0;
}

void intro(){
	cout<<"*******************************************************\n*";
	cout<<"\n*\tPlease create a bank account that used to deposit\t\n*";
	cout<<"\tStay and Work with us!!!                              \n*";
	cout<<"\n*\n*******************************************************\n";
	cout<<endl;
	cout<<"\tPress any key to get started!! : ";
	cin.get();
}
void write_account(){
	system("cls");
	ofstream accountfile;
	accountfile.open("account_data.dat", ios::app|ios::binary);
	if(accountfile.fail()){
		cerr<<"There is error in oppening file!";
		exit(1);
	}
	cout<<"\nEnter account Number : ";
	cin>>ac.acc_no;
	cout<<"\nEnter the name of account holder : ";
	cin.ignore();
	cin.getline(ac.name, 50);
	cout<<"\nEnter Type of the account (c/s) : ";
	cin>>ac.type;
	ac.type = toupper(ac.type);
	do{
	cout<<"\nEnter the Initial amount (x > 24.99 for saving and x > 99.99 for transfer) : ";
	cin>>ac.deposit;
	}while(ac.deposit<25);
	cout<<"\n\nAccount created succssesfully;\n";
	cout<<"\n\n\tPress any key to ger started!! : ";
	accountfile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
	accountfile.close();
} 

void deposit_withdraw(int num, int option){

	system("cls");
	int amount;
	bool found = false;
	Account ac;
	fstream accountfile;
	accountfile.open("account_data.dat", ios::out|ios::in|ios::binary);
	if(!accountfile){
		cout<<"Error in openning file";
		return;
	}
	while(!accountfile.eof()&&found==false){
		system("cls");
		accountfile.read(reinterpret_cast<char *> (&ac), sizeof(Account));
		if(ac.acc_no==num){
			cout<<"\nAccount Number : "<<ac.acc_no;
			cout<<"\nAccount Holder name : "<<ac.name;
			cout<<"\nType of Account : "<<ac.type;
			cout<<"\nBalance Amount : "<<ac.deposit;
			cout<<endl<<endl;

			if (option ==1){
				cout<<"\n\n\t To deposit amount ";
				cout<<"\n\nEnter the amount to be deposited : ";
				cin>>amount;
				ac.deposit += amount;
			}
			if (option==2){
				cout<<"\n\n\t To withdraw amount ";
				cout<<"\n\nEnter the amount to be withdraw : ";
				cin>>amount;
				int balance = ac.deposit - amount;
				if((balance<50&&ac.type=='S')||(balance<70&&ac.type=='C')){
					cout<<"INSUFFICIENT BALANCE";
				}
				else
					ac.deposit -= amount;
			}

			int position = (-1)*static_cast<int>(sizeof(ac));
			accountfile.seekp(position, ios::cur);
			accountfile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
			cout<<"\n\tAccount updated successfully!!";
			found = true;

		}
	}
	accountfile.close();
	if(found == false){
		cout<<"Record doesn't found! ";
	}
}

void display_specific(int num){
	system("cls");
	Account ac;
	bool flag = false;
	fstream accountfile;
	accountfile.open("account_data.dat", ios::binary|ios::in);
	if(!accountfile){
		cout<<"Error in openning file!";
		return;
	}
	cout<<"\n\n\tBalance Details\n";
	while(accountfile.read(reinterpret_cast<char *> (&ac), sizeof(Account))){
		if(ac.acc_no==num){
			cout<<"\nAccount Number : "<<ac.acc_no;
			cout<<"\nAccount Holder Name : "<<ac.name;
			cout<<"\nType of Account : "<<ac.type;
			cout<<"\nBalance amount : "<<ac.deposit;
			flag = true;
			cout<<"\n\n\tPress any key to get out!! : ";
		}
	}
	accountfile.close();
	if(flag==false){
		cout<<"\n\nAccount number does not exist.";
		cout<<"\n\tPress any key to get out!! : ";
	}

}

void display_all(){
	system("cls");
	Account ac;
	fstream accountfile;
	accountfile.open("account_data.dat", ios::binary|ios::in);
	if(!accountfile){
		cout<<"Error in accessing file.";
		exit(1);
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"\t========================================================\n";
	cout<<"\tAccount No."<<setw(10)<<"Name"<<setw(15)<<"Acc. Type"<<setw(20)<<"Balance\n";
	cout<<"\t========================================================\n";
	while(accountfile.read(reinterpret_cast<char *> (&ac), sizeof(Account))){
		cout<<"\t"<<ac.acc_no<<setw(20)<<ac.name<<setw(15)<<ac.type<<setw(15)<<ac.deposit;
		cout<<endl;
	}
	accountfile.close();
	cout<<"\n\n\tPress any key to get back... : ";
}

void delet_acc(int num){
	system("cls");
	Account ac;
	ifstream infile;
	ofstream outfile;
	infile.open("account_data.dat", ios::binary);
	if(!infile){
		cout<<"Error in accessing file!! Press any key to get out... : ";
		return;
	}
	outfile.open("temp.dat", ios::binary);
	infile.seekg(0, ios::beg);
	
	while(infile.read(reinterpret_cast<char *> (&ac), sizeof(Account))){
		if(ac.acc_no!=num){
			outfile.write(reinterpret_cast<char *> (&ac), sizeof(Account));
		}
	}

	infile.close();
	outfile.close();
	remove("account_data.dat");
	rename("temp.dat", "account_data.dat");
	cout<<"\n\n\tRecord Deleted!!\n";
	cout<<"\tPress any key to get out... : ";
}

void modify_acc(int num){
	system("cls");
	bool found = false;
	Account ac;
	fstream file;
	file.open("account_data.dat", ios::binary|ios::in|ios::out);
	if(!file){
		cout<<"File does not exist!!  Press any key to get out... : ";
		return;
	}
	while(!file.eof()&&found==false){
		file.read(reinterpret_cast<char *> (&ac), sizeof(Account));
		if(ac.acc_no==num){
			cout<<"\nAccount Number : "<<ac.acc_no;
			cout<<"\nAccount Holder Name : "<<ac.name;
			cout<<"\nType of Account : "<<ac.type;
			cout<<"\nBalance amount : "<<ac.deposit<<endl<<endl;

			cout<<"\n\nEnter the New details of Account!\n";
			cout<<"\nModify Account Number : ";cin>>ac.acc_no;
			cout<<"\nMOdify Acount Holder Name : ";
			cin.ignore();
			cin.getline(ac.name, 50);
			cout<<"\nModify Types of Account : ";
			cin>>ac.type;
			ac.type=toupper(ac.type);
			cout<<"\nDeposit some amount of money : ";cin>>ac.deposit;

			int position = (-1)*static_cast<int>(sizeof(Account));
			file.seekp(position, ios::cur);
			file.write(reinterpret_cast<char *> (&ac), sizeof(Account));
			cout<<"\n\n\tRecord Updated Successfully!!\n";
			found = true;
			cout<<"\tPress any key to get out... : ";

		}
	}
}