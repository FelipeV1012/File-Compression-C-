File Compression Tool (RLE)
Description
This File Compression Tool is a simple command-line application written in C++ that uses Run-Length Encoding (RLE) for compressing and decompressing text files. RLE is a basic form of lossless data compression where sequences of the same data value are stored as a single data value and count.

Getting Started
Dependencies
C++ Compiler (such as GCC or Clang)
Basic command-line interface (like Terminal on macOS/Linux or Command Prompt/Powershell on Windows)
Installing
Download the source code from the repository or copy it into a text file.
Save the file with a .cpp extension, for example, file_compressor.cpp.
Compiling the Program
To compile the program, use a C++ compiler. For example, using GCC:

bash
Copy code
g++ -o file_compressor file_compressor.cpp
This will create an executable named file_compressor.

Executing the Program
To run the program, use the following command in your command line:

bash
Copy code
./file_compressor
Then follow the on-screen instructions to compress or decompress a file.

How to Use
Start the program. You will see a prompt to choose between compression and decompression.
Enter 1 to compress a file or 2 to decompress a file.
Enter the name (or path) of the input file.
Enter the name (or path) for the output file.
The program will process the file and save the output to the specified location.
Important Notes
The tool is primarily designed for text files and may not be effective for other file types.
Ensure you have backup copies of important files before compressing or decompressing.
The efficiency of compression depends on the file content; files with lots of repeated characters are more effectively compressed.

