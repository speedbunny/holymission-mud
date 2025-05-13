/* tunnel3 */

// 101197: Sauron: Removed id 'ring' (and changed associated descs) as the
//                 'ring' id didn't work if the player had a ring in their
//                 inventory (eg, a wedding ring).

inherit "/room/room";
#include "defs.h"

int rope;

void reset(int flag)
{
    ::reset(flag);
    if (flag == 0)
    {
         set_light(0);
	 short_desc = "Hole";
         long_desc = BS(
	 "There is a big hole here, and some kind of iron rings in the wall. "+
	 "It is should be possible to pass the hole.");
         dest_dir = 
         ({
            PATH+"tunnel2","south",
            PATH+"tunnel4","north",
            PATH+"tunnel8","down",
         });
         items = 
         ({
            "rings","Sturdy iron rings, fastened to the wall",
         });
         rope = 0;
    }
}

int move(string arg) 
{
    if (!arg)
         arg = query_verb();

    if (arg == "down" && !rope) 
    {
        write("You would fall down the hole and possibly hurt yourself.\n");
	return 1;
    }
   return ::move(arg);
}

int tie(string where)
{
   if (!rope)
   { 
       rope = 1;
       return 1;
   }
   return 0;
}

int id(string arg) 
{
    return arg == "rings";
}

int untie(string where) 
{
    if (rope)
    {
       rope = 0;
       return 0;
    }
    return 1;
}

int query_rope() 
{
    return rope;
}
