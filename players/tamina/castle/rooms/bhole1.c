/*  This is a hole under the Bed  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {
  if (arg) return ;

      	set_light(-2);
	short_desc = "Hole under the Bed";
	long_desc = 
"You have just entered a very dark hole under the bed.\n"+
"There is very little to be seen here, except the small, \n"+
"cramped passageway that stretches on to the north here.\n";

	dest_dir = ({
          CROOMS + "bhole2","north",
        });

}

init() 
{
  ::init();
  AA("climb",  "climb");
  AA("no_up",     "up");
  call_out("growl", 5, TP);
}

int climb(string str)
{
  if (!str || str == "back" || str == "up")
  {
    write("You climb back up through the hole.\n");
    MPL("up through the hole#/players/tamina/castle/rooms/ebed1");
    return 1;
  }
  else
  {
    NFAIL("Climb where?\n");
    return 0;
  }
}

growl()
{
  TRM (TO,
   "You suddenly hear a low, animalic growl....\n");

  return 1;
}

no_up()
{
  write("You are going to have to climb up here.\n");
  return 1;
}

