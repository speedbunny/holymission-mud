/*  This is the first Bedchamber in the East Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";
object bed;

reset(arg) {
  if (arg) return ;

      	set_light(1);
	short_desc = "Bed Chamber";
	long_desc = 
"This room is surprisingly clean, compared to the dust and dirt in the \n"+
"corridor outside.  However, on the open window, you can see signs of \n"+
"a lack of cleaning.  A cool breeze flutters in through the small gap in\n"+
"the wall, airing the room pleasantly.  There is a four-poster bed against\n"+ 
"the wall to the left, with a screen pulled round it.  There is also a\n"+  
"chest at the foot of the bed.\n";
	no_obvious_msg = "";

	items = ({
  "screen",
"Perhaps if you pulled it aside, you would get a better view of the bed",
  "window",
"The open window shows a large expanse of green rolling hills, with the "
"occasional copse of beech or alder",
  "bedroom",
"It is a much more cleaner room than the others in this castle.  You would "
"think that someone was living here at the moment..",
  "chest",
"It seems to be an old, worthless chest, which you don't want to waste "+
"your time over",
     });

  bed = CLO (COBJ + "bed");
  MO (bed, TO);

}
