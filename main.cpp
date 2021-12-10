//Library Management System applying OOP concepts
//OOP Concepts applied: Classes and Objects,Access Specifiers,Encapsulation

//Libraries
#include<iostream>
#include<conio.h>
#include<string>
#include <vector>
#include <map>

using namespace std;


map<string,int>mp;

class Book{
 private:
     string id;
     string title,author,desc;
     string date;
 public:
    void setId(string a){id=a;}
    void setTitle(string t){title=t;}
    void setAuthor(string t){author=t;}
    void setDesc(string t){desc=t;}
    void setDate(string d){date=d;}

    string getId(){return id;}
    string getTitle(){return title;}
    string getAuthor(){return author;}
    string getDesc(){return desc;}
    string getDate(){return date;}

};

//initializing functions with counter as parameter
void addBook(int counter);
void deleteBook(int counter);
void editBook(int counter);
void searchBook(int counter);
void viewAllBooks(int counter);

//counter for Book array
int counter=0;

//function for incrementing counter
void increment(int a){
	a++;
	counter=a;
}

//function for decrementing counter
void decrement(int a){
	a--;
	counter=a;
}

vector<Book>book(100);
Book temp;
string choice;

int main(){



cout<<"LIBRARY MANAGEMENT SYSTEM\n\n";
cout<<"[1]ADD BOOK\n";
cout<<"[2]DELETE BOOK\n";
cout<<"[3]EDIT BOOK\n";
cout<<"[4]SEARCH BOOK\n";
cout<<"[5]VIEW ALL BOOKS\n";
cout<<"[6]QUIT\n\n";


cout<<"ENTER CHOICE: ";
getline(cin,choice);


if(choice=="1"){
	addBook(counter); //function call
}
else if(choice=="2"){
	deleteBook(counter); //function call
}
else if(choice=="3"){
	editBook(counter); //function call
}
else if(choice=="4"){
	searchBook(counter); //function call
}
else if(choice=="5"){
	viewAllBooks(counter); //function call
}
else if(choice=="6"){
	goto quit; //function call
}
else{
    main();
}


quit:
    cout<<"your are out\n";
return 0;

}

void addBook(int counter){
string id;
string title,author,desc;
string date;

cout<<"ADD BOOK\n";


if(counter<100){
cout<<"Enter id:\n";
getline(cin,id);
mp[id]++;
cout<<"Enter Title:\n";
getline(cin,title);
mp[title]++;
cout<<"Enter Author:\n";
getline(cin,author);
mp[author]++;
cout<<"Enter desc:\n";
getline(cin,desc);
mp[desc]++;
cout<<"Enter Date:\n";
getline(cin,date);
mp[date]++;


if(mp[id]>1&&mp[title]>1 && mp[author]>1 &&mp[desc]>1 &&mp[date]>1){
    cout<<"sorry this book is exist you can't enter it\n";
    _getch();
    main();
}
book[counter].setId(id);
book[counter].setTitle(title);
book[counter].setAuthor(author);
book[counter].setDesc(desc);
book[counter].setDate(date);

cout<<"\nBOOK ADDED SUCCESSFULLY!\n\nPress any key to continue . . .";

increment(counter);
_getch();
main();
}
else{
    cout<<"YOU HAVE REACHED THE MAXIMUM NUMBER OF BOOKS TOBE ADDED!\n\nPress any key to continue . . .";
		_getch();
		main();
}
}


void deleteBook(int counter){
    string id;
    if(counter==0){
        cout<<"THERE IS NO BOOK TO DELETE!\n\nPress any key to continue . . .";
		_getch();
		main();
    }
    cout<<"Enter the id\n";
    getline(cin,id);

    for(int i=0;i<counter;i++){
        if(book[i].getId() == id){
            cout<<"\nBOOK FOUND\n\n";
			cout<<"Do you want to delete?\n[1]Yes\n[2]No\n\nEnter Choice: ";
			mp[book[i].getId()]--;
			mp[book[i].getAuthor()]--;
			mp[book[i].getDesc()]--;
			mp[book[i].getTitle()]--;
			mp[book[i].getDate()]--;
			cin>>choice;
			if(choice=="1"){
                book[i].setId("");
                book[i].setTitle("");
                book[i].setAuthor("");
                book[i].setDesc("");
                book[i].setDate("");

                for(int j=i;j<counter;j++){
                    book[j]=book[j+1];
                }
                book[book.size()-1].setId("");
                book[book.size()-1].setTitle("");
                book[book.size()-1].setAuthor("");
                book[book.size()-1].setDesc("");
                book[book.size()-1].setDate("");

                decrement(counter);
                cout<<"\nBOOK SUCCESSFULLY DELETED!\n\nPress any key to continue . . .";
				_getch();
				main();
			}else{
			main();
			}
        }
    }

    cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
	_getch();
	main();
}


