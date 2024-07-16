Avon Dhaba Shopping Application

Overview

This C++ application is a basic console-based shopping system called "Avon Dhaba". It allows administrators to manage products by adding, editing, or removing items from a product list stored in a file. Buyers can view available products and generate receipts for their purchases.

Features

 1.Administrator
 2.Login Authentication: Access to the administrator menu requires email and password validation.
3.Add Product: Administrators can add new products to the inventory.
4.Edit Product: Modify details of existing products.
5.Remove Product: Delete products from the inventory.
6.Buyer
7.View Products: Buyers can view the list of available products.
8.Purchase Products: Buyers can add products to their cart and generate a receipt with the total amount and discount applied.

Project Structure
-Class shopping: Contains private member variables for product details and public member functions for the main functionalities.

Private Members:
- int pcode: Product code.
- float price: Product price.
- float dis: Product discount.
- string pname: Product name.

Public Member Functions:

- void menu(): Displays the main menu and handles user choice.
- void administrator(): Displays the administrator menu.
- void buyer(): Displays the buyer menu.
- void add(): Adds a new product to the inventory
- void edit(): Edits an existing product in the inventory.
- void rem(): Removes a product from the inventory.
- void list(): Lists all available products.
- void receipt(): Generates a receipt for the buyer's purchases.

File Handling

- Database File (database.txt): Stores product details in the format pcode pname price dis.
- Temporary Database File (database1.txt): Used during the editing and removal of products to temporarily store updated data.

Usage

- Running the Application

   Compile the Program:
g++ shopping.cpp -o shopping

- Run the Program:

./shopping

- Administrator Login
Email: t.sahil@iitg.ac.in
Password: 123456789

- Sample Execution

On running the program, you will be presented with the main menu.
Choose 1 for Administrator or 2 for Buyer.
Administrator can manage products, while Buyers can view and purchase products.



Main Menu:

1) Administrator
2) Buyer
3) Exit

Administrator Menu:

1) Add the product
2) Modify the product
3) Delete the product
4) Back to Main menu
   
Buyer Menu:

1) Buy Product
2) Go Back

   
Receipt Example:


Product No    Prod.name     quantity    Price    Amount    Amount with discount
1             Bread         2           30.0     60.0      54.0
Notes
Ensure the database.txt file exists in the same directory as the executable.
The application uses basic file handling and does not implement advanced error handling or data validation.
Contact
For any queries or issues, please contact Sahil Tyagi at t.sahil@iitg.ac.in.
