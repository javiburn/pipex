# pipex
Simulating the pipe "|" in C language.

A project designed to learn about creating new processes and communicating between them. With this project I learned how the fork(), pipe() and dup2() functions work.

<img width="808" alt="Screen Shot 2023-05-17 at 12 02 20 PM" src="https://github.com/javiburn/pipex/assets/72255876/72629482-c255-422e-95c9-dd6b5cd526d4">

The program admits 4 arguments (plus the program's name ./pipex), being the first one the name of the file to be read, then the two commands that will be executed simulating the pipe operation, and finally the name of the output file.

With this, the command "./pipex infile command1 command2 outfile" works the same way as "<infile command1 | command2>outfile", as it is shown on the images above.
