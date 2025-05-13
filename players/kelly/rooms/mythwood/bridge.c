inherit "room/room";

status rope;

int _climb(string item) {

    if (item != "down rope" && item != "down the rope") return 0;
    if (rope) {
        write("The stream is too fast.  You are pulled away from the bank.\n" +
              "You are left swimming in the center of the Quiet river until\n" +
              "catching an eddy and pulling yourself up to the shore.\n");
/*
        write("The stream is too fast. You're pulled away. You're helplessly swimming\n" +
              "in the waves of Quiet River. Suddenly you are washed onto a shore.\n");
*/
        this_player()->move_player("down the rope#players/kelly/rooms/wastelands/shore1");
    }
    else
        write("Maybe you should tie the rope to the bridge first.\n");
    return 1;
}

int _tie(string str) {

    if(str != "rope to bridge" && str != "rope onto bridge") return 0;
    write("You take the rope and securely tie it to the bridge,\n" +
          "dangling the other end over the side.\n");
    rope = 1;
    return 1;
}

int _untie() {

    write("You untie the rope, coil it up, and place it beside the bridge.\n");
    rope = 0;
    return 1;
}

int _get(string str) {

    if (str == "rope") {
        write("You can tie the rope to the bridge, but you cannot get it.\n");
        return 1;
    }
    return 0;
}


void reset(int arg) {

    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="On a bridge";
    long_desc="You are standing on a bridge over the fast-flowing Quiet River.\n"+
              "Down below, you can see the water flow swiftly past. There is a rope\n" +
              "lying on the ground near the bridge that you might be able to use\n" +
              "to climb down with if it was tied to the bridge.\n";
    dest_dir=({
               "players/kelly/rooms/mythwood/mythpath5","east",
               "players/kelly/rooms/mythwood/plateau","west",
             });
    items=({"bridge","A wooden bridge spanning the quiet river",
            "rope",  "A rope that could be used to climb down"
          });
}

void init() {
    ::init();
    add_action("_climb","climb");
    add_action("_untie","untie");
    add_action("_tie","tie");
    add_action("_get","get");
    add_action("_get","take");
}

