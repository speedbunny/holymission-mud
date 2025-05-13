inherit "room/room";

reset(arg) {
    if (arg) return;

    set_light(1);
    short_desc="A dimly lit chapel.";
    long_desc= 
        "A dimly lit chapel. There is nothing inside except some\n"+
        "stairs going down, and a rotten pile of wood and a broken\n"+
        "down old altar at the corner of the room.\n";
    items=({
        "stairs","Some stairs made of stone with lots of dust on them",
        "pile","This wooden poles must have been the cross of the chapel once",
        "wood","This wooden poles must have been the cross of the chapel once",
        "pile of wood", "This wooden poles must have been the cross of"+
                        " the capel once",
        "altar","On a closer look there is only a pile of stones left",
        "stone","The stone is old, crumbling and covered with moss",
        "stones","The stones are the remains of the old altar of this church",
          });
    dest_dir=({ 
        "/players/jewel/quest/church2","down",
        "/players/jewel/quest/bell","up",
        "/players/jewel/quest/grave11","south" 
             });
}

init() {
    ::init();
    add_action("search","search");
}

search(arg) {
object wood;

    if(!arg) {
        write("Search what ?\n");
        return 1;
    }
    if(arg=="pile" || arg=="wood" || arg=="pile of wood") {
        write("You found a sharpended, wooden pole.\n");
        say(this_player()->query_name()+" searches the pile of wood.\n");
        move_object(wood=clone_object("obj/weapon"),this_object());
        wood->set_name("wooden pole");
        wood->set_short("a wooden pole");
        wood->set_long("A oakwood pole. It former was part of a cross.\n");
        wood->set_weight(2);
        wood->set_value(10);
        wood->set_class(3);
        wood->set_type(2);
        wood->set_alias("pole");
        return 1;
    }
}
