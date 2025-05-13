/* THING.C - Programmed by Padrone, this is an inherit/clone file. DO NOT
             COPY! */
/* 200191: Padrone: Latest update */
/* 240693: Ethereal Cashimor: USERDOC and linewrap added */
// 160893: Moonchild clean up and declare types

#include <lw.h>
#include "setlight.h"
#pragma strict_types

/* USERDOC:
general
A thing. It can be read, either with a fixed message or a file. Clone this 
object to get a generic thing. Generally defined functions:
set_alias, set_short, set_long, set_read, set_weight and set_value, query_name,
query_weight, query_value, set_alias, set_alt_name, set_read_file, set_can_get.
*/

string name,alt_name,alias_name,short_desc,long_desc,read_message,read_file;
string info; /* Matt OCT-05-94: Added set_info and query_info */
status can_get;
int weight,value;

int read(string str);

void set_name(string n)      { name = n; short_desc = capitalize(n); }

void reset(int arg) {
  if(arg) return;
  can_get = 1;
  weight = 1;
  value = 1;
  set_name("thing");
}

int id(string str) {
  return str == name || str == alias_name || str == alt_name;
}

int get()                    { return can_get; }

void set_short(string sh)    { short_desc = sh; }
void set_long(string long)   { long_desc = lw(long); }
void set_read(string str)    { read_message = str; }
void set_read_file(string f) { read_file = f; }
void set_weight(int w)       { weight = w; }
void set_value(int v)        { value = v; }
void set_alias(string n)     { alias_name = n; }
void set_alt_name(string n)  { alt_name = n; }
void set_can_get(int n)      { can_get = n; }
void set_info(string str)    { info = str; }

string short()               { return short_desc; }

void long() {
  if(long_desc) write(long_desc);
  else if(read_file || read_message) read(name);
  else write("You see nothing special.\n");
}

string query_name()          { return name; }
int query_weight()           { return weight; }
int query_value()            { return value; }
string query_info()          { return info; }

void init()                  { add_action("read", "read"); }

int read(string str) {
  if(!str || !id(str)) return 0;
  else if (!read_file && !read_message) return 0;
  else {
    say((string)this_player()->query_name() + " reads the " + name + ".\n");
    if(read_file) cat(read_file);
    else write(read_message);
    return 1;
  }
}
