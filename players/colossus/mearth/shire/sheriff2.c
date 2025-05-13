#include "mroom.h"

void reset(int arg){
    int i;
    if(!present("shiriff")) {
	for(i=0;i<6;i++)
	    move_object(clone_object(SHIRE+"/shiriff2"), this_object());
    }
    if(arg) return;
    set_light(1);
    short_desc = "Shiriff outpost";
    long_desc =
    "Whitewashed walls and a large room by hobbit standards\n"+
    "describe the reception area of the main shiriff outpost.\n"+
    "Tiny chairs and tables lay all about the room and a few\n"+
    "wanted posters hang here and there. To the south lies more\n"+
    "of the shiriff outpost.\n";
    dest_dir=({
      SHIRE+"/sheriff1", "west",
      SHIRE+"/quest/hall", "south",
    });

    items=({
      "outpost", "The main shiriff outpost",
      "walls", "The walls are clean and whitewashed",
      "chairs", "The chairs are small and built for function\n"+
      "and not comfort",
      "tables", "The tables are small wooden functional affairs",
      "posters", "Some of those posters date back two decades",
    });
}