void searchBook(int counter){
string id;

bool flag=false;

if(counter==0){
		cout<<"THERE IS NO BOOK TO SEARCH!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
cout<<"Enter ID: ";
getline(cin,id);

for(int i=0;i<counter;i++){
    if(book[i].getId() ==id){
        cout<<"\nBOOK FOUND!\n\n";
        cout<<"ID: "<<book[i].getId()<<endl;
        cout<<"TITLE: "<<book[i].getTitle()<<endl;
        cout<<"AUTHOR: "<<book[i].getAuthor()<<endl;
        cout<<"DESC: "<<book[i].getDesc()<<endl;
        cout<<"DATE: "<<book[i].getDate()<<endl;
        flag=true;
    }
}
if(flag){
    cout<<"\n\nPress any key to continue . . .";
    _getch();
    main();
}
else{
		cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
		_getch();
		main();
	}

}

void viewAllBooks(int counter){
	//iterating all the values on the library using book array
	cout<<"VIEW ALL BOOKS\n\n";
	for(int i=0;i<counter;i++){
		cout<<"BOOK DETAILS\n\n";
		cout<<"ID: "<<book[i].getId()<<endl;
		cout<<"TITLE: "<<book[i].getTitle()<<endl;
		cout<<"AUTHOR: "<<book[i].getAuthor()<<endl;
		cout<<"DESC: "<<book[i].getDesc()<<endl;
		cout<<"DATE: "<<book[i].getDate()<<endl<<endl;
	}
	cout<<"Press any key to continue . . .";
	_getch();
	main();
}

void editBook(int counter){
	string editID,choice;
	string id,title,author,desc,date;
	cout<<"\nEDIT BOOK\n\n";
	if(counter==0){
		cout<<"THERE IS NO BOOK TO EDIT!\n\nPress any key to continue . . .";
		_getch();
		main();
	}
	cout<<"Enter ISBN: ";
	getline(cin,editID);
	for(int i=0;i<counter;i++){
		//finding a match using for loop
		if(book[i].getId()==editID){
			cout<<"\nBOOK FOUND!\n\n";
			cout<<"ID: "<<book[i].getId()<<endl;
			cout<<"TITLE: "<<book[i].getTitle()<<endl;
			cout<<"AUTHOR: "<<book[i].getAuthor()<<endl;
			cout<<"DESC: "<<book[i].getDesc()<<endl;
			cout<<"Date: "<<book[i].getDate()<<endl;
			cout<<"\nDo you want to edit?\n[1]Yes\n[2]No\n\nEnter choice: ";
			getline(cin,choice);
			if(choice=="1"){
				//re-entering values
				cout<<"Enter Id: ";
				getline(cin,id);
				cout<<"Enter Title: ";
				getline(cin,title);
				cout<<"Enter Author: ";
				getline(cin,author);
				cout<<"Enter Desc: ";
				getline(cin,desc);
				cout<<"Enter Date: ";
				getline(cin,date);
				book[i].setId(id);
				book[i].setTitle(title);
				book[i].setAuthor(author);
				book[i].setDesc(desc);
				book[i].setDate(date);
				cout<<"\nBOOK EDITED SUCCESSFULLY!\n\nPress any key to continue . . .";
				_getch();
				editBook(counter);//function call to self
			}
			else{
				main();
			}
		}
}
	cout<<"\nBOOK NOT FOUND!\n\nPress any key to continue . . .";
	_getch();
	main();
}






