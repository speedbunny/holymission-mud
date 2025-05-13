inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="A hole with some rotten things inside.";
    long_desc=
        "You are in the northwest corner of the Yard, in front of you\n"+
        "there is a big hole with lots of rotten things inside.\n";
    items=({
        "hole","A big hole with rotten things",
        "things","Some nasty rotten cadavers"
          });
    dest_dir=({
        "/players/jewel/quest/grave11","east",
        "/players/jewel/quest/grave7","south"
             });
}

dig() {
    write("You dig a hole in the garbage. Now you stink like a zombie.\n");
    say(this_player()->query_name()+" digs in the garbage like an animal.\n");
    this_player()->set_alignment("stinking");
    return 1;
}
