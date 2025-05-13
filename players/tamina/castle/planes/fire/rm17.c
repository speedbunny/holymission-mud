inherit "players/tamina/castle/planes/hostiles/fire"

#include "/players/tamina/defs.h"
#include "/players/tamina/castle/planes/fire/lightall.h"


reset(arg)
{
  if (!arg)
    {
      timer  = 5;    	    /*  How often player is burned  */
      damage = 20;	    /*  How much damage player takes from burns  */
      survivor = "ruby";    /*  That object which saves the player from burns */
      envname  = "fire";    /*  Type of alien environment  */
      saymsg   = "is singed by the heat.";
      wrtmsg   = "You writhe in agony as your skin is scorched by the heat!";
      property = ({ "has_fire", "no_teleport" });

      set_light(1);
      short_desc = "On the edge of the Mountain";
      long_desc = 
"    The path you are walking along suddenly comes to the very lip of\n"+
"    the Mountain, leaving you standing at the top of an enormous drop\n"+
"    downwards into the chasm.  The height is making your head spin with\n"+
"    dizziness.  The small bridge that is at your feet looks very strange\n"+
"    and you are not entirely sure if it will hold your weight...\n";

      dest_dir = ({
      FIRE + "rm16", "southeast",
      });

      items = ({
  "minaret",
"It is very tall, reaching up into the clouds.\n"+
"You can now see that the Minaret is suspended in mid-air, hanging in "+
"almost nothingness.  It has a slender bridge leading from the edge of "+ 
"the mountain over the heights of the chasm, to the base of the tower",
  "rocks",
"They are huge rocks which you cannot climb over, which is making the "+
"path wind, and twist and bend",
  "chasm",
"It is a very, very, VERY long way down to the bottom.  In fact, you do "+
"not even see the bottom from where you are..",
  "bridge",
"It is the strangest of bridges that you have ever seen.  It seems to be "+
"formed from the red-rock of the mountainside you are standing on, and "+
"stretches out to the base of the Minaret.  Perhaps you could try and "+
"cross it..",
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
  AA("bridge",  "cross");
}

int bridge(string str)
{
  if (str == "bridge" || str == "the bridge" || str == "over bridge"
                      str == "over the bridge")
  {
    if (TP->DEX < 17)
    {
      write("You honestly do not think that you are confident enough to \n"+
	    "this bridge yet...\n");
        say(TPN+" gets an attack of vertigo.\n");

      return 1;
    }
    write("You step out onto the narrow bridge.\n");
      say(TPN+" steps out onto the bridge.\n");

    call_out("mover", 3);

    return 1;
  }
  else
  {
    NFAIL("Cross what?\n");
    return 0;
  }
}

mover()
{
  write("The bridge sways slightly as it tries to adjust to your weight...\n");

  MPL("onto the bridge#/players/tamina/castle/planes/fire/bridge");

  return 1;
}

