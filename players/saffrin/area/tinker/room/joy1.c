inherit "room/room";
#include "/players/saffrin/defs.h"

reset(arg) {
    set_light(2);
    short_desc="Joy's Park";
    long_desc=
         "You are standing along the north edge of Joy's Park.  There are large hedges "+
         "scattered about the area.  You can smell the sweet roses blooming on a rose "+
         "bush to the west.  You can hear the trickling of water coming from the south.  "+
         "The wind lightly blows through your hair.\n";
    dest_dir = ({
      TINK+"room/joy12", "south",
      TINK+"room/joy2", "east",
      TINK+"room/joy10", "west",
    });
    items =({
      "hedges", "Large hedges that are dark green.  You can not make out the variety",
      "rose", "A sweet smelling rose",
      "rose bush", "A large rose bush with several buds and roses on it",
      "bush", "A large rose bush with several buds and roses on it",
      "roses", "Several sweet smelling roses",
      "buds", "Small roses trying to bloom into flowers",
    });
    clone_list=({
          1, 1, "robin", TINK+"npc/robin", 0,
    });
    ::reset();
    replace_program("room/room");
}
