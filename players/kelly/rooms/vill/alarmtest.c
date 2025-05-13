inherit "obj/thing";

alarm() {

    write("You press the alarm button.\n");
    "players/kelly/rooms/vill/police_office"->alarm("e,n,n,e,e",this_player()->query_real_name());
    return 1;
}

get() { return 1; }

reset(arg) {

    ::reset(arg);
    if (arg) return;
    set_name("button");
    set_short("A button");
}

init() {
    ::init();
    add_action("alarm","alarm");
}

