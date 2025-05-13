
inherit "room/room";

#include "/players/apollo/guild/barb.h"

void reset(int arg) {
   set_light(1);

   short_desc = "A well trodden path";

   long_desc = 
              "A well trodden path leads west into the a vast " +
              "open field spotted with trees. To the north, south " +
              "and east appear to be impenetrable forest. Though " +
              "you can make out an animal path east.\n";

   dest_dir = ({
             "/room/giant_conf","east",
	GROOMS+"path2","west",
     });

   items = ({
	"path", "It looks well used",
	"plain", "A wild untamed land",
     });

   replace_program("/room/room");
   ::reset(arg);

}
