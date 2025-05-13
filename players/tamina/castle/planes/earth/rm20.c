inherit "/room/room";

#include "/players/tamina/defs.h"

object arthur, bedevere, gawain, lancelot;

void reset(int arg)
{
  ::reset(arg);
  if (arg) return 0;  

    property = ({ "has_earth", "no_teleport" });
    smell = "The huge amounts of Earth gets clogged up your nose!\n";

	set_light(1);
	short_desc = "";
	long_desc = 
"    You have reached a dead-end here.\n"+
"    The tunnel simply ends in complete and unblemished rock.\n";

     	dest_dir = ({
      EARTH + "rm19", "north",
	});

	items = ({
  "tunnel",
"It is milky-white coloured, and very smooth",
  "walls",
"They are similar to ivory",
      });

  arthur   = CLO(CMONS + "arthur");
  bedevere = CLO(CMONS + "bedevere");
  gawain   = CLO(CMONS + "gawain");
  lancelot = CLO(CMONS + "lancelot");

  MO(arthur,   TO);
  MO(bedevere, TO);
  MO(gawain,   TO);
  MO(lancelot, TO);
}
