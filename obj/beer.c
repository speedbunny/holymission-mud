// 160893: Moonchild: clean-up & strict-types 

#include "setlight.h"

#pragma strict_types

int full;

void reset(int arg) { if(!arg) full = 1; }

int id(string str)  { return (str=="beer" && full) || str=="bottle"; }

int get()           { return 1; }

string short()      { return full ? "Bottle of beer" : "Empty bottle"; }
void long()         { write(short() + ".\n"); }
string query_name() { return (full ? "beer" : "bottle"); }
int query_value()   { return full ? 0 : 10; }

void init()         { add_action("drink", "drink"); }

int drink(string str) {
  if(str && str != "beer" && str != "from bottle") return 0;
  if(!full) return 0;
  if(!this_player()->drink_alco(2)) return 1;
  full = 0;
  write("It is really good beer!\n");
  say((string)this_player()->query_name() + " drinks a bottle of beer.\n");
  return 1;
}
