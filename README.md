AVON DHABA
A C++ console application that allows an administrator to manage products in a database and buyers to purchase products.

Table of Contents
Description
Features
Installation
Usage
License
Contributing
Description
AVON DHABA is a simple command-line based shopping application. It provides functionalities for an administrator to add, edit, and delete products, and for buyers to view the list of products and purchase them.

Features
Administrator Menu

Login with email and password
Add new products
Edit existing products
Remove products
View product list
Buyer Menu

View product list
Purchase products and generate a receipt
Installation
Clone the repository

sh
Copy code
git clone https://github.com/your-username/avon-dhaba.git
cd avon-dhaba
Compile the code

Make sure you have a C++ compiler installed. Then, compile the code using:

sh
Copy code
g++ -o avon_dhaba main.cpp
Run the application

sh
Copy code
./avon_dhaba
Usage
Menu Navigation

On running the application, you will see the main menu with options for Administrator and Buyer.
Select 1 for Administrator or 2 for Buyer.
Administrator Login

Enter email: t.sahil@iitg.ac.in
Enter password: 123456789
Administrator Functionalities

Add, edit, or remove products using the options provided in the Administrator menu.
Products are stored in a file named database.txt.
Buyer Functionalities

View the list of available products.
Purchase products by entering the product code and quantity.
A receipt will be generated with the total amount including discounts.
License
This project is licensed under the MIT License.

Contributing
Contributions are welcome! Please open an issue or submit a pull request for any changes or enhancements.
