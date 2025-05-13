
/* tunnel 9  coded to room/room Whisky 22.02.95 */

inherit "/room/room";
#include "defs.h"

int rope;

void reset(int flag)
{
     ::reset(flag);
     if (flag == 0)
     {
         short_desc = "In front of a Hole in the ceiling";
         long_desc = "There is a big hole in the ceiling.\n"+
                     "@@chk_rope@@";
         dest_dir =
         ({
            PATH+"tunnel10", "west",
	    PATH+"tunnel14", "east",
	    PATH+"tunnel8",  "up",
         });
         rope = 0;
     }
}

string chk_rope()
{
    if ((PATH+"tunnel3")->query_rope())
	return "There is a rope hanging down the hole !\n";
    return "";
}

static move(string arg)
{
    if (!arg) 
         arg = query_verb();

    if (!rope && arg=="up" && !(PATH+"tunnel3")->query_rope() ) 
    {
        write("You can't go stright up with some kind of support.\n");
	return 1;
    }
    return ::move(arg);
}



