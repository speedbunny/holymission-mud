inherit "room/room";

void reset(int arg) {
        
    if(arg) return;

    set_light(1);

    short_desc = "Mountain top with a small grate in the ground";

    long_desc = 
               "You are on top of a mountain. There is a small " +
               "plateau to the east and you can see a higher plateau " +
               "that looks outta reach to the west. You can see " +
               "a large grate on the ground.\n";

    dest_dir = ({
                 "room/ravine", "down",
                 "room/mount_top2", "east",
                 "players/warlord/road1", "north",
                 "players/kasgaroth/quest/shop", "south",
               }); 

    items = ({
              "grate", "You see a heavy black grate. You wonder " +
                       "if you can move it",
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
        write("Arrggghhhh. \n");
	write("You move the heavy grate.\n");
	this_player()->move_player("in#/players/apollo/link/aqua05");
    }
    return 1;
}

int move_up(string str) {

    if (!str || str!="grate") {
        notify_fail("What do you want to move? \n");
        return 0;
    } 
    if (str=="grate") {
        write("Arrgghhhh. \n");
        write("You move the heavy grate.\n");
	this_player()->move_player("in#/players/apollo/link/aqua05");
        return 1;
    }

}
