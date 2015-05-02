========================================================================
    CONSOLE APPLICATION : As1v2 Project Overview
========================================================================

A line editor using a linked list to store each line in a text file

Set the startup command line parameters to "EDIT (the file to be read in) (the file to be outputted)"
- ignore the parenthesis 
- use "EDIT in.txt out.txt" to use the sample text file provided  

========================================================================
    COMMANDS
========================================================================

- If the letter I is entered with a number n following it, then insert the text to be followed before line n.  
		-If I is not followed by a number, then insert the text before the current line.  
 - If D is entered with two numbers n and m, one n, or no number following it, then delete lines n through m, line n, or the current line. 
 - If V is entered display the entire set of lines in the buffer  
 - G followed by a number, n, goes to line n in the buffer. If there is no line number it goes to the first line of the buffer.
 - L lists the lines of the buffer using the same numbering system as the D command. 
 - S Substitutes a new line, entered by the user, for the current line in the buffer, or at a specified line number. The command must prompt the user for the new line, perform the replacement, and then automatically issue the V command to list the buffer contents. 
 - E signifies exit and saving the text in the second file in the argument list. 
 - Q signifies exit immediately without saving changes.