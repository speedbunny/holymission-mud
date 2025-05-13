/*  The Hut  */

#include "/players/tamina/defs.h"

inherit "room/room";
  object ob;

void reset(int arg) 
{
  ob = present("guinever");
  if (!ob || !living(ob))
  MO (CLO (CMONS + "guinever"), TO);

  if (arg) return ;

      	set_light(1);
	short_desc = "In a little Hut(out)";
	long_desc = 
"You have just entered a dim little hut.\n"+
"Around you are several signs of rustic life, where simple people\n"+
"live, such as a straw pallet, a hearth, a small wooden table with\n"+
"wooden benches, and bare wooden walls.  Windows let in some light into\n"+
"this otherwise dim little shack.\n";
	no_obvious_msg = "";

	smell = "It smells very natural, very earthy in here.\n";

	items = ({
  "hearth",
"This is where a fire would be kept.  There is no fire lit at the moment",
  "table",
"A small, but functional table resting against the wall to your left",
  "benches",
"They are sitting beneath the table, waiting to be pulled out at meal times",
  "walls",
"Not surprisingly, they are made completely out of wood here",
  "windows",
"Small outlets looking into the Dread Forest",
  "pallet",
"This is merely a sheet covering a bed of old straw.  It does not look "+
"entirely comfortable",
     });

}

init() 
{
  ::init();
  AA("_out",  "out");
  AA("_out",  "leave");
}

int _out()
{
  write("You leave the small hut.\n");
  MPL("the hut.#/players/tamina/castle/rooms/forest/out_hut");

  return 1;
}
