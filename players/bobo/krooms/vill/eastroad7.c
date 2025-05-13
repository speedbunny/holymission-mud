inherit "/room/room";

void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="The east road.";
   long_desc=
	"You are traveling on the far edge of the east road which continues "+
	"on to the south of here.  The other portion of the road leads to "+
	"the northeast where Red Rock Junction is.\n";
   dest_dir=({
	"/players/bobo/krooms/vill/eastroad6","south",
	"/players/bobo/krooms/vill/entrance","northeast",
   });
   replace_program("/room/room");
}
