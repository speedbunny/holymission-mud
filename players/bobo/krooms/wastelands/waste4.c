inherit "room/room";
 
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="The Wastelands";
    long_desc="You're in the Wastelands.\n";
    dest_dir=({
	"players/bobo/krooms/wastelands/waste7","south",
	"players/bobo/krooms/wastelands/waste3","west",
   });
}
