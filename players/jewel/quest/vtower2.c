inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="The first level of the vampire tower";
    long_desc=
        "You are standing on the first level of the vampire kings tower.\n"+
        "From above a cold wind blows. You get an uneasy feeling. Dim light\n"+
        "falls through a small window to the north. Looking through the \n"+
        "window you can see another dark castle in a far distance\n";
    items=({
        "window","A very small window, it lightes the room a little bit",
        "castel","The castle of the cruel overlord"
        });
    dest_dir=({
        "/players/jewel/quest/vtower3","up",
        "/players/jewel/quest/vtower1","down"
        });
}
