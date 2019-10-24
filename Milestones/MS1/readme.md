# Milestone 1

## `Utilities` and `Item` classes

This milestone will implement and test the `Utilities` and `Item` classes.

- `Utilities` class is an object used to support the parsing of input files to setup and configure the assembly line simulation.
- `Item` class encapsulates the information about a given item on the assembly line that can be filled within a customer order.

The specifications of the classes are defined below.


### `Utilities` Class

Parsing string data from input files is performed the same for all objects within the system.  The `Utilities` type provides the basic functionality required for all objects in the assembly line system.

Each `Utilities` object holds the following information:
-  `m_widthField` -- specifying the length of the token extracted; used for display purpose later; default value is `1`.
-  `m_delimiter` -- separates the tokens from a given `std::string`. All `Utilities` objects **share the same delimiter**.

The member functions of the `Utilities` class include:
-  `void setFieldWidth(size_t)` -- sets the field width of the current object to the value of the parameter
-  `size_t getFieldWidth() const` -- returns the field width of the current object
-  `const std::string extractToken(const std::string& str, size_t& next_pos, bool& more)` -- extracts tokens from the first parameter
  - This function uses the delimiter to extract the next token from `str` starting at `next_pos`.
  - If successful, it returns the extracted token found and sets `more` to `true`; `false` otherwise.
  - This function reports an exception if there are two delimiters with no token between them.
  - This function updates the current object's `m_widthField` data member if its current value is less than the size of the token extracted.
    - **Note:**  `str` represents a single line read from an input file
-  `static void setDelimiter(const char)` -- sets the delimiter for this class to the character received
-  `const char getDelimiter() const` -- returns the delimiter character of the current object.


### `Item` Class

An `Item` object manages a single item on the assembly line.

Each `Item` holds the following information:
-  `m_name` – the name of the Item
-  `m_description` – description of the item
-  `m_serialNumber` – the next serial number to be assigned on the assembly line
-  `m_quantity` – the number of current items left in stock
-  `m_widthField` – the maximum characters to be displayed for a field
  - **Note:**  All `Item` objects share the same `m_widthField`

The member functions of the `Item` class include:
-  custom constructor
  - upon instantiation, an `Item` object receives a reference to an unmodifiable `std::string`.  This string contains a single record (one line) that has been retrieved from the input file specified by the user.
  - the constructor uses an `Utilities` object (created local in the function) to extract each token from the record and populates the `Item` object accordingly.
  - **Note:**  You can assume that a record from the file contains 4 fields separated by a delimiter, in the following order:
    - name of item
    - starting serial number
    - quantity in stock
    - description
  - the delimiter of the tokens is a single character, specified by the client and stored into the `Utilities` object.
  - once the constructor has extracted all of the tokens from the record, it updates `Item::m_widthField` to the maximum value of `Item::m_widthField` and `Utilities::m_widthField`.
  - **Note:**  the `display(...)` member function uses this field width to align the output across all of the records retrieved from the file.

-  `const std::string& getName() const` - returns the name of the current `Item` object
-  `const unsigned int getSerialNumber()` – returns the next serial number to be used on the assembly line and increments `m_serialNumber`
-  `const unsigned int getQuantity()` – returns the remaining quantity of the current `Item` object
-  `void updateQuantity()` – substracts 1 from the available quantity; should not go below 0.
-  `void display(std::ostream& os, bool full) const` -- inserts the content of the current object into first parameter.
  - if the second parameter is `false`, this function inserts only the name and serial number in the format: `NAME [######]`
  - if the second parameter if `true`, this function uses the following format: `NAME [######] Quantity: QTY Description: DESCRIPTION`
  - the `NAME` and `QTY` fields will use `m_widthField` characters, serial number field will use 6 characters; the `DESCRIPTION` has no formatting options
  - this function will terminate the printed message with an endline

## Tester Module

The tester module and input files have been added to the repository. Do not modify any of them. See in the sample output below the expected command line.

## Sample Output
The output for this milestone should look as follows:

```
Command Line: ms1 Inventory1.dat Inventory2.dat

=======================
= Inventory (summary) =
=======================
CPU          [123456]
Memory       [654321]
GPU          [056789]
SSD          [987654]
Power Supply [147852]

=======================
=  Inventory (full)   =
=======================
CPU          [123456] Quantity: 5            Description: Central Processing Unit
Memory       [654321] Quantity: 10           Description: Basic Flash Memory
GPU          [056789] Quantity: 7            Description: General Porcessing Unit
SSD          [987654] Quantity: 5            Description: Solid State Drive
Power Supply [147852] Quantity: 20           Description: Basic AC Power Supply

=======================
=  Manual Validation  =
=======================
getName(): CPU
getSerialNumber(): 123456
getSerialNumber(): 123457
getQuantity(): 5
getQuantity(): 4
```


#### Submission

Before the due date, upload to your matrix account the following files:
-  `Utilities.h`
-  `Utilities.cpp`
-  `Item.h`
-  `Item.cpp`