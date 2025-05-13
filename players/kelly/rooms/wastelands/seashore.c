inherit "room/room";
 
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="The seashore";
    long_desc="You're at the shore of the ocean\n"+
      "To the west a river leads into the ocean.\n"+
      "There is an entrance to a cave.\n";
    dest_dir=({
      "players/kelly/rooms/wastelands/cliff2","up",
      "players/kelly/rooms/wastelands/cave1","north",
      "players/kelly/rooms/wastelands/mouth","west",
    });
    items=({
      "ocean","The wide ocean, far in the distance you think you can see an island",
      "river","It is called Quite River",
      "cave","It's big and seems to belong to a really big beast",
      "entrance","It's a big hole in the rock",
    });
}
 
