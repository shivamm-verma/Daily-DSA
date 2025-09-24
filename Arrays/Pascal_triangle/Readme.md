Pascal's Triangle Generator
Overview

This project generates Pascal’s Triangle up to a user-specified number of rows. Pascal’s Triangle is a triangular array of binomial coefficients. Each number is the sum of the two numbers directly above it.

The project includes implementations in:

C++

Java

Python

Features

Generates Pascal’s Triangle dynamically based on user input.

Supports any number of rows.

Efficient calculation using combinatorial formula to avoid factorial overflow.

How to Run
C++

Compile the code using a C++ compiler:

g++ pascal.cpp -o pascal


Run the executable:

./pascal


Enter the number of rows when prompted.

Java

Compile the code:

javac PascalTriangle.java


Run the program:

java PascalTriangle


Enter the number of rows when prompted.

Python

Run the Python script:

python pascal.py


Enter the number of rows when prompted.

Example Output

For n = 5 rows:

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1

How It Works

The first value of every row is 1.

Each subsequent value is calculated using the formula:

val = val * (i - j) / (j + 1)


where i is the row index and j is the position in the row.

This formula avoids calculating factorials directly and is efficient for large rows.

Author

Nicky