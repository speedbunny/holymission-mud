inherit "room/room";

void reset(int arg) {

    if (arg) return;

    set_light(1);

    short_desc="Big tree";
    long_desc="A big single tree on the plain.\n";


    dest_dir=({
               "room/plane7", "east",
               "room/giant_path", "west",
             });
    items=({
            "tree","A very big oak",
            "big tree","A very big oak",
          });

    clone_list = ({ 1, 1, "rope", "obj/rope", 0,
                 });
    ::reset(arg);
}

init() {
    ::init();
    add_action("climb", "climb");
    add_action("tie","tie");
}

int tie(string str) {

    if (str == "rope to tree" || str == "rope to big tree") {
        write("The branches are very high up.\n");
        return 0;
    }
    return 0;
}

int climb(string str) {

    if (!id(str))
        return 0;
    write("There are no low branches.\n");
    return 1;
}
