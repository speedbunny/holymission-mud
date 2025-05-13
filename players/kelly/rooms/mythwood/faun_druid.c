inherit "room/room";

#include "/players/mangla/defs.h"

object druid;

int _buy(string str) {

    object obj;

    if(!present("druid",TO))  {
        write("The druid isn't in.\n");
        return 1;
    }
    if(str!="salve" && str!="glowworm") return 0;

    if(str == "glowworm" && TP->query_money() > 150) {
        obj=clone_object("/players/kelly/obj/glowworm");
        MOVE(obj,TP);
        TP->add_money(-150);
        write("The druid searches in his shelves and finally he finds one.\n" +
              "He says: Here it is!\n");
    }
    if(str == "salve" && TP->query_money() > 200) {
        obj=clone_object("/players/kelly/obj/salve");
        MOVE(obj,TP);
        TP->add_money(-200);
        write("The druid pulles out a box and takes a tube of salve out of it.\n");
    }
    return 1;
}

int _read(string str) {

    if(str != "sign") return 0;
        write("The sign is something like a price-list.\n\n" +
              "It reads: Druid's original mistletoe salve - 200 coins\n" +
              "          A trained glowworm               - 150 coins\n\n");
    return 1;
}

void reset(int arg) {

    if (arg) return;
    set_light(1);
    short_desc="The Faun-druid's magic shop";
    long_desc="You are in the Faun-druid's magic shop.\n"+
              "There are hundreds of shelves. A sign is attached at the "+
              "counter.\n";
    dest_dir=({
               "players/kelly/rooms/mythwood/faun_mark2","north",
               "players/kelly/rooms/mythwood/faun_drpr","east",
             });
    items=({
            "sign","Perhaps you should read it",
            "shelves","You wonder how anybody is able to find something in that mess",
          });

    druid=clone_object("players/kelly/monster/druid");
    MOVE(druid,TO);
}

init() {
    ::init();
    add_action("_buy","buy");
    add_action("_read","read");
}

