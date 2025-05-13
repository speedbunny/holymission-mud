#include "/players/tamina/defs.h"

inherit "room/room";

int connected_to_center() {   return 1;  }

void reset(int arg) 
{
  if (arg) return 0;

  set_light(1);
  short_desc = "Junction between Tamina's Worlds";
  long_desc = 
"This is a junction between worlds, where Elemental\n"+
"Guardians stalk the unwary... From here, you can\n"+
"see a lot of gateways leading to different time lines,\n"+
"and different environments.\n";

  dest_dir = ({
    AIR + "rm1",                 "air",
    "/players/axlrose/workroom", "axlrose",
    "/players/blade/workroom",   "blade",
    "/players/cookie/workroom",  "cookie",
    CROOMS + "entrance",         "camelot",
    EARTH + "rm1",               "earth",
    "/players/nokey/centralroom","centre",
    FIRE + "rm1",                "fire",
    "/players/gandalf/workroom", "gandalf",
    "/players/haplo/workroom",   "haplo",
    RROOMS + "gates",            "imladris",
    PATH + "workroom",           "tamina",
    "/players/ted/workroom",     "ted",
    WATER + "rm1",               "water",
		});

    ::reset(arg);

    RPR("room/room");
}
