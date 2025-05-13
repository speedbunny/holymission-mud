inherit "room/room";

#include "/players/tamina/defs.h"
#include "/players/tamina/castle/planes/fire/lightall.h"


reset (arg) {
  if (!arg) {

      timer  = 3;
      damage = 35;
      survivor = "ruby";
      envname  = "fire";
      saymsg   = "is singed by the heat.";
      wrtmsg   = "You writhe in agony as your skin is scorched by the heat!";
      property = ({ "has_fire", "no_teleport" });

      	set_light(1);
	short_desc = "Crossroads (n,s,e)";
	long_desc = 
"    You have reached a fork in the road where the clear \n"+
"    path extends on to the north, and a rough trail leads\n"+
"    east up into the red mountains.  Of the path ahead, you\n"+
"    see very little, since it swiftly begins to twist into \n"+
"    the distance.  To the west, there is simply the fast-\n"+
"    flowing river of molten lava.  But, you can see a strange\n"+
"    stone protruding up out of the waves.\n"; 

	dest_dir = ({
          FIRE + "rm6","north",
          FIRE + "rm2","south",
          FIRE + "rm5","east",
        });

	items = ({
  "stone",
"  It looks rather strange all alone in the middle of "+
"that pool of molten lava..",
     });
  }
}

void init() {
  ::init();
  add_action("jump","jump");
  if (!nodanger) light_all();
}

jump (str)
{
  if (!str) 
  {
    write("Jump where?\n");
    return 1;
   }

  if (str=="lava" || str=="across lava" || str=="stone" || str=="to stone") 
  {
    if (TP->DEX < 19) 
    {
      write("You don't quite make it over to the stone with your jump!!!!\n\n");
      write("You land with a fierce splash in the pool of molten lava!!\n");
      say(TPN+" jumps straight into the pool of boiling lava!!!!\n");

      HIT(130);

      MPL("into the pool of lava#/players/tamina/castle/planes/fire/lava_pool");

      return 1;

    }
    write("You jump across the boiling pool of lava, and land \n"+
          "safely on the stone.\n");
    say(TPN+" sails across the pool of lava, and lands \n"+
        "magnificently on the stone at the other side!\n");

    MPL("into the air!#/players/tamina/castle/planes/fire/rm3");

    return 1;

  }

}


light_text (str)
{
  write("\nYou find an area of concetrated heat in the room,\n"+
	"and hold the "+str+" there to light it.\n");
  say(TPN+" lights a "+str+",\n"+
      "using the heat of the room.\n");
}
