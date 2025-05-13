inherit "room/room";

reset(arg) {
    if (arg) return;
    set_light(1);
    short_desc="A small ruin.";
    long_desc=
        "You are standing in the undertakers hut, it has no roof,"+
        " so the rain\nis coming down on your head\n";
    items=({
        "rain","Dark black raindrops"
          });
    dest_dir=({
        "/players/jewel/quest/grave6","west",
        "/players/jewel/quest/hut2","north"
             });
}
