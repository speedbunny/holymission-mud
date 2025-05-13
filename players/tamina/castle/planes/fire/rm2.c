/*  This is the second room in the Elemental Plane of Fire  */

inherit "room/room";

#include "/players/tamina/defs.h"
#include "/players/tamina/castle/planes/fire/lightall.h"


reset (arg) {
  if (!arg) {
      timer  = 4;
      damage = 25;
      survivor = "ruby";
      envname  = "fire";
      saymsg   = "is singed by the heat.";
      wrtmsg   = "You writhe in agony as your skin is scorched by the heat!";
      property = ({ "has_fire", "no_teleport" });


      	set_light(1);
	short_desc = "Plane of fire (n,s)";
	long_desc = 
"    The heat is almost unbearable here, but you feel a \n"+
"    protective power eminating from the ruby you hold in\n"+ 
"    your palm.  You can see molten rivers of lava run\n"+
"    alongside the slender path that you are walking on.\n"+
"    Great mountains of red rock shimmer in the distance,\n"+
"    in which, you can also just see paths winding in and out.\n";

	dest_dir = ({
          FIRE + "rm4","north",
          FIRE + "rm1","south",
        });
	
	smell = "The soot makes you cough when you try to smell!\n";

	items = ({
  "mountains",
" Huge erections thrust up from the boiling pits of "+
"lava and magma",
  "river",
" Fast flowing rivers that speed past you, with great puffs "+
"of steam billowing around you",
  "path",
" It is a small pathway made of a very fine sand, "+
"with steam vapour rising from your feet.  Without "+
"the protection from the ruby, you think you would "+
"not survive here for long",
     });

   }

}

light_text (str)
{
  write("\nYou find an area of concetrated heat in the room,\n"+
	"and hold the "+str+" there to light it.\n");
  say(TPN+" lights a "+str+",\n"+
      "using the heat of the room.\n");
}

init() 
{
  ::init();
  if (!nodanger) light_all();
}


