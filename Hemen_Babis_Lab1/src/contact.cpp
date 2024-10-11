#include "contact.h"
#include <cstring>
#include <iostream>
using namespace std;

Contact::Contact(){
  firstName=NULL;
  lastName=NULL;
  phNumber=NULL;
  emailAdd=NULL;
  groupType=0;
}

Contact::Contact(char* firstName, char* lastName, char* phNumber, 
char* emailAdd, int gp){
  this->firstName=NULL;
  this->lastName=NULL;
  this->phNumber=NULL;
  this->emailAdd=NULL;
  this->groupType=0;
  setFirstName(firstName);
  setLastName(lastName);
  setPhNumber(phNumber);
  setEmailAdd(emailAdd);
  setGroupType(gp);
}

Contact::Contact(const Contact &cpy){
  this->firstName=NULL;
  this->lastName=NULL;
  this->phNumber=NULL;
  this->emailAdd=NULL;
  this->groupType=0;
  setFirstName(cpy.firstName);
  setLastName(cpy.lastName);
  setPhNumber(cpy.phNumber);
  setEmailAdd(cpy.emailAdd);
  setGroupType(cpy.groupType);
}

Contact::~Contact(){
  if(firstName!=NULL){
    delete firstName;
  }
  if(lastName!=NULL){
    delete lastName;
  }
  if(phNumber!=NULL){
    delete phNumber;
  }
  if(emailAdd!=NULL){
    delete emailAdd;
  }
}

Contact& Contact::operator=(const Contact& cpy){
  
  if (this != &cpy){
    setFirstName(cpy.firstName);
    setLastName(cpy.lastName);
    setPhNumber(cpy.phNumber);
    setEmailAdd(cpy.emailAdd);
    setGroupType(cpy.groupType);
    }
  return *this;
}

//getters
      char* Contact::getFirstName(){
        return firstName;
      }
      char* Contact::getLastName(){
        return lastName;
      }
      char* Contact::getPhNumber(){
        return phNumber;
      }
      char* Contact::getEmailAdd(){
        return emailAdd;
      }
      int Contact::getGroupType(){
        return groupType;
      }
//setters
  void Contact::setFirstName(char* first){
    if(firstName!=NULL){
      delete firstName;
      firstName=NULL;
    }
    if(first==NULL){
      return;
    }
    int size=strlen(first)+1;
    firstName= new char[size];
    strcpy(firstName, first);
  }
  void Contact::setLastName(char* last){
    if(lastName!=NULL){
      delete lastName;
      lastName=NULL;
    }
    if(last==NULL){
      return;
    }
    int size=strlen(last)+1;
    lastName= new char[size];
    strcpy(lastName, last);
  }
  void Contact::setPhNumber(char* number){
    if(phNumber!=NULL){
      delete phNumber;
      phNumber=NULL;
    }
      if(number==NULL){
      return;
      }
    int size=strlen(number)+1;
    phNumber= new char[size];
    strcpy(phNumber, number);
  }
  void Contact::setEmailAdd(char* email){
    if(emailAdd!=NULL){
      delete emailAdd;
    emailAdd=NULL;
    }
    if(email==NULL){
      return;
    }
    int size=strlen(email)+1;
    emailAdd= new char[size];
    strcpy(emailAdd, email);
  }
  void Contact::setGroupType(int gp){
    groupType = gp;
  }

void Contact::print(){
    if(firstName==NULL){
      cout << "Contact not set." << endl;
      return;
    }
    cout << firstName << ";" 
    << lastName << ";" 
    << phNumber << ";" 
    << emailAdd << ";";
      groupName();
        cout << endl;
  }

void Contact::groupName()
{
  switch (groupType)
  {
    case 0:
      cout << "Family";
      break;
    
    case 1:
      cout << "Friend";
      break;
    
    case 2:
      cout << "Co-worker";
      break;
    
    default:
    cout << "Others";
    }
}