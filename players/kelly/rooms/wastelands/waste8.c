inherit "room/room";
 
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="The Wastelands";
    long_desc="You're in the Wastelands.\n"+
      "To the east you see a huge dolmen.\n";
    dest_dir=({
      "players/kelly/rooms/wastelands/cliff1","south",
      "players/kelly/rooms/wastelands/dolmen1","east",
      "players/kelly/rooms/wastelands/waste5","north",
    });
    items=({
      "dolmen","A huge dolmen, but you see nothing special",
    });
}
