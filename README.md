# Banking Management System

A C++ banking management system that manages user accounts, provides secure authentication, allows balance checks, and facilitates money transfers. This application is designed to simulate the core functionalities of a basic banking system using linked lists for account management.

## Features

- **User Account Management**: Create new user accounts with unique IDs and account numbers.
- **Authentication**: Verify users with a user ID and password.
- **Balance Inquiry**: Check the current balance for authenticated users.
- **Money Transfer**: Transfer funds between accounts securely, ensuring adequate balance checks.

## Installation

1. **Clone the repository**:
   - Clone the repository from GitHub.

2. **Compile the code**:
   - Use the `g++` compiler to compile the `banking_management_system.cpp` file.

3. **Run the executable**:
   - Execute the compiled program to start the banking management system.

## Usage

1. **For Existing Users**:
   - Login with a user ID and password.
   - Access options to check balance and transfer money.

2. **For New Users**:
   - Provide details to create an account, including a name, mobile number, and address.
   - Securely set a password and receive a unique user ID and account number.

## Code Structure

- **Node Struct**: Stores user data (balance, account number, password, etc.).
- **LinkedList Struct**: Manages account operations, including adding accounts, verifying credentials, and processing transactions.
- **Main Program**: Provides a menu-driven interface for user interactions.

## Technologies Used

- **Language**: C++
- **Data Structure**: Linked List

## Future Enhancements

- Add more functionalities like transaction history, interest calculations, and account deletion.
- Improve security with hashed passwords.
- Implement graphical UI for an enhanced user experience.

## Contributing

Feel free to fork the repository, make improvements, and create pull requests.
