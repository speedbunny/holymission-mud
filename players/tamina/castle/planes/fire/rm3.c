inherit "room/room";
int searched;

#include "/players/tamina/defs.h"
#include "/players/tamina/castle/planes/fire/lightall.h"


reset(arg)
{
  if (!arg)
    {
      timer  = 2;    	    /*  How often player is burned  */
      damage = 40;	    /*  How much damage player takes from burns  */
      survivor = "ruby";    /*  That object which saves the player from burns */
      envname  = "fire";    /*  Type of alien environment  */
      saymsg   = "is singed by the heat.";
      wrtmsg   = "You writhe in agony as your skin is scorched by the heat!";
      property = ({ "has_fire", "no_teleport" });

      	set_light(1);
	short_desc = "A Stone";
	long_desc = 
"    You manage to jump across the boiling lava, and \n"+
"    land on the stone.  All you can see here is bare\n"+
"    stone, in the midst of a river of lava...\n";

	items = ({
  "stone",
"A large, knobbled hunk of rock, in the middle of a river "+
"of lava.  You do notice that one knobble does seem irregular..",
  "knobble",
"Simply looking at it won't suffice!!  You'll have to search "+
"harder than that!!",
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
  add_action("jump","jump");
  add_action("search","search");
  add_action("enter_it","enter");
  add_action("enter_it","down");
  if (!nodanger) light_all();
}


jump (str) 
{
  if (!str) 
  {
    write("Jump where?\n");
   return 1;
  }

  if (str == "across lava" || str == "back") 
  {
    if (TP->DEX < 20) 
    {
      write("You don't quite make it over to the stone with your jump!!!!\n\n");
      write("You land with a fierce splash in the pool of molten lava!!\n");
      say(TPN+" jumps straight into the pool of boiling lava!!!!\n");

      HIT(150);

      MPL("into the pool of lava!!!#/players/tamina/castle/planes/fire/lava_pool");

    return 1;

    }
    write("You jump across the boiling pool of lava, and land \n"+
          "safely back on the other side.\n");
    say(TPN+" sails across the pool of lava, and lands \n"+
        "perfectly back on the other side!\n");

    MPL("into the air!#/players/tamina/castle/planes/fire/rm4");

  return 1;
  }

}

search (str) 
{
  if (str != "knobble")
    return NFAIL("That cannot be searched here!\n");

  if (searched) 
  {
    write("But you have already searched the stone!!\n");
    say(TPN+" searches the stone again, but strangely enough,\n"+
        "comes up with nothing new...\n");

  return 1;
  }

  write("You search around the knobble, and see that \n"+
        "it can be moved aside.  On doing so, you reveal\n"+
        "a passage down...\n");
  say(TPN+" snoops around a particular knobble in the surface\n"+
      "of the stone, and moves it aside to reveal a passage down!!\n");

  searched = 1;

  return 1;

}

enter_it (str) 
{
  if (!str) 
  {
    write("Enter what?\n");
    return 1;
  }

  if (str == "passage" || str == "hole" || str == "stone")
  {
    write("You slip down into the passage way..\n");

    MPL("down into the darkness of the passageway below#/players/tamina/castle/earth/rm1");

  return 1;
  }  
  else
    write("That cannot be entered here.\n");
    return 1;
}
