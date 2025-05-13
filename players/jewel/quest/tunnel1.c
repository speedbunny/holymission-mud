// Code originally by Sherman of Holy Mission //
// re-coded and enhanced by Jewel of Holy Mission May 1996 //

inherit "room/room";

#define hill "players/jewel/quest/entrance"

reset(arg) {
    if (arg) return;
    set_light(0);
    short_desc="A dark foul reeking tunnel.";
    long_desc=
        "A tunnel with foul reeking slime on the walls.\n"+
        "This seems to be the dead end of the tunnel.\n";
    items=({
        "tunnel","A foul reeking tunnel in a mountain, it is very cold",
        "wall","A stone wall with slime on it",
        "walls","Stone walls with slime on them",
        "ceiling","You can see a trapdoor",
          });
    dest_dir=({
        "/players/jewel/quest/tunnel2","east"
             });
}
init() {
    ::init();
    add_action("up","up",1);
    add_action("search","search");
    add_action("open","open");
    add_action("close","close");
}

up() {
    if(hill->query_open()) {
        write("You climb up and leave through the ceiling.\n");
        this_player()->move_player("through the ceiling#"+hill);
        return 1;
                           }
       else notify_fail("You bang your head on the ceiling.\n");
}

search(arg) {
    if(arg=="ceiling") {
        write("You notice a hidden trapdoor at the ceiling.\n");
        if(hill->query_open())
            write("It is open.\n");
        else
            write("It is closed.\n");
        return 1;
    }
}

open(arg) {
    if(arg=="trapdoor") {
        if(hill->query_open()) write("It is already open.\n");
        else {
            write("You open the trapdoor.\n");
            say(this_player()->query_name()+" moves something at the "+
                "ceiling.\n");
            hill->open_door();
        }
        return 1;
    }
}

close(arg) {
    if(arg=="trapdoor") {
        if(!hill->query_open()) write("It is already closed.\n");
        else {
            write("You close the trapdoor.\n");
            say(this_player()->query_name()+" moves something at the "+
                "ceiling.\n");
            hill->close_door();
        }
        return 1;
    }
}

open_door() {
    tell_room(this_object(),"Something moves on the ceiling.\n");
}

close_door() {
    tell_room(this_object(),"Something moves on the ceiling.\n");
}

