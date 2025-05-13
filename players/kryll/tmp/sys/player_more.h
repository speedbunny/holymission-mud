#ifndef __PLAYER_MORE_H__

#define __PLAYER_MORE_H__

// Prototypes:

int set_line_number(int val);
static void even_more(string str);
int more(string str);
static void more_string2(string str);
void more_string(string str);
static string line_format(string str, int arg, int w1, int w2, string indent,\
                          string explo, string delim, string lastchar);

// End prototypes.


// Global variables:

static string more_file;        /* used by the more-command */
static string *more_txt;
static int    more_line;

// End global variables.

#endif // __PLAYER_MORE_H__

