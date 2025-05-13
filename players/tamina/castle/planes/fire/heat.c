/*   This is the basis of the rooms in the Elemental Plane of Fire.
 *   It is coded with the help of Cashimor's inherits and includes
 *   for alien environments, which are inherently harmful to 
 *   players.  Here, the heat on the Plane is so intolerable that
 *   without the protection of the enchanted Ruby (found in Camelot)
 *   the player is burned constantly, each time being dependant
 *   on the value of the timer.   
 */

inherit "players/tamina/castle/planes/fire/hostile_fire";

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

  /*
   *  In here you can put the normal configurations of "room/room"
   *  such as :
   *  set_light();
   *  short_desc;
   *  long_desc;
   *    etc...
   */

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
