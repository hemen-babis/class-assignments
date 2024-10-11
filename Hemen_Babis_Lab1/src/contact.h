#pragma once

class Contact{
  public:
      Contact();
  Contact(char* firstName, char* lastName, char* phNumber, 
  char* emailAdd, int gp);
  Contact(const Contact &cpy);
  ~Contact();

  Contact& operator=(const Contact& cpy);
//getters
      char* getFirstName();
      char* getLastName();
      char* getPhNumber();
      char* getEmailAdd();
      int getGroupType();
//setters
  void setFirstName(char* first);
  void setLastName(char* last);
  void setPhNumber(char* number);
  void setEmailAdd(char* email);
  void setGroupType(int gp);
  void print();

  private:
      char* firstName;
      char* lastName;
      char* phNumber;
      char* emailAdd;
      int groupType;
      void groupName();
};


