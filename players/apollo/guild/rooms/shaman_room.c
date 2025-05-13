
inherit "room/room";

#include "/players/apollo/guild/barb.h"

void reset(int arg) {
   set_light(1);

   short_desc = "The Tent of the Shaman";

   long_desc = 
      "This tent leads into a shrine which is very quiet and glows by the "+ 
      "candles burning in the walls. The shrine is built from stone and " +
      "wood with different carvings in the walls of Barbarian Gods. Barbarians " +
      "can come here seek of healing attention but must give part of their " +
      "treasure to the shrine to show loyalty to their God.\n";

   dest_dir = ({ 
	GROOMS+"camp3","west" 
     });
   
   items = ({
      "shrine", "The shrine is built from wood and stone",
      "carvings", "The carvings are of Barbarian Gods",
      "candle", "The candles are for the shrine, please don't touch", 
     });

   clone_list = ({ 1, 1, "shaman", GMONSTERS+"shaman", 0, });

   replace_program("/room/room");
   ::reset(arg);

}
