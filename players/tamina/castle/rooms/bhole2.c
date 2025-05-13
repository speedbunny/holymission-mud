/*  This is the Thing Hole  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {
  if (arg) return ;

      	set_light(-2);
	short_desc = "A Dark Hole";
	long_desc = 
"The cramped tunnel continues along until you reach what appears to be\n"+
"a turn towards the east.  Here, in the pitch darkness, you can feel\n"+
"the cold air waft around you, tingling the sweat on your neck.\n";

	dest_dir = ({
          CROOMS + "bhole3","east",
          CROOMS + "bhole1","south",
        });

}

init() 
{
  ::init();
  call_out("growl", 8, TP);
}

growl()
{
  TRM (TO,
   "A deep, reverbating growl sends shivers up your spine....\n");

  return 1;
}
