inherit "room/room";

void reset(int arg) {

    ::reset(arg);
    if (!arg) {
        set_light(1);
        short_desc="backroom of bank";
        long_desc="You are in the backroom of the bank.\n";
        dest_dir=({
                   "room/bank","east",
                 });
        items=({
                "door","@@door_desc",
              });
        move_object(clone_object("obj/safe"), this_object());
    }
}

string door_desc() {

    if ("room/bank"->query_door())
        return("The door is closed");
    else
        return("The door is open");
}

init() {

    ::init();
    add_action("east", "east");
    add_action("open", "open");
}

int east() {

    if ("room/bank"->query_door()) {
        write("The door is closed.\n");
        return 1;
    }
    return ::move();
}

int open(string str) {

    if (!str) return 0;

    if (!"room/bank"->query_door())
        return 0;
    "room/bank"->open_door_inside();
    say(this_player()->query_name()+" opens the door.\n");
    write("Ok.\n");
    return 1;
}
