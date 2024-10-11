#include "contact.h"

struct Node{
  Contact data;
  Node* next;
};
class ContactList{
  private:
      int count;
      Node* head;
  public:
      ContactList();
      //prototypes for contact.cpp file
      void addContact();
      void listByLastName();
      void listByGroup();
      void removeContact();
      void searchByFname();
      void readInFile();
      void writeOutFile();
      void addContactToList(Contact &item);
      void groupName(int gp);
      void groupMenu();
};