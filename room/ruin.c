inherit "room/room";

status i;

void reset(int arg) {

    i=0;

    if(arg) return;

    set_light(1);

    short_desc="Ruin";

    long_desc="You are standing inside an old deserted ruin. " +
              "The roof has long since fallen down, and there " +
              "is no sign of a door. Heaps of rubble lie on " +
              "the ground, mainly coming from the walls, which " +
              "look as if they are now only half the height they" +
              "once were.\n";

    dest_dir=({ "room/plane8", "north",
                "room/plane9", "east",
                "room/plane4", "south",
                "room/plane3", "west" });

    items=({ "ruin", "This is an old deserted ruin",
             "roof", "The roof has not been here for a long time",
             "door", "You are not even sure where the door used to be",
             "rubble", "There is rubble everywhere. It might be " +
                       "a good idea to search it",
             "heaps of rubble", "There is rubble everywhere. It " +
                                "might be a good idea to search it",
             "heaps", "There is rubble everywhere. It might be a " +
                      "good idea to search it",
             "walls", "The walls are crumbling badly. In a lot of " +
                      "places, they are almost gone",
          });
}

init() {
    ::init();
    add_action("search", "search");
}

int search(string str) {

    object s;

    if(!id(str)) return 0;
    if(i || str=="ruin" || str=="roof" || str=="door" || str=="walls") {
        write("You search the " + str + " but find nothing.\n");
        say(this_player()->query_name() + " searches the " + str +
                 " but finds nothing.\n");
        return 1;
    }
    i=1;
    write("You search the " + str + " and find a stethoscope!\n");
    say(this_player()->query_name() + " searches the " + str +
             " and finds something!\n");
    s=clone_object("obj/stethoscope");
    if(transfer(s,this_player())) {
        write("You are carrying too much.\n");
        move_object(s,this_object());
    }
    return 1;
}

