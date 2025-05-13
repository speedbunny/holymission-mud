/* Chomp's room - 1/6/95 */

#include "/players/chomp/kdland/def.h"
inherit "room/room";

reset(arg)  {
     if (arg) return;
        set_light(1);
        short_desc= "Temporary PRIVATE room !!!";
        long_desc=
  "GO AWAY !!! Unauthorised entry can be prosecuted.\n"+
  "This is a temporary room created only for PRIVATE USES by Chomp !!!\n"+
  "This room is necessary, since he needs to go to Ezo island frequently,"+
  "as he is re-coding it on the Wildsow site.\n";
        
        dest_dir=({
            "players/patience/ezo/cave/cave20", "cave",
            "players/patience/ezo/forest/f1", "forest",
            "players/patience/ezo/coast/c1", "junk",
            "players/patience/ezo/ryuworld/cd", "kojin",
            "players/patience/ezo/meadow29", "hole",
            "players/patience/ezo/coast/rf21", "ryu",
            "players/patience/ezo/coast/sh1", "shore",
            "players/patience/ezo/forest/f26", "temple",
            "players/patience/ezo/forest/cave1", "kat",
            "players/patience/ezo/cave17", "c17",
	    "players/patience/ezo/conn1", "conn",
	    "players/patience/ezo/snail_hole2", "snail",
	    "players/patience/ezo/island_link/link1", "link1",
	    "players/patience/ezo/island_link/cave_fisher", "cafi",
	    "players/patience/ezo/island_link/dt1", "dt1",
		      });
        items=({
  "ground","The ground is shaking, so you better get outta here !",
              });
        smell = "The air is hot like hell !";
  
     }

init()
{
  ::init();
}
