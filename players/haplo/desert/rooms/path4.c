inherit "/room/room";

#include "/players/haplo/defs.h"

void reset(int arg) {
    if(!arg) {   
        set_light(1);
        
      short_desc="Desert Path";
        long_desc = "\
You are on a path leading through a barren wasted desert. The is no water in \
sight and you can feel the intense heat from the bright sun.\n";

        dest_dir=({
       "/players/haplo/desert/rooms/path3","south",
       "/players/haplo/desert/rooms/path5","north"
        });
           
        items = ({
 "sand","It's a desert what do you think there would be",
  "sun","It is very hot and bright",
 "dunes","They are very high and can't be climbed",
        });
           
        property = ({
        });
    }
    ::reset(arg);
    replace_program("/room/room");
}
