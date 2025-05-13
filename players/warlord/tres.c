/* TREASURE.C - This is an inherit/clone file. DO NOT COPY! */
/* 151292: Dago: Changed alias_name to alt_name */
/* 290693: Ethereal Cashimor: USERDOC added */
/* 130793: Ethereal Cashimor: Read with no argument rejected */
// 160893: Moonchild: declare types, remove process_string for sec. reasons,
//                    clean up code somewhat. linewrap in long()

/* USERDOC:
general
This is a generic valuable object. Clone a copy, and setup local values.
Generally defined functions:
set_short, set_long, set_id, set_name, set_alias, set_alt_name, query_value,
set_value, set_weight, query_weight, set_read, set_info, query_info,
query_name.
*/

#include <lw.h>
#include "setlight.h"
#pragma strict_types

string short_desc,long_desc,name,alias_name,alt_name,read_msg,info;
int value, local_weight;

void reset(int arg)           {}

int id(string str) {
  return str == name || str == alias_name || str == alt_name;
}

int get()                     { return 1; }

void set_id(string str)       { local_weight = 1; name = str; }
void set_name(string str)     { local_weight = 1; name = str; }
void set_alias(string str)    { alias_name = str; }
void set_alt_name(string str) { alt_name = str; }
void set_long(string str)     { long_desc = lw(str); }
void set_value(int v)         { value = v; }
void set_weight(int w)        { local_weight = w; }
void set_read(string str)     { read_msg = str; }
void set_info(string i)       { info = i; }

void set_short(string str) {
  short_desc = str;
  long_desc = "You see nothing special.\n";
}

string short()                { return short_desc; }
void long()                   { write(long_desc); }
string query_name()           { return name; }
int query_value()             { return value; }
int query_weight()            { return local_weight; }
string query_info()           { return info; }

void init()                   { if(read_msg) add_action("read", "read"); }

int read(string str) {
  if(!str || !id(str)) {
    notify_fail("Read what?\n");
    return 0;
  }
  write(read_msg);
  return 1;
}
