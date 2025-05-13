#ifndef __P_MORE_C__

#define __P_MORE_C__

#include "player_defs.h"
#include "player_more.h"

/*--------------------------------------------------------------------------*/
/* Set the number of lines shown to the player when they read something     */
/* like a board or file. Use by the cat command also                        */
/*--------------------------------------------------------------------------*/
int set_line_number(int val) {
  int num;

  if(!val)
    write("Your screen is currently set at " + CHUNK + " lines.\n");
  else {
/*
    sscanf(val, "%d", num);
    if(!num)
*/
    if(!intp(val))
      write("You can't set the number of lines to that!\n");
    else {
/*
      env_var["LINES"] = num;
*/
      env_var["LINES"] = val;
      write("Your screen is currently set at " + CHUNK + " lines.\n");
    }
  }
  return 1;
}

/*--------------------------------------------------------------------------*/
/* HERP: this is the only file-function for player.c !                      */
/* In more we find out if this is a full path or has a '~' that needs to    */
/* be substituted. After that is done, then it prints the first section of  */
/* lines defined by CHUNK and asks if you want more and inputs your answer  */
/* to "even_more". Choices are up, down(enter), and quit. repeated till     */
/* nothing left in the file.                                                */
/*--------------------------------------------------------------------------*/
static void even_more(string str) {
  if(str == "" || str == "d")
    more_line += CHUNK;
  else if(str == "q") {
    write("Ok.\n");
    return;
  }
  else if(str == "u") {
    more_line -= CHUNK;
    if(more_line < 1)
      more_line = 1;
  }
  if(cat(more_file, more_line, CHUNK) == 0) {
    more_file = 0;
    write("EOF.\n");
    return;
  }
  write("More: (line " + (more_line + CHUNK) + ") [u|d|q|enter] ");
  input_to("even_more");
  return;
}

int more(string str) {
  if(!str)
    return 0;
  if(str[0] == '~')
    str = "/players/" + name + str[1..strlen(str) - 1];
  more_file = str;
  more_line = 1;
  if(cat(more_file, more_line, CHUNK) == 0) {
    write("No such file.\n");
    return 1;
  }
  input_to("even_more");
  write("More: (line " + (CHUNK + 1) + ") [u|d|q|enter] ");
  return 1;
}

/*--------------------------------------------------------------------------*/
/* moonchild 210693: added this function                                    */
/* Other more was to split up strings into readable chunks. This one just   */
/* displays the whole string with CHUNK breaks. No special options.         */
/* Useful for boards and such.                                              */
/*--------------------------------------------------------------------------*/
static void more_string2(string str) {
  int i, sz, chsz;

  if(str && lower_case(str[0..0]) == "q") {
    more_txt = 0;
    return;
  }
  sz=sizeof(more_txt);
  if(sz > more_line+CHUNK) {
    for(i=more_line; i<more_line+CHUNK; i++)
      write(more_txt[i] + "\n");
    write("More? [q to quit] ");
    more_line += CHUNK;
    input_to("more_string2");
    return;
  }
  else {
    for(i=more_line; i<sz; i++)
      write(more_txt[i] + "\n");
    more_txt = 0;
    return;
  }
}

void more_string(string str) {
  more_txt = explode(str, "\n");
  more_txt = more_txt[0..sizeof(more_txt) - 2];
  more_line = 0;
  more_string2(0);
  return;
}

/*--------------------------------------------------------------------------*/
/* Makes lies line wrap.                                                    */
/*--------------------------------------------------------------------------*/
static string line_format(string str, int arg, int w1, int w2, string indent,
                          string explo, string delim, string lastchar) {
  string *arr;
  int    i, j, sz;

  arr = explode(str, explo);

  sz=sizeof(arr);
  if(sz < 2)
    return (arr[0] + lastchar);

  str = "";

  for(i=0; i<sz-1; i++) {
    str += arr[i] + delim;
    if(strlen(str + arr[i+1]) > (arg-w1)) {
      str += "\n";
      if(!indent)
        indent = "";
      w1 = -strlen(str);
      str += extract(indent + "                     ", 0, w2);
    }
  }
  return (str + arr[i] + lastchar);
}

#endif // __P_MORE_C__
