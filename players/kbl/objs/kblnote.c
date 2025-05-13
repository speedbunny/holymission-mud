/* Kbl's Note of information on important items. */

inherit "/players/kbl/objs/thing";
#include "/players/kbl/header/T.h"

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    name = "Small leaf";
    short_desc = "Small leaf";
    long_desc = "Small maple leaf. Looks to have writing on it.\n";
    value = 10;
    weight = 0;
    alias_name = "small leaf";
    alt_name = "maple leaf";
  }
}


init()
{
  add_action("read","read");
}

read(str)
{
  if(!str)
   return;
  if(id(str))
  {
    tell_object(TP,"Star Leaf operational instructions:\n"+
                   "-----------------------------------\n"+
                   "Attack living -  toss <living>\n"+
                   "Memory ability - rmem <string>\n"+
                   "Erase memorys -  rmem <1>,<2>,<3>,<4>\n"+
                   "Erase memory -   rmem all\n"+
                   "Absorb energy -  absorb <all> or <half>\n"+
                   "Information   -  ask leaf about origin\n"+
                   "              -  ask leaf about energy\n"+
                   "              -  ask leaf about recharge\n"+
                   "              -  ask leaf to dump memory\n");
    return 1;
  }
}

get()
{
  return 1;
}

query_value()
{
  return 5;
}

query_weight()
{
  return 0;
}
