# -Trabalho2_Faculdade-
Inventory Management System in C.

This is a console system developed in C to manage product inventory. The project was created as part of the Algorithms II course and focuses on the direct manipulation of text files for data persistence, without the use of in-memory vectors for runtime storage.

A list of everything the program does:
* Product registration with unique code verification.
* Price and quantity changes.
* Product deletion.
* Listing of all products or filtering by name and brand.
* Reports on total quantity and total value by name or brand.

One of the main requirements of the project was that the system should not have a fixed product limit. To meet this requirement, the architecture was developed to manipulate the stock.txt file directly for each operation, instead of loading the data into a vector in memory. For change and delete operations, the temporary file technique was implemented to ensure data integrity without the need for external libraries.

The project was created in Dev C++ 6.3

To compile the project, use a GCC compiler and run the following command in the root folder: gcc main.c product.c -o stock.exe

The code was designed in Windows.
