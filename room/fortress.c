inherit "room/room";

void reset(int arg) {

    if(arg) return;

    set_light(1);

    short_desc="The orc fortress";

    long_desc="This is the local strong point of the orcs. There is an " +
              "entrance to a small room to the north.\n";

    dest_dir=({"room/orc_treasure","north",
               "room/orc_vall","south"});

    items=({"point","It seems this place could flood with orcs",
            "entrance","It's beautiful, at least, for orc standards",
            "room","It looks very important"});

    clone_list = ({ 1, 8, "orc", "obj/orc", 0,
                 });

    ::reset(arg);
}

init() {
    ::init();
    add_action("north", "north");
}

int north() {

    if(present("orc",this_object())) {
        write("An orc bars your way.\n");
        return 1;
    }
    return ::move("north");
}

