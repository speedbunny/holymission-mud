inherit "room/room";

#include "/players/mangla/defs.h"
#define this_guild GM->query_number("jedi")


void reset(int arg) {

    object ob;

    ::reset(arg);

    if(arg)
        return;

    short_desc="Storage";

    long_desc="In this room are stored many things that you might\n" +
              "need on your journies. You may access these things\n" +
              "through a dispenser that is sitting in the middle of\n" +
              "the room.\n";

    set_light(1);

    property=({"no_telport","no_fight","no_steal"});

    smell="\nYou are overwhelmed by the lack of scents here.\n";

    dest_dir=({"/players/mangla/guild/rooms/caperoom","east",
              });

    ob = clone_object(PATH + "guild/dispenser");
    MOVE(ob,TO);

}

void init() {

    ::init();
    if((TPL < 30) && (TP->query_guild()!=4)) {
        write("You are not allowed in this place!\n");
        TP->MOVEP("is moved#players/redsexy/jedi/areas/guild/room");
    }
}
