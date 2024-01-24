CIS 2107 Notes

## Chapter 1

- ~ : home directory

Command Grouping uses semicolon ;

General Commands
- which - displays path name for a command
- chsh - change shell | echo $SHELL shows current shell
- whereis - display all location
- passwd - change your login password
- date - displays date
- cal - displays calendar
- sleep - do nothing for some time
- alias - customize command names
    - alias newcommand=""
- history - displays history of recently used commands
- exit/logout - exit form login session
- shutdown - shutdown system

File Commands
- ls
    - ls -alrt
- pwd - path name
- more - see page by page / less
- touch - create or update file
- cp - copies files/directories
- mv - moves or renames files/directories
- rm - removes files/directories
- script - writes a log of whatever happened in the terminal to a file
- find - looks up a file in a directory tree
- mkdir - makes a directory
- rm - removes a directory

# File permissions
- roles
    - u - for user
    - g - for group
    - o - for others
- permissions
    - r - for read
    - w - for write
    - x - for execute

    for directories, read lets you look into directories, write lets you add and remove files, and execute lets you cd into them

3 digit notation
- the first digit corresponds to the owner(user)
- the second digit corresponds to the group
- the third digit corresponds to the others

0 - Deny all

1 - Execute Only

2 - Write Only

3 - Write + Execute

4 - Read Only

5 - Read + Execute

6 - Read + Write

7 - Read + Write + Execute

chmod to set permissions to a file
example:
chmod 123 example.txt

> STDIN - keyboard

> STDOUT - screen

> exit: shutdown

> logout: hibernate/sleep