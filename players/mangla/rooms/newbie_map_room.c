#include "/sys/levels.h"
inherit "room/room";

#include "/players/mangla/defs.h"

int _read(string str) {

    if(str == "topics") {
        write("Topics are newbie and guild.\n");
        return 1;
    }
    if(str != "newbie" && str != "guild") {
        notify_fail("Read newbie or read guild?\n");
        return 0;
    }
    if(str == "newbie") {
        cat("/players/mangla/rooms/newbie_map");
        return 1;
    }
    cat("/players/mangla/rooms/guild_map");
    return 1;
}

void reset(int arg) {

    ::reset(arg);
    if(arg) return;

    short_desc = "Newbie Map Room";

    long_desc = "In this room is a large collection of maps, some " +
                "of which are available for you to read. " +
                "The topics available are for newbie and " +
                "guild. To view them just 'read'.\n";

    set_light(1);

    items = ({ 
            });

    property = ({
                 "no_teleport",
                 "no_clean_up",
                 "no_sneak",
                 "no_steal",
                 "no_fight",
               });

    dest_dir = ({

                  "players/moonchild/newbie/hut", "down",
               });

}

init() {
  if(TP->LEVEL > 5 && TP->LEVEL < L_APPR) {
    write("This place is for newbies only!\n");
    TP->MOVEP("down#players/moonchild/newbie/hut");
    return;
  }
  ::init();
  add_action("_read", "read");
}

