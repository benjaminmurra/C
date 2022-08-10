#!/bin/bash
# The line above this one is the Shebang (#!) line. It tells the 
# execution environment which program to execute this script with.
# In the case of this script, we're telling Unix to use bash, which
# stands for Bourne Again SHell. Another option could be /bin/sh.
# If you do not include this line, then you must execute a script
# using the specific program you want to run it with. The shebang
# line must always be first and cannot include any spaces or it
# will not function properly!

# These lines are called comments. When the script runs, comment 
# lines are ignored (not executed). Comments are easily to identify 
# because their line starts with a #.

# In this script we will create a variable and print it to the 
# screen. 

# To print a line of text to the screen, we can use echo, just like
# in the previous challenge. Since these bash scripts use all the 
# same commands as the terminal, feel free to use any of them in your
# own scripts. Try changing some of the text within the quotes in 
# the echo command and see what prints to the screen.
echo "Welcome to my file creation script!"

# This echo is a simple command to create a blank output line.
echo

# This echo prints the name of the script file to the screen. In
# this line you will see a value as $0. This is called a variable.
# Variables in these scripts will always start with a $. Variables
# allow the script to store information for later use. In this case,
# $0 is referred to as a special or reserved variable. Upon script
# execution, the variable $0 will always be set to the name of the 
# script. 
echo "The name of this script is: $0"

# When you execute this script in the instructions, it tells you
# to include three extra words in the command: hill at pie.
# When you provide additional inputs to any command, script, or
# program they're referred to as arguments. In this case, the 
# script looks for arguments 1 and 2, which are stored in special
# variables $1 and $2 by default. You may include as many arguments
# as you'd like, but only the first two will be used here. By
# default, scripts will only use $1 to $9 for special variables
# with arguments. If you have more arguments than 9, consider
# using an input file. If an input file is not practical for your
# script, then you will have to manually parse any arguments 
# beyond the ninth.
echo "First Argument: $1"
echo "Second Argument: $2"

# Similar to the special variables for arguments themselves, there
# is also a special argument which gives the total number of 
# arguments provided to the script, as represented by $#.
echo "Total Arguments: $#"

# To simply print every argument to the screen, you can echo the
# special variable $@, which is where the arguments are stored.
echo "All Arguments: $@"
echo

# The first thing this script does is clean its intended working
# directory, in this case the "into" directory.
rm -r into 

# Next, create a new "into" directory in the current directory.
mkdir into

# Next, create two files using the names provided in the arguments.
touch into/$1.txt
echo "$1 file created at into/$1.txt"
touch into/$2.txt
echo "$2 file created at into/$2.txt"

# Since we can use any commands we want in our scripts, we can show
# the current directory structure using the ls command. Notice that
# it has the -R flag. The -R flag stands for "Recursive", which 
# means it will show the current directory structure and if there
# are any nested directories, it will also show their contennts.
# This process will repeat until there are no more directories to
# show. Be very careful when using any -R (sometimes -r) flags on
# Unix commands because if there are lots of items to process 
# inside your current directory, it could increase execution time
# immensely.
echo
echo "Current Directory Structure:"
ls -R
echo

# Just so we know the script finished successfully (rather than
# failing before the end and not telling us), we can include an
# echo to confirm the script completion.
echo "The $0 script has finished successfully."
echo
