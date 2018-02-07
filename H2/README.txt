Jose Arguelles
CS 283
H2

This homework was done using the gcc compiler on tux.

This folder contains a .txt file with the answer to 10.6, which is called
106.txt. It also contains the programs fstatcheck.c (for problem 10.8),
cpfile.c (for problem 10.10), and tee.c

10.8 fstatcheck
This program is meant to tell you what a number file descriptor is (like if
it is a file, directory, or other) and if it is readable. To compile this, I
reccommend typing "gcc -o fstatcheck fstatcheck.c" into the command line.
Then you can run the program by typing "./fstatcheck #" where the pound
symbol is any number you can enter. If you do not enter in an argument, you
will get a segmentation fault.

10.10 cpfile
This program is meant to copy what you type in stdin into stdout, or if a
file name is added to the argument (must incldue extension, .txt) it will
output the contents of the file into stdout. To compile this, I reccommend
typing "gcc -o cpfile cpfile.c". Then you can run the program by typing
"./cpfile" or "./cpfile filename.txt" where filename can be any .txt file
that is within the same directory. Make sure to include the .txt extension!

tee
This program is meant to copy what you type in stdin into stdout and a file.
If a file does not exist, it will create a new file with that name. If it
already exists then it will completely overwrite the contents of the file.
If the -a flag is included within the arguments (must come before filename)
it will append to whatever file is opened instead of overwriting it. To
compile this code, I reccommend typing "gcc -o tee tee.c" into the
commandline. To run this code you can either type in "./tee filename.txt"
(which you can type into and it will overwrite/create a file" or you can
type "./tee -a filename.txt" (where when you type and enter, it will
append/create a file).

This was a good homework assignment.
