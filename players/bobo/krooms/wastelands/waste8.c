inherit "room/room";
 
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="The Wastelands";
    long_desc="You're in the Wastelands.\n"+
      "To the east you see a huge dolmen.\n";
    dest_dir=({
	"players/bobo/krooms/wastelands/waste5","north",
	"players/bobo/krooms/wastelands/cliff1","south",
	"players/bobo/krooms/wastelands/dolmen1","east",
    });
    items=({
      "dolmen","A huge dolmen, but you see nothing special",
    });
}
