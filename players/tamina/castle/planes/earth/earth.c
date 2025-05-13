/*   This is the basis of the rooms in the Elemental Plane of Earth.
 *   It is coded with the help of Cashimor's inherits and includes
 *   for alien environments, which are inherently harmful to 
 *   players.  Here, the heat on the Plane is so intolerable that
 *   without the protection of the enchanted Diamond (found in Camelot)
 *   the player finds breathing difficult, and is hit as a consequence, 
 *   each time being dependant on the value of the timer.   
 */

inherit "/room/room";

#include "/players/tamina/defs.h"


reset(arg)
{
  if (!arg)
    {
      timer  = 5;    	         /*  How often player is harmed   */
      damage = 30;	         /*  How much damage player takes */
      survivor = "diamond ring"; /*  That object which saves the player */
      envname  = "earth";        /*  Type of alien environment  */
      saymsg   = "is crushed by the Earth.";
      wrtmsg   = "The immense weight of Earth crushes down on you!";
      property = ({ "has_earth", "no_teleport" });
      smell = "The huge amounts of Earth gets clogged up your nose!\n";

  /*
   *  In here you can put the normal configurations of "room/room"
   *  such as :
   *  set_light();
   *  short_desc;
   *  long_desc;
   *    etc...
   */

	set_light(0);
	short_desc = "Underground";
	long_desc = 
"    You are underground, in a seeming maze of tunnels.\n";

    }
}
