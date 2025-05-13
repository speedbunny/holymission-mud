inherit "/players/kbl/objs/thing";
#include "/players/kbl/cloud/gen.h"

int type;
string energy;

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
   short_desc = "Wand upgrader";
   long_desc = "Weightless item made from woven clouds.\n";
   weight = 0;
   type = 1;
   value = type * 500;
   energy = "blue";
   alias_name = "cloud";
   alt_name = "upgrade";
   can_get = 1;
   read_message = "Clouds by Kbl";
  }
}

set(com,var)
{
  switch(com)
  {
    case "type":    
         type = var;
         break;
    case "value":
         value = type * var;
         break;
    case "energy":
         energy = var;
         break;
  }
}

query(str)
{
  switch(str)
  {
    case "type": return type;
         break;
  }
}

energy()
{
  return energy;
}
