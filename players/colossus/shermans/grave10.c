inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
short_desc = "Stinking hole";
    long_desc=
"As you enter this part of the graveyard you are assaulted by a\n"+
"wave of sickening stench that makes you regurgitate. From the\n"+
"sense of smell you are left with, you guess that it's coming\n"+
"from a hole where a tombstone used to be.\n";
        "there is a big hole with lots of rotten things inside.\n";
    items=({
        "hole","A big hole with rotten things",
        "things","Some nasty rotten cadavers"
          });
    dest_dir=({
        "/players/sherman/grave11","east",
        "/players/sherman/grave7","south"
             });
}

dig() {
    write("You dig a hole in the garbage. Now you stink like a zombie.\n");
    say(this_player()->query_name()+" digs in the garbage like an animal.\n");
    this_player()->set_alignment("stinking");
    return 1;
}
