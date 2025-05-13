inherit "room/room";
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A path";
    long_desc="A path in the mountains. \n"+
      "To the north there is a strange forest.\n";

    dest_dir=({
      "players/kelly/rooms/mountains/path14","south",
      "players/kelly/rooms/entwood/wood1","north",
    });
    items=({
      "forest","A really strange forest",
    });
}
