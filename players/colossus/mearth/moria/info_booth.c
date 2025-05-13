#include "/players/colossus/mearth/mroom.h"

reset(arg){
    if(arg) return;
    set_light(1);
    short_desc = "Visitors Information room";
    long_desc =
    "You are in the Visitor Information room where visitors can get some\n"+
    "information on the layout of Rama. A busy looking dwarf sits behind\n"+
    "a counter and when he spots you he gestures towards a plaque hanging\n"+
    "above his head. The room is small and functional, there is a counter,\n"+
    "a bench for visitors, and a small table where some burned out ital\n"+
    "spliffs lay in the ashbowl. Looks like some adventurers have been\n"+
    "here before.\n";

    dest_dir = ({
      MORIA+"/city_entrance", "west",
      MORIA+"/main2", "north",
    });

    ::reset();
    replace_program("/room/room");
}
