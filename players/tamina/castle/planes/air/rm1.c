/*  This is the first Air Room  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {
  if (arg) return ;

      	set_light(1);
	short_desc = "Elemental Plane of Air";
	long_desc = 
"    You have just entered the "+short_desc+".\n"+
"    Here, in the clouds, you can see walkways made out of\n"+
"    clouds moving off into the distance, leading to a strange\n"+
"    looking structure...\n";
	no_obvious_msg = 
"           You can only go east, onto the pathway.\n";

	property = ({"no_teleport"});

	dest_dir = ({
    AIR + "rm2", "east",
	});

	items = ({
    "walkways",
  "Strange magically maintained pathways made entirely out of clouds it "+
  "would appear",
    "structure",
  "You would have to get closer to find out anything more about this..",
    "air", 
  "There is a lot of it here!",
     });

}

init() {
  ::init();
  call_out("neck", 3, TP);
}

neck()
{
  if (!present("silver necklace", TP)) 
  {
    write(
  "You have just entered the "+short_desc+".\n"+
  "From way up here in the clouds, you can see way down...\n"+
  "						       ...down...\n"+
  "						              ...down...\n"+
  "But what is there here to stop you from falling??\n"+ 	
  "You suddenly feel that you should not have ventured here without\n"+ 
  "adequate protection from the elements...There is too much insubstantial\n"
  "Air around here to hold you..!!\n"
  "\n"+
  "      ** You are falling... ** \n"+
  "\n"+
  "      ** You are falling... ** \n"+
  "\n"+
  "      ** You are falling... ** \n"+
  "\n"+
  "      ** You are falling... ** \n"+
  "\n"+
  "      ** You are falling... ** \n"+
  "\n"+
  "You land with a very painful THUMP!!!!!\n");
    say(
  TPN+" looks around nervously, and suddenly finds that "+TP->QPRO+" is not\n"+ 
  "supported by anything.  You then see "+TP->QOBJ+" suddenly fall downwards!!\n"); 

    HIT(175);

    MPL("straight down!#/players/tamina/castle/rooms/p_2");

    return 1;
  }

}
