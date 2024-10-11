#include "main.h"
#include "contact.h"
#include "contactlist.h"

ContactList::ContactList(){
  head = NULL; //checking if the list is empty
  count = 0;
}
void ContactList::addContact()
{
  int gp;
  char firstName[51];
  char lastName[51];
  char phNumber[51];
  char emailAdd[51];
  cout << "Enter the first Name: ";
  cin.getline(firstName, 50);
  cout << "Enter Last Name: ";
  cin.getline(lastName, 50);  
  cout << "Enter Phone Number: ";
  cin.getline(phNumber, 50);  
  cout << "Enter Email Address: ";
  cin.getline(emailAdd, 50);
  cout << "Enter Group: \n";
  groupMenu();
  cin >> gp;
  cin.ignore(50,'\n');
  Contact item(firstName, lastName, phNumber,
  emailAdd, gp);
  addContactToList(item);
}

void ContactList::groupMenu()
{
  cout << "0 Family" << endl;
  cout << "1 Friend" << endl;
  cout << "2 Co-worker" << endl;
  cout << "3 Others" << endl;
}


void ContactList::listByLastName(){
  Node* curr = head;
  while(curr){ //testing for curr being not null
    curr->data.print();
    curr = curr->next;
  }
}

void ContactList::listByGroup(){
  int ch;
  cout << "Enter group number: ";
  groupMenu();
  cin >> ch;
  Node* curr = head;
    while(curr){
      if(curr->data.getGroupType() == ch){
        curr->data.print();
      }
    curr = curr->next;
    }
    /*for(int j=0; j<count; j++){
      if(list[j].getGroupType() == ch){
        list[j].print();
      }
    }*/
    
}
void ContactList::removeContact(){
  char email[51];
  bool found = false;
  int idx = 0;
  cout << "Enter your email: ";
  cin.getline(email,50);
  Node* curr = head;
  Node* prev = NULL;
  while(curr){
    if(strcmp(email,curr->data.getEmailAdd())==0){
      if(!prev){
        head = curr->next;
      } else{
        prev->next = curr->next;
      }
      delete curr;
      return;
    } 
    prev = curr;
    curr = curr->next;
  }
  cout << "Not found." << endl;
}

void ContactList::searchByFname()
{
  char fname[51];
  bool found = false;
  int idx=0;
  cout << "Enter your first name: ";
  cin >> fname;
  Node* curr = head;
  while(curr){
    if(strcmp(fname,curr->data.getFirstName())==0){
      curr->data.print();
      return;
    }
  curr = curr->next;
  }
  cout << "Name not found in contact list \n";
  
}

void ContactList::readInFile()
{
  int gp;
  char firstName[51];
  char lastName[51];
  char phNumber[51];
  char emailAdd[51];
	
	
	ifstream infile(INFILE);
	
	if(!infile) // check to see if file is open
	{
		cout << "unable to open file of readings" << endl;
		return;
	}
	
	
	while( infile.getline(firstName, 51, ';') )
	{
    infile.getline(lastName, 51, ';');
    infile.getline(phNumber, 51, ';');
    infile.getline(emailAdd, 51, ';');
    
		infile >> gp;
		infile.ignore(10,'\n');
		
    Contact item(firstName, lastName, phNumber,
  emailAdd, gp);
    addContactToList(item);
		 
  }
	 
  infile.close();
}

/* Purpose:  Writes out the array to a give file.
 *  The name is set as a const in the main.h file.
 * Parameters: the list of readings (array of structs)
 *                     and the count as reference
 * Return:  none
 */
 
void ContactList::writeOutFile()
{
	ofstream outfile(OUTFILE);
	cout << "Contacts written to file!" << endl;
	if(!outfile)
	{
		cout << "can't open file for output" << endl;
		return;
	}

  Node* curr = head;
  while(curr){
    outfile << curr->data.getFirstName() << ";";
		outfile << curr->data.getLastName() << ";";
		outfile << curr->data.getPhNumber() << ";";
    outfile << curr->data.getEmailAdd() << ";";
    outfile << curr->data.getGroupType() << endl;

    curr = curr->next;
  }
	
	outfile.close();

}

void ContactList::addContactToList(Contact &item)
{
  Node* newNode = new Node; //create a space for a larger node
  newNode->data=item;
  newNode->next=NULL;
  if(!head){
    head = newNode;
    return;
  }
  Node* curr = head;
  Node* prev = NULL;
  while(curr){
    if(strcmp(item.getLastName(), curr->data.getLastName()) < 0){
      newNode->next=curr;
      if(!prev){
        head = newNode;
      } else{
        prev->next = newNode;
      }
      return;
    }
    prev = curr;
    curr = curr->next;
  }
  prev->next = newNode;  
    
}

