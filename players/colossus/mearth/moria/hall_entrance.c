#include "/players/colossus/mearth/mroom.h"

reset(arg){
    ::reset(arg);
    if(arg) return;
    set_light(0);
    short_desc = "Halls of Moria";
    long_desc =
    "You are in the halls of Moria. This place looks like it's been a\n"+
    "battle field for dwarves and invaders. Even now you see the skeletons\n"+
    "of dwarves and orcs in their death poses. The truly curious thing is \n"+
    "that the corpses have not been looted. Then you remember stories and\n"+
    "legends about how the reigning king of Moria cursed this place and all\n"+
    "who would loot it. Apparently the orcs believed it enough to keep even\n"+
    "their grubby hands off.\n";

    dest_dir = ({
      MORIA+"/entrance", "out",
      MORIA+"/hall1", "northwest",
      MORIA+"/road", "northeast",
    });

    items = ({
      "skeletons", "Skeletons of orcs and dwarves locked in combat",
      "dwarves", "The skeletons of the heroic dwarves that attempted to protect Moria",
      "orcs", "Disgusting and filthy orcs that have long since rotted",
    });
}
