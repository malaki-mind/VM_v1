Dev Log
======
## 7-18-2026
- Completed edit feature for vm_log2 program
    * now user can write/edit vm log fields
    * able to use directly in command line
    * save and quit updates git

### Reflection
sometimes the simplest ideas can take a complicated path in C++<br>

## 7-17-2026
- Created better flow for vm_log2 program 
    * updated row selection functions
    * need to implement better type checking

#### Reflection
slowly chipping away in periods where I can try out an idea.<br>

## 7-12-2026
- Revisiting project
    * focused on other creative project for some time
- Discovered bugs in VM Log application
    * editing entries does not update the table
    * need to push_back new entry and delete old
    * need to capture row index to implement properly

#### Reflection
I've been working a bit on my music project which has been<br>
eating up a lot of time, including the time taken from my<br>
day job. I am looking to get back into this and finally get<br>
a VM up and running. I want to start building applications and<br>
web services that will tie into my creative projects, as well<br>
as advancing my career into something a bit more suitable. <br>

## 3-26-2026
- Cleaned up and pushed VM Log application to git
    * cleared up input issues with getline() function
    * used cin.clear() and cin.ignore() to clean buffer

- Pushed files not meant for the git
    * learned valuable lesson in secure commits and pushes
    * nothing sensitive leaked but made git messy

#### Reflection
It's good I went back and cleaned up the cin bugs<br>
and was reminded of cin.clear() and cin.ignore<br>
as well as better practices in inputting data<br>
utilizing getline(). It took just a little<br>
research to be reminded of these basic functions.<br>
I did make a mistake of pushing .filters and .exe<br>
files to the git after making naming mistakes and<br>
a misunderstanding of what should be uploaded to<br>
a remote git. Although I was able to remove the files<br>
from the main git, the unneeded files still exist<br>
in the commit history. This was an important lesson<br>
in secure practices with the git, as I see the process<br>
of removing files from the commit history is quite<br>
the process. Thankfully nothing sensitive was leaked, just<br>
taking on the extra precautions and building the paranoia<br>
before committing anything to the git.<br>

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