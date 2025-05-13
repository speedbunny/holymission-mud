
inherit "room/room";

#include "/players/apollo/guild/barb.h"
 
void reset(int arg) {
   set_light(1);

   short_desc = "In the tent of the Barbarain Chief";

   long_desc = 
      	"This is the tent of the Chieftan of the Horde. Among "+
	"his other duties, the Chieftan preforms marriages "+
	"between members of the Horde.\n";

   dest_dir = ({
	GROOMS+"camp5","east"
     });

   clone_list = ({ 1, 1, "captain", GMONSTERS+"captain", 0, });

   replace_program("/room/room");
   ::reset(arg);

}
