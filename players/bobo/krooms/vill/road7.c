inherit "/room/room";

void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="A road.";
   long_desc=
	"You are just outside Red Rock Junction city limits.  The road here "+
	"runs from east to west in the middle of a steep ravine.  Even though "+
	"it is very steep perhaps you can climb it.  There is also a large "+
	"rock to the west.\n";
   dest_dir=({
	"/players/saffrin/area/aine/room/for1","east",
	"/players/bobo/krooms/vill/road5","west",
	"/room/ravine","up",
   });
   items=({
	"forest","A forest with lots of trees",
	"trees","They make up the forest",
	"path","It looks like it was created recently",
	"rock","It's a big red rock",
   });
   replace_program("/room/room");
}
