inherit "room/room";
 
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="The Wastelands";
    long_desc="You're in the Wastelands.\n"+
      "To the south you sight a huge dolmen.\n";
    dest_dir=({
	"players/bobo/krooms/wastelands/waste3","north",
	"players/bobo/krooms/wastelands/dolmen1","south",
	"players/bobo/krooms/wastelands/waste7","east",
	"players/bobo/krooms/wastelands/waste5","west",
    });
    items=({
      "dolmen","A huge dolmen, but you don't see anything special" 
    });
}
 
