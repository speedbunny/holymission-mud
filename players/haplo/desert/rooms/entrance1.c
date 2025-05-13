inherit "/room/room";

#include "/players/haplo/defs.h"

void reset(int arg) {
    if(!arg) {   
        set_light(1);
        
        short_desc = "Island";
        long_desc = "\
You stand before a door leading into what looks like a small pyramid. The \
wind is whipping around you stirring up the desert sand. The sun continues \
to beat mercilessly down on you.\n";

        dest_dir=({
         "/players/haplo/desert/rooms/path5","south",
         "/players/haplo/workroom","north"
        });
           
        items = ({
    "door","The door has some writing and a wierd symbol that should be examined closer",
    "triangle","Probably represents unity of the Eygptian nation. The indents \
seem to draw your attention",
   "symbol","It is the sun with a triangle in the center. There are indents \
at each corner of the triangle",
  "sand","It's a desert what do you think there would be",
  "sun","It is very hot and bright",
  "writing","BEWARE all who would enter this tomb lest the Pharoah's Curse \
take you. For all who enter through this door shall not be able to exit here",
   "indents","You might try pushing the indents on the triangle's corners",
   "corners","They are triangle corners! What do you expect? Try looking at \
              something else",
   "sun","Probably represents Ra the Eygptian Sun god"
        });
           
        property = ({
        });
    }
    ::reset(arg);
}
