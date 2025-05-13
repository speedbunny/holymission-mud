
inherit "room/room";  

#include "/players/apollo/private/defs.h"

reset(arg) {
  set_light(1);
  
  short_desc = "Goodie room";

  long_desc = "This is Apollo's goodie room. \n";

  clone_list = ({ 1, 2, "haste_potion", PWOBJ+"haste_potion", 0,
		  2, 7, "heal_potion", PWOBJ+"heal_potion", 0,
		  3, 1, "jeweled_earrings", PWOBJ+"jeweled_earrings", 0,
	/*
		  4, 1, "claws", PGW+"claws", 0,
	*/
		  5, 1, "thammer", PBWOBJ+"thammer", 0, 
		  5, 1, "diring", PLA+"diring", 0,
	 	  6, 1, "wizardshat", PPOBJ+"wizardshat", 0,
		  7, 1, "dshield", PAWEA+"dshield", 0,
		  8, 1, "dplate", PAWEA+"dplate", 0,
	});

  ::reset(arg);
   
}
