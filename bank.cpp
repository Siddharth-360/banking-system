#include <iostream>
#include <string.h>
using namespace std;
struct node
{
  int balance;
  int userno;
  int accountno;
  string password;
  string name;
  string mobileno;
  string address;
  node *next;
  node(int userno, int balance, int accountno, string password, string name, string mobileno, string address)
  {
    this->userno = userno;
    this->balance = balance;
    this->accountno = accountno;
    this->password = password;
    this->name = name;
    this->mobileno = mobileno;
    this->address = address;
    this->next = nullptr;
  }
  node(int userno, int balance, int accountno, string password, string name)
  {
    this->userno = userno;
    this->balance = balance;
    this->accountno = accountno;
    this->password = password;
    this->name = name;
    this->next = nullptr;
  }
};

struct linkedlist
{
  node *head = nullptr;

  void add(int userno, int balance, int accountno, string password, string name, string mobileno, string address)
  {
    node *newnode = new node(userno, balance, accountno, password, name, mobileno, address);
    if (head == nullptr)
    {
      head = newnode;
      return;
    }
    else
    {
      node *temp = head;
      while (temp != nullptr && temp->next != nullptr)
      {
        temp = temp->next;
      }
      temp->next = newnode;
    }
  }
  void add(int userno, int balance, int accountno, string password, string name)
  {
    node *newnode = new node(userno, balance, accountno, password, name);
    if (head == nullptr)
    {
      head = newnode;
      return;
    }
    else
    {
      node *temp = head;
      while (temp != nullptr && temp->next != nullptr)
      {
        temp = temp->next;
      }
      temp->next = newnode;
    }
  }

  bool searchuser(int userno)
  {
    node *temp = head;
    while (temp != nullptr)
    {
      if (temp->userno == userno)
      {
        return true;
      }
      temp = temp->next;
    }
    return false;
  }
  bool ckeckpassword(int userno, string password)
  {
    node *temp = head;
    while (temp != nullptr)
    {
      if (temp->userno == userno)
      {
        if (temp->password == password)
        {
          return true;
        }
      }
      temp = temp->next;
    }
    return false;
  }

  int checkbalance(int userno)
  {
    node *temp = head;
    while (temp != nullptr)
    {
      if (temp->userno == userno)
      {
        return temp->balance;
      }
      temp = temp->next;
    }
    return 0;
  }

  bool searchaccount(int acno)
  {
    node *temp = head;
    while (temp != nullptr)
    {
      if (temp->accountno == acno)
      {
        return true;
      }
      temp = temp->next;
    }
    return false;
  }
  void deductmoney(int userno, int amount)
  {
    node *temp = head;
    while (temp != nullptr)
    {
      if (temp->userno == userno)
      {
        temp->balance -= amount;
      }
      temp = temp->next;
    }
  }

  void addmoney(int acno, int amount)
  {
    node *temp = head;
    while (temp != nullptr)
    {
      if (temp->accountno == acno)
      {
        temp->balance += amount;
        return;
      }
      temp = temp->next;
    }
  }
};
string inpassword()
{
  string password;
  cout << "Enter your New password:";
  cin >> password;
  return password;
}
int main()
{
  int input, acno, userno, amount;
  string password, address, mobileno, name;
  linkedlist account;
  int user = 2000;
  int acc = 4532;
  account.add(1001, 200000, 33330, "dummy", "Siddharth");
  account.add(1002, 200000, 33333, "dummy", "Sujal");
  account.add(1003, 200000, 33335, "dummy", "Mayank");
  while (true)
  {
    cout << "PEOPLE'S BANK " << endl;
    cout << "Welcome Sir/Mam " << (char)01 << endl;
    cout << "----------------------------" << endl;
    cout << "Enter 1 for Existing User" << endl;
    cout << "Enter 2 for New User" << endl;
    cout << "Enter 0 to Exit-" << endl;
    cin >> input;
    if (input == 0)
    {
      return 0;
    }
    while (input != 1 && input != 2)
    {
      cout << "Choose a Valid Option-" << endl;
      cout << "Enter 1 for Existing User" << endl;
      cout << "Enter 2 for New User" << endl;
      cout << "Enter 0 to exit-" << endl;
      cin >> input;
      if (input == 0)
      {
        return 0;
      }
    }
    if (input == 1)
    {
      cout << "Enter your User Number:";
      cin >> userno;
      while (!account.searchuser(userno))
      {
        cout << "Incorrect User Number:" << endl;
        cout << "Enter User Number:" << endl;
        cin >> userno;
      }
      cout << "Enter Password:";
      cin >> password;
      while (!account.ckeckpassword(userno, password))
      {
        cout << "Incorrect Password:" << endl;
        cout << "Enter your Password again:";
        cin >> password;
      }
      int input1;
      cout << "\nServices-" << endl;
      cout << "Press 1 to Check Balance." << endl;
      cout << "Press 2 to Transfer Money." << endl;
      cout << "Press 0 to Exit-" << endl;
      cin >> input1;
      while (input1 != 0)
      {
        if (input1 == 1)
        {
          cout << "Your Balance is:" << account.checkbalance(userno) << endl;
        }
        if (input1 == 2)
        {
          cout << "Enter the Receivers Bank Account:";
          cin >> acno;
          int count = 0;
          while (!account.searchaccount(acno) && count < 2)
          {
            cout << "Bank Account not Found!" << endl;
            cout << "Enter Account Number again:";
            cin >> acno;
            count++;
          }
          if (count < 2)
          {
            cout << "Enter the Amount:";
            cin >> amount;
            while (account.checkbalance(userno) < amount)
            {
              int i;
              cout << "Insufficient Balance!!" << endl;
              cout << "press 1 to Enter Amount:" << endl;
              cout << "Press 0 to Exit-" << endl;
              cin >> i;
              if (i == 0)
              {
                break;
              }
              if (i == 1)
              {
                cout << "Enter the Amount:";
                cin >> amount;
              }
            }
            account.deductmoney(userno, amount);
            account.addmoney(acno, amount);
            cout << "Transaction Successful " << char(3) << endl;
          }
        }
        cout << "\nServices-" << endl;
        cout << "Press 1 to Check Balance." << endl;
        cout << "Press 2 to Transfer Money." << endl;
        cout << "Press 0 to Exit-" << endl;
        cin >> input1;
      }
    }
    else
    {
      cout << "Enter your Full Name:";
      cin.ignore();
      getline(cin, name);
      cout << "Enter your Mobile Number:";
      cin >> mobileno;
      cout << "Enter your Address:";
      cin.ignore();
      getline(cin, address);
      cout << "Your User Number is:" << user + 1 << endl;
      password = inpassword();
      while (true)
      {
        int i;
        cout << "To confirm your password Press 1" << endl;
        cout << "To Enter again Press 0" << endl;
        cin >> i;
        if (i == 1)
        {
          break;
        }
        password = inpassword();
      }
      account.add(user + 1, 0, acc + 5, password, name, mobileno, address);
      cout << "\nCongratulations " << char(3) << " your Account has been created." << endl;
      cout << "Your User Number is:" << user + 1 << endl;
      cout << "Your Account no is :" << acc + 5 << endl;
      user = user + 1;
      acc = acc + 4;
      cout << "\nPress 1 for Main Menu" << endl;
      cout << "Press 0 to Exit-" << endl;
      int i;
      cin >> i;
      if (i == 0)
      {
        return 0;
      }
    }
  }

  return 0;
}