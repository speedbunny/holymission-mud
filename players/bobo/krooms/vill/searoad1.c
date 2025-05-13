inherit "/room/room";
 
void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="A road";
   long_desc=
	"You are on a road leading to the sea.  In the distant east you can "+
	"see some seagulls soaring in the wind.  The road breaks off to the "+
	"east with a large gap where the road once was.\n";
   dest_dir=({
	"/players/bobo/krooms/vill/road7","west",
   });
   items=({
	"seagulls","They are too far away to discern anything special",
	"gap","it seems very unnatural",
   });
   replace_program("room/room");
}
