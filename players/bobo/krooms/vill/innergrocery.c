inherit "/room/room";

void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="A strage room.";
   long_desc=
	"You have entered the store's storage room.  There is not much "+
	"of interest here being that there is just a bunch of boxes "+
	"lining the walls and floor.\n";
   dest_dir=({
	"/players/bobo/krooms/vill/grocery","east",
   });
   items=({
	"boxes","Loads of non-perishable food is stored here",
	"walls","The walls are pretty much covered by boxes",
	"floor","A hard rock floor with a small grate in the center",
	"grate","It appears to be just a small ordinary grate",
   });
   replace_program("/room/room");
}
