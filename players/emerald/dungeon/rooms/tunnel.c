#define TP this_player()
inherit "room/room";

void reset(int arg) {
        
    if(arg) return;

    set_light(1);

    short_desc="A tunnel";

    long_desc="You have entered a narrow tunnel.  Just above your head " +
              "you can see an iron grate.  Light shines through the " +
              "grate, and you can hear the sounds of metal clinking on " +
              "metal.\n";

    dest_dir=({"players/emerald/dungeon/rooms/ap2", "southeast",
               }); 

    items=({"grate", "An iron grate.  It looks like it could be moved",
            });

}

init() {

    ::init();
    add_action("open", "open");
    add_action("move_up", "move");
}

int open(string str) {
    if (!str || str!="grate") {
        notify_fail("What do you want to open? \n");
        return 0;
    }
    if (str=="grate") {
        write("Ugh, it's heavy, but you manage to open the grate.\n");
        TP->move_player("up#/players/emerald/castle/rooms/groom5");
    }
    return 1;
}

int move_up(string str) {

    if (!str || str!="grate") {
        notify_fail("What do you want to move? \n");
        return 0;
    } 
    if (str=="grate") {
        write("Ugh, its heavy, but you manage to move the grate.\n");
        TP->move_player("up#/players/emerald/castle/rooms/groom5");
        return 1;
    }

}
