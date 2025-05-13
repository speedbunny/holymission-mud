inherit "/room/room";

void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="The east road.";
   long_desc=
	"You are travelling on the east road.  It runs from north to south.  "+
	"The road to the north looks newer and seems to be repaired more "+ 
	"often.\n";
   dest_dir=({
	"/players/bobo/krooms/vill/eastroad7","north",
	"/room/eastroad5","south",
   });
   replace_program("/room/room");
}
