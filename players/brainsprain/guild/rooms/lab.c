
#include "/players/brainsprain/guild/headers.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Laboratory";
    long_desc =
    "Bottles and beakers, chemicals still dripping from them, create an almost\n"
    +"unimaginable clutter.  A nearly imperceptible path through the mess leads\n"
    +"to the center of the room, where someone has been experimenting recently.\n";
    items = ({
      "bottles","Foul-smelling liquids of blue, green, and amber drip to the floor",
      "beakers","Disgusting yellow chemicals molder inside"
    });
    dest_dir=({
      ROOMDIR+"alch_shop","down"
    });
    clone_list = ({

      2,1,"pot",POIDIR+"pot",0,

      3,1,"parchment",POIDIR+"parchment",0,

      4,1,"vellum",POIDIR+"vellum",0,
    });
    ::reset();
    replace_program("room/room");
}
