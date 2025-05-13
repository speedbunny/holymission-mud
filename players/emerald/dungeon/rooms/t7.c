#define TP this_player()
inherit "room/room";

void reset(int arg) {
        
    if(arg) return;

    set_light(1);

    short_desc="A tunnel";

    long_desc="You have entered a narrow tunnel.  Just above your head " +
              "you can see an iron grate.  Light shines through the " +
              "grate, and you can hear the sounds of footsteps above you.\n";

    dest_dir=({"/players/emerald/dungeon/rooms/t6","northwest",
               }); 

    items=({"grate", "An iron grate.  It looks like it could be moved",
            });

  ::reset(arg);
}

init() {

    ::init();
    add_action("move_up", "open");
    add_action("move_up", "move");
}


int move_up(string str) {

    if (!str || str!="grate") {
        notify_fail("What do you want to move? \n");
        return 0;
    } 
    if (str=="grate") {
        write("Ugh, its heavy, but you manage to move the grate.\n");
        TP->move_player("up#/players/emerald/town/t17");
        return 1;
    }

}
