inherit "room/room";
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="A path";
    long_desc="A path in the mountains. To the south the path falls down to a uninviting\n"+
      "area. You can see the magic swamps there. You shiver from the cold that runs \n"+
      "down your neck, when look at them.\n";

    dest_dir=({
      "players/kelly/rooms/swamps/swampexit","south",
      "players/kelly/rooms/mountains/path2","north",
      "players/kelly/rooms/mountains/path7","northwest",
   });
}
