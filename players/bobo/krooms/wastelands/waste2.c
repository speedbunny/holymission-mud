inherit "room/room";
 
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="The Wastelands";
    long_desc="You're in the Wastelands.\n"+
      "To the north a path starts into Mythwood.\n"+
      "The Wastelands continue south and east.\n";
    dest_dir=({
	"players/bobo/krooms/mythwood/mythpath6","north",
	"players/bobo/krooms/wastelands/waste5","south",
	"players/bobo/krooms/wastelands/waste3","east",
   });
}
 
