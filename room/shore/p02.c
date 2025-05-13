inherit "room/room";

reset(arg) {
    if(arg) return;
    set_light(1);
    short_desc="Turning";
    long_desc=
"You are on a path heading south towards a strange looking building.\n"+
"Somewhere towards the east you hear the tides roll against a shore.\n";
    dest_dir=({
                "room/shore/p01","east",
                "room/shore/p03","south" });
}
