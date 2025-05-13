/*
 *   This is the basis of the rooms in the Elemental Plane of Ait.
 *   It is coded with the help of Cashimor's inherits and includes
 *   for alien environments, which are inherently harmful to 
 *   players.  Here, the air on the Plane of course is so thin that
 *   without the protection of the enchanted Necklace (found in Camelot)
 *   the player is hit because he does not have sufficient oxygen to 
 *   breathe, frequency of damage being dependant on the value of the timer.
 */

inherit "/room/room";

#include "/players/tamina/defs.h"

reset(arg) 
{
  if (!arg) 
  {

    timer  = 4;
    damage = 25;
    survivor = "necklace";
    envname  = "air";
    saymsg   = "seems to be unable to breathe.";
    wrtmsg   = "There is not enough oxygen to breathe!";
    property = ({"in_air", "no_teleport" });

  /*
   *  In here you can put the normal configurations of "room/room"
   *  such as :
   *  set_light();
   *  short_desc;
   *  long_desc;
   *    etc...
   */
    set_light(1);
    short_desc = "in the Clouds";
    long_desc = 
"    You stand upon what appears to be a solid enough walkway\n"+
"    made entirely of clouds.  Around you is a sky entirely coloured\n"+
"    white, which is enhanced by the palid colour of the clouds.  The\n"+
"    Air here is extremely thin, and makes breathing very difficult.\n";

  }

}
