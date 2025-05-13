
/* sislnd6.c */

inherit "/room/south/island";
#include "_defs.h"

string add_long()
{
     return (
     "You are standing on the shore of the Isle of the Magi.\n" +
	  "The shore of the island continues northeast and southwest from here.\n" +
	  "To the west, a hill rises up to the ancient ruins of the Tower\n" +
	  "of Arcanarton, the archmage who used to live on this island.\n" +
	  "To the north, you can see some sort of crumbled monument.\n"); 
}

string *add_items()
{
   return ({
   "ruin","The ruins of the tower of Arcanarton",
   "ruins","The ruins of the tower of Arcanarton",
   "monument","To the north you see a crumbled monument",
    });
}

string *add_dirs()
{
   return ({
   PATH+"sislnd5","north",
   PATH+"sislnd16","west",
   PATH+"sislnd5","northeast",
   PATH+"sislnd7","southwest",
   });
}
void get_objects()
 { if (!find_living("Nun Anica")) 
   { 
     move_object(clone_object("/players/whisky/guild/monster/anica"),
         this_object());   
       }
 }
