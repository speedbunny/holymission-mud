inherit "room/room";

#include "/players/tamina/defs.h"
#include "/players/tamina/castle/planes/fire/lightall.h"

reset(arg)
{
  if (!arg)
    {
        timer  = 5;
        damage = 20;
        survivor = "ruby";
        envname  = "fire";
        saymsg   = "is singed by the heat.";
        wrtmsg   = "You writhe in agony as your skin is scorched by the heat!";
        property = ({ "has_fire", "no_teleport" });

      	set_light(1);
	short_desc = "Along trail on Mountains (n,w) ";
	long_desc = 
"    You have successfully reached the top of the moutain in this\n"+
"    Plane of Fire, and the view that you can see from such an\n"+
"    elevation is truly strange to say the least.  It is so unnatural\n"+
"    that it takes almost all your concentration keeping your balance.\n"+
"    All about you is rock, each in varying shades and tones of red,\n"+ 
"    brown or crimson, under a red-stained sky with no moon, sun, or stars.\n"+ 
"    Great ruptures in the turbulent landscape can be seen far in the \n"+
"    distance, where mountainous forms have thrust themselves up into a \n"+
"    forced existence.  Below you, the cavernous canyon delves deep\n"+
"    into the bowels of this land, the bottom of it being far out of \n"+
"    your sight.  To the northwest, you can vaguely make out a path \n"+
"    amongst boulders on the opposite side of the chasm.  To the north,\n"+
"    you can see not only the continuing path, but also a large tower,\n"+
"    standing tall and  thin as a minaret, alone, marked dramatically \n"+
"    against the background, stretching high into the sky.\n"; 

	dest_dir = ({
          FIRE + "rm13","north",
          FIRE + "rm8","west",
        });

	items = ({
  "minaret",
"  A smooth, spindly tower reaching the puffy red clouds",
  "chasm",
"  A great rift in the landscape the size of a canyon",
  "canyon",
"  A great rift in the landscape the size of a chasm",
  "boulders",
"  Enormous rocks that have fallen, or rolled from somewhere",
  "mountains",
"  A large, protruding rock, thrust up from the landscape",
  "sky",
"  A peculiar shade of red, which makes you feel decidedly uneasy",
  "clouds",
"  Small, puffy cumuli, which match the red tint to everything",
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

init() {
  ::init();
  if (!nodanger) light_all();
}
