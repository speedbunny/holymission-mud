inherit "room/room";

int dug;

reset(arg) {
    dug=0;

    if (arg) return;
    set_light(1);
    short_desc="A grave with a magical aura.";
    long_desc=
        "You are standing in front of a grave with a strange magical aura.\n";
    items=({
        "aura","A very strange aura",
        "magical aura","A very strange aura"
          });
    dest_dir=({
        "/players/jewel/quest/grave4","south",
        "/players/jewel/quest/grave8","east",
        "/players/jewel/quest/grave10","north"
             });
}

dig() {
    object mon,gh;
    if (present("ghost")) {
        write("The ghost stops your attempt.\n");
        say(this_player()->query_name()+
            " tries to dig but the ghost stops him.\n");
        return 1;
    }
    if (!dug) {
        write("As you dig in the grave, a horrible ghost rises from it.\n");
        say(this_player()->query_name() +" disturbs an angry ghost.\n");
        move_object(gh=clone_object("/players/jewel/quest/ghost"),this_object());
        mon=clone_object("/obj/money");
        mon->set_money(1000+random(1000));
        move_object(mon,gh);
        dug=1;
    } else {
        write("You dig a hole and find nothing.\n");
        say(this_player()->query_name() +" digs a hole and finds nothing.\n");
    }
    return 1;
}
