#include "/players/tamina/defs.h"

status full;

id(str) {
   return str == "liquid" || str == "vial";
}

string short () {
      return "A small vial";
}

void long () {
   if (full)
      write ("This is a small vial containing a strangely coloured liquid.\n");
   else
      write ("This is a small, empty vial.\n");
}

void reset (int arg) {
   if (!arg)
     full = 1;
}

void init() {
   AA("drink", "drink");
}

int drink (string str) 
{
  if (!id(str)) return 0;

  if (!full) 
  {
    write ("But the vial is empty.\n");
    return 1;
  }
  write("You open the vial and pour the thick liquid down your "+
        "throat.\n\nIt has a strange bitter taste, and as you drink "+ 
        "it you\nfeel a tingle as your body begins to rejuvenate.\n\n"+  
        "You are healed.\n");
    say(TPN+" drinks a potion.\n");

  TP->heal_self(50 + random(21));
  TP->add_intoxication(1);
  full = 0;

  return 1;
}
      
int get() {  
  return 1;  
}

int query_value() {
   if (full)
      return 1000;
   else
      return 25;
}

int query_weight() {  
  return 1;  
}
