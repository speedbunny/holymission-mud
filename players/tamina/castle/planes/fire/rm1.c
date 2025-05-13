/*  This is the first Fire Room  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {
  if (arg) return ;

      	set_light(1);
	short_desc = "Elemental Plane of Fire";
	long_desc = 
"    You have just entered the "+short_desc+".\n"+
"    The heat is tremendous here: great pools of lava lie bubbling\n"+
"    beside the small path that you are currently standing on. The air\n"+
"    is so stifling, that is very difficult to breathe, as well as the\n"+
"    amount of soot getting into your lungs...You wonder why you ventured\n"+
"    into such a dangerous area.\n";

	dest_dir = ({
          FIRE + "rm2","north",         
     });

	property = ({"no_teleport"});

	smell = "<cough> The soot makes you gag when you try to smell!";

	items = ({
    "pools",
  " You think it would be unwise to try and swim in these pools",
    "air", 
  " It is wavering in the intense heat",
     });

}

init() {
  ::init();
  if(!present("ruby", TP)) {
    write(
  "You have just entered the "+short_desc+".\n"+
  "But what is there here to protect you from the heat??\n"+
  "You suddenly feel that you should not have ventured here without\n"+ 
  "adequate protection from the elements...The heat is totally unbearable!!\n");
    say(
  TPN+" suddenly starts to turn a distinctly dangerous shade of pink...\n"+ 
  "which turns to red...which turns to purple...which turns eventually turns to\n"+ 
  "a nasty, burnt-flesh-shade..."+TP->QOBJ+" starts to smell as though "+TP->QOBJ+"\n"+ 
  "has been cooked for several hours!!\n"); 

    HIT(150);

    MPL("in a puff of smoke!#/players/tamina/castle/rooms/p_2");

    return 1;
   }

}
