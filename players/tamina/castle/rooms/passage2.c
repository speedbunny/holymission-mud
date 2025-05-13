/*  This is the Secret Passage  */

inherit "room/room";
#include "/players/tamina/defs.h"

object ob;

void reset(int arg) 
{
  ::reset(arg);
  if (!ob = present("demon") && !living(ob))
  MO (CLO (CMONS + "s_demon"), TO);

  if (arg) return 0;

     set_light(-2);
     short_desc = "Dark Passage ";
     long_desc =
   "You are walking along a very dusty, and very cramped Secret Passage.\n"+ 
   "The light that you have shows very little of interest in the corridor.\n"+
   "The passage continues on ahead...\n"; 

     dest_dir = ({
   CROOMS + "passage3","northeast",
   CROOMS + "passage","south",
     });

     smell = "Very musty, and very old..";

}

move(str) 
{
  object demon;

  if (!str) 
    str = query_verb();
  if (str == "south") 
    return ::move(str);

  demon = present("Shadow Demon");
  if (demon) 
  {
     write("The Demon of Shadow bars your path!!\n");
     demon->attack_object(TP);
     return 1;
  }
  if (str = "northeast") 
    return ::move(str);
}
