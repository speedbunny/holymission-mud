inherit "room/room";
 
 
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
    short_desc="The Wastelands";
    long_desc="You're in the Wastelands.\n";
    dest_dir=({
	"players/bobo/krooms/wastelands/waste1","north",
	"players/bobo/krooms/wastelands/waste6","south",
	"players/bobo/krooms/wastelands/waste4","east",
	"players/bobo/krooms/wastelands/waste2","west",
   });
}
