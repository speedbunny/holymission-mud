inherit "room/room";
 
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="The Wastelands";
    long_desc="You're in the Wastelands.\n"+
       "To the west a path starts into Mythwood.\n"+
      "To to south the Wastelands continue.\n";
    dest_dir=({
      "players/kelly/rooms/mythwood/mythpath6","west",
      "players/kelly/rooms/wastelands/waste3","south",
    });
    items=({
      "mythwood","It's a strange wood",
      "path","A spooky path",
    });
}
 
