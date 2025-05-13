#include "path.h"
inherit "room/room";


void reset(int arg) {

    ::reset(arg);
    set_light(1);
    short_desc="Danford's Hide-away",

    long_desc=
              "Danford's Hide-away.\n" +
              "There is no real reason for a real desc here\n" +
              "as its just a workroom to idle in.\n";
	      
    dest_dir=({
               "room/church", "church",
               "/players/whisky/guild/room/c10", "guild", 
                "room/wiz/general", "board",
             });

    items=({ 
            "air","It's very thin up here",
            "floor","The floor is dirty",
          });

    property = ({
                 "no_teleport","no_sneak","no_steal",
               });

    replace_program("room/room");
}

init() {
    ::init();
    add_action("_blah","blah");
}
