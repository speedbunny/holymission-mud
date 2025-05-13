#include "/players/ted/defs.h"

inherit "room/room";

reset(arg) {
    set_light(1);
    short_desc = "Unused Room";
    long_desc =
    "This room is totally bare. The only decoration is dust.\n"+
    "Small footprints form a path around the room and then exit.\n";
    dest_dir = ({
      FIRE + "ehall4","north"
    });
    items = ({
      "path","The footprints circle the room, then leave",
      "footprints","The footprints circle the room, then leave",
      "dust","The footprints circle the room, then leave"
    });
    replace_program("room/room");
}
