inherit "obj/weapon";
#include <lw.h>

status drop() 
  {writelw(
  "Your feel your heart shatter just like the sword at is slips out of "+
  "your fingers and falls to the ground, shattering into uncountable "+
  "fragments.  Never before have you felt such despair, knowing that the "+
  "sword you have come to know and trust is gone forever.\n");  
  destruct(this_object());
  return 1;}

void reset(int arg) 
  {::reset(arg);
  if(!arg) 
   {set_name("denizen's sword");
   set_alias("sword");
   set_short("Denizen's sword");
   set_long("The sword has a familiar feel to it, and feels sturdy in your grip.\n"+
   "It is likely to be a weapon you can count on to help you out in\n"+
   "dangerous situations.\n");
   set_class(11);
   set_value(0);
  set_weight(3);}}

int throw_out_transfer()
  {return 1;}
