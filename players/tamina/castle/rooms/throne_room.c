#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {
  if (arg) return;

     set_light(0);
     short_desc = "Regal Throne Room ";
     long_desc = 
"This is a long corridor which swiftly gets very dark, and very dusty.  The\n"+
"passage itself proceeds long into the gloom ahead which your torch does not\n"+ 
"yet illuminate...\n"+ 
"But you proceed on nonetheless, and eventually arrive in a cavernous room\n"+
"with the most striking feature being two large thrones sitting at the far\n"+
"end of the room.  This room is similar in style to the previous Reception\n"+
"Area, in that there are filthy windows lining the side walls, and several\n"+
"candle-holders swinging from the ceiling.  In fact there is one that would\n"+
"appear to have fallen to the ground, and is lying in a broken heap in the\n"+
"middle of the room.\n";

     dest_dir = ({
   CROOMS + "reception","south",
   CROOMS + "junction","east",
     });

     items = ({
  "thrones",
"There are two of these enormous, grand chairs.  But they now seem "+
"to have lost some of their grandeur as time has taken its toll", 
  "candle-holder",
"Something like a chandelier, but without any candles",
  "windows",
"They are so dirty that you cannot see much through them, and very little "+
"light is let into the room",
  "heap",
"You see what appears to be the leftovers of one of the holders which has "+
"fallen from the ceiling, and smashed into many pieces",
     });

    	clone_list = 
  ({ 1, 3, "retainer", DARK + "retainer", 0, });

    	::reset();

	RPR("room/room");
}
