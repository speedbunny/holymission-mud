inherit "/room/room";

void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="At a small farmhouse.";
   long_desc=
	"You have come to a small clearing with a farmhouse in it.  The "+
	"house sits on the northern edge of the clearing with the mist "+
	"enveloping the back portion of it.  The clearing itself is filled "+
	"with clutter and trash.\n";
   dest_dir=({
	"/players/bobo/area/farm/f5","east",
	"/players/bobo/area/farm/f11","south",
	"/players/bobo/area/farm/f3","west",
   });
   items=({
	"mist","This mist is unlike any other mist that you have seen and is "+
	       "very scary",
	"house","a scraggley little house half enveloped by the mist",
	"clutter","there's bit an pieces of refuse all over the ground here",
	"trash","The trash includes, food, wood, and broken tools strewn about",
   });
   replace_program("/room/room");
}
