Dev Log
======

## 3-25-2026

- Structured main program to encompass new functions<br>
    * need to clean up logic bugs, but files read fine
    * indices out-of-range, bugs with cin statements

#### Reflection
As with most C++ program, things aren't as easy as they seem.<br>
I need to brush up on how to use cin so that spaces don't<br>
cause unexpected output or cause a less user-friendly<br>
experience. When user inputs values to create a new row<br>
on the table, spaces inputs the next string into the next<br>
field, and skips to the preceding field for next user input.<br>
Either I must eliminate spaces in input or figure out how<br>
to include spaces as one string. I may experiment with 'cin'<br>
in a separate program to get a better understanding. <br>

## 3-24-2026

- Added functions to logging program<br>
    * view, edit, add entry, and menu output<br>
- Planning a "restore" feature<br>
    * allowing user to return table to original state<br>

## 3-23-2026

- Started C++ program for logging VMs<br>
    * takes data from a csv and turns it into a table<br>
    * able to view data on table (using vector data type)<br>

#### Reflection
Although this may be taking time from started on using VMs,<br>
I feel it is important for me keep my programming skills sharp.<br>
This will make it more streamlined to update the log via bash. 
<br>

## 3-22-2026

- Researched bash commands<br>
    * needed way to update text at specific points in file<br>
    * learned about awk and sed (besides echo, printf)<br>
    * files were not capturing text updates. step missing?<br>
    * At this stage, manually update files/run simple script shall suffice<br>

#### Reflection
I saw the depth of bash commands and how useful they could be,<br>
but for the task of complex updates to a text file, this may<br>
go over the intended scope of this project. I am curious about<br>
writing a small program to update a csv that can be called in the<br>
bash console to automate.
<br>

## 3-21-2026

- Created local git repo<br>
     * can't create GitHub repo via git bash<br>
        
- Created GitHub repo manually<br>     

- Linked local repo to GitHub<br>
    * had issue linking repos because I missed crucial bash command<br>
    * will include .md reference describing process<br>

- Acquired host system information<br>
    * will create separate .md reference file<br>

#### Reflection
My quest in building an environment for Virtual Machines<br> 
has been a bit sidetracked by learning git and bash commands<br>
which is a world all its own. I wanted to automate logging<br>
as much as possible, utilizing bash scripts, which may take <br>
some time.
<br>