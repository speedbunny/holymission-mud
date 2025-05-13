inherit "/room/room";

#include "/players/haplo/defs.h"

void reset(int arg) {
    if(!arg) {   
        set_light(1);
        
      short_desc="Desert Path";
        long_desc = "\
You are on the edge of a vast expanse of desert. The only traversable path \
is north between huge sand dunes. The wind is whipping sand all around, and \
the sun is blazing brightly in the sky.\n";

        dest_dir=({
        "/players/haplo/workroom","south",
       "/players/haplo/desert/rooms/path2","north"
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
