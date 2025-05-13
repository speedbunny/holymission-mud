//  for creating Body Parts

#include "/players/tamina/defs.h"

string info, name, id;
string short_desc, long_desc;
string part, owner, code;
int value, weight;

void reset(int arg) 
{
  if (arg) return 0;
}

int id(string str) 
{
  return (str == name || str == short_desc || str == part || str == code);
}

void query_info()
{ 
  write("This is the "+part+" from "+owner+".\n");
}

void long()          { write(long_desc); }
string short()       { return short_desc; }
int query_value()    { return value; }
int query_weight()   { return weight; }
string query_long()  { return long_desc; }
string query_name()  { return name; }
string query_part()  { return part; }
string query_code()  { return code; }
string query_short() { return short_desc; }
string query_owner() { return owner; }

set_name(n)     { name = n; set_short(n); }
set_part(p)     { part = p; }
set_owner(o)    { owner = o; }
set_code(c)     { code = c; }
set_short(s)    { short_desc = s; long_desc = s+"\n"; }
set_long(l)     { long_desc = l; }
set_value(v)    { value = v; }
set_weight(w)   { weight = w; }

int get()  { return 1; }
int drop() { return 0; }
int prevent_insert() 
{
  write("You cannot put the "+part+" in there.\n");
  return 1; 
}
