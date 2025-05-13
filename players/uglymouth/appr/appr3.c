inherit "room/room";

void reset(int arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Apprentice Wizard Commands";
  long_desc = "Apprentice Wizard Commands.\n\n"
    + "Some of your new commands will be explained here. All the wizard\n"
    + "commands are described in the docs, so this room will only make\n"
    + "you familiar with the file functions. The rest you can then read\n"
    + "yourself. The commands for readin files are:\n"
    + "\tcd, ls, dir, pwd, more, cat, tail, man.\n\n"
    + "To be able to understand the mud, you should know how the directory\n"
    + "structure of the mud is built up. In the mud names of subdirectories\n" 
    + "are separated by a '/'. When you will be newwiz, your home directory\n" 
    + "will be '/players/<your name>'. The directory '/' is the root of the\n"
    + "mud. All docs are in the /doc directory.\n" 
    + "Three scrolls, numbered 1 - 3, hang from the walls. Each containing\n"
    + "some information on the commands mentioned above. Read them if you\n"
    + "are not yet familiar with file functions in a mud.\n";
  dest_dir = ({
    "/players/uglymouth/appr/appr4", "next",
    "/players/uglymouth/appr/appr2", "previous",
    "/players/airborne/new/station", "leave",
  });
}

void init() {
  ::init();
  add_action("read", "read");
}

int read(string str) {
  int i;
  if(sscanf(str, "scroll %d", i) != 1) {
    notify_fail("Read which scroll?\n");
    return 0;
  }
  switch(i) {
    case 1:
      write(
  "With the 'cd' command you can change the directory (or short 'dir')\n"
  + "you are working in. Try 'cd /doc' to get to the docs.\n"
  + "The commands 'ls' and 'dir' will show you the contents of your\n"
  + "current directory. Any filenames ending with a '/' are subdirectories.\n" 
  + "In '/doc' the 'w/' is the subdirectory where the wizard commands are\n" 
  + "described. You can do 'ls <directory name>' to scan the contents of a\n" 
  + "dir without leaving your current dir. So 'ls /players/uglymouth/appr'\n" 
  + "will show you the contents of the directory where these rooms are\n"
  + "coded, while you will remain in /doc. To scan, or change to subdirs of\n"
  + "your current dir, you only need to enter the name of the subdir. For\n"
  + "example: 'ls w' or 'cd w' will scan/bring you to the dir '/doc/w'.\n"
  + "'..' refers to the parent dir, the dir one '/' step back. Thus from\n"
  + "'/doc/w/' both 'cd /doc' and 'cd ..' will get you back to '/doc'.\n"
  + "The 'pwd' command shows you the pathname of the dir you are currently\n" 
  + "working in. Just in case you forgot ;-)\n");
      return 1;
    break; 
    case 2:
      write(
  "The commands 'more <file name>' and 'cat <file name>' will show you\n" 
  + "the contents of a file, one page at a time. Go to the '/doc' dir, and\n" 
  + "do 'ls' and 'more wiz_help'. This reads you the contents of the text\n" 
  + "file 'wiz_help', which contains a list of which commands are available\n" 
  + "to each wizard level. By typing the whole file name, you can read the\n"
  + "contents of any file, without leaving your current dir. For example:\n"
  + "with 'more /players/uglymouth/appr/appr3.c' you will read the code of\n" 
  + "this room.\n\n"
  + "The 'tail <file name>' command shows you the last section of a file.\n"
  + "Note that this section is longer than one page and doesn't use page\n"
  + "format. It can be useful sometimes though. For example, when you type:\n"
  + "'tail lpmud.log' you will get the latest error messages that have been\n"
  + "caused in the mud. (lpmud.log is one of the biggest files around).\n");
      return 1;
    break;
    case 3:
      write(
  "So now you can handle reading the files you need to read. But often\n"
  + "you have a problem and are not sure where to find the answer. Now you\n"
  + "don't want to go through all the docs again. That's why they invented\n"
  + "the 'man' (manual) command. Type 'man'. You will now have a list of\n"
  + "which doc directories you should read. Arguments for the 'man' command\n"
  + "may be any subdir, or any individual topic in each of the subdirs.\n"
  + "Thus 'man w' will actually do the same as 'ls /doc/w'. And 'man title'\n"
  + "does the same as 'more /doc/w/title', but you wouldn't have to know\n"
  + "for sure that the doc on the 'title' command is in '/doc/w'.\n");
      return 1;
    break;
    default:
      write("The scrolls are only numbered 1, 2 and 3.\n");
      return 1;
    break;
  }
}

