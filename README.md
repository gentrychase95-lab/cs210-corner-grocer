# Corner Grocer  
**Author:** Chase K. Gentry  
**Course:** CS-210 Programming Languages (C++)  
**Portfolio Artifact**

---

##  Overview
Corner Grocer is a simple C++ console application that reads a text file of grocery items, counts how many times each item appears, and displays the results.  
It helps a store quickly see which products are purchased most often without needing to sort data by hand.

All logic runs from **CornerGrocer.cpp**, and the **data** folder holds the input file used for counting.

---

##  Features
- Reads an input text file from the `data` directory  
- Counts the frequency of each grocery item  
- Displays results in a clean list format  
- Generates a text-based histogram showing purchase frequency  
- Handles missing files gracefully (no crashes)

---

##  What I Did Well
- Wrote clear, easy-to-follow C++ code with helpful comments  
- Kept everything organized and simple in one file  
- Used a `map<string, int>` to automatically manage unique items and counts  
- Handled file input/output safely and efficiently

---

##  What Could Be Improved
- Add better error handling for bad or missing data  
- Sort results by highest purchase frequency  
- Add a simple user menu (search by item, export to file, etc.)  
- Optimize for very large input files

---

##  Challenges and Solutions
The hardest part was getting file input/output to work without crashes when files were missing.  
I learned to check file status, read line by line, and store results in a `map`.  
C++ reference sites and Stack Overflow helped me figure out the best way to handle it.

---

##  Skills and Takeaways
- File I/O, loops, conditionals, and STL maps in C++  
- Structuring small console programs that can easily scale  
- Writing readable, maintainable, well-commented code  
- Concepts that apply to other languages like Python and Java

---

##  Code Style and Maintenance
- Consistent formatting and descriptive variable names  
- Each section of logic is clearly commented  
- Easy to adapt or expand later without rewriting everything

---

##  Build and Run Instructions
Make sure your `CornerGrocer.cpp` file and the `data` folder are in the same directory.

```bash
# Compile
g++ -std=c++17 CornerGrocer.cpp -o CornerGrocer

# Run
./CornerGrocer
