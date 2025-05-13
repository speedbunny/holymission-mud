inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="Hill";
    long_desc=
"You are standing at the foot of a hill. The building seems to be a mansion\n"+
"ruling the area from above the hill.\n";
    dest_dir=({ "room/shore/p02","north" });
}

