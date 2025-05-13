#include "/players/colossus/mearth/mroom.h"

reset(arg){
    int i;
    if(!present("shiriff")) {
	for(i=0;i<6;i++)
	    move_object(clone_object(SHIRE+"/shiriff2"), this_object());
    }
    if(arg) return;
    set_light(1);
    short_desc = "Shiriff outpost";
    long_desc =
    "This is the main office of the shiriffs. Several shiriffs block the way\n"+
    "into the office where the thain is. The thain apparently doesn't like\n"+
    "unwanted and uninvited guests to drop in on him. It looks like you cannot\n"+
    "go further in unless you somehow get past these shiriffs.\n";

    dest_dir=({
      SHIRE+"/sheriff1", "west",
      SHIRE+"/thain_office", "east",
    });

    items=({
      "outpost", "The main shiriff outpost",
    });
}
