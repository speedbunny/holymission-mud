#pragma strict-types
// Generic object

#include <lw.h>
string name, alt_name, alias_name, long_desc, short_desc, info;
int value, weight;
status can_get;

//Prototypes

void long() { write(lw(long_desc)+"\n");}
string short() { return short_desc;}
void reset(int arg);

void set_name(string n) { name = n; }
void set_value(int v) { value = v; }
void set_weight(int w) { weight = w; }
void set_short(string d) { short_desc=d; }
void set_long(string d) { long_desc=d; }
void set_alias(string a) { alias_name=a; }
void set_alt_name(string a) { alt_name=a; }
void set_can_get(int flag) { can_get=flag; }
void set_info(string i) { info=i; }

int query_value() { return value; }
int query_weight() { return weight; }
string query_info() { return info; }
int get() { return can_get; }

int id(string str) {  
  return str == name || str == alias_name || str == alt_name;
}

void reset(int arg) {
  if (arg)
    return;
  name="object";
  long_desc="A Generic Object. Just add water :)";
  short_desc="Generic Object";
  weight=1;
  value=10;
  can_get=1;
}

void init() {
}

