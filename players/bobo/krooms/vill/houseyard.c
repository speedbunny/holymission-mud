inherit "/room/room";

void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="A courtyard.";
   long_desc=
	"You are standing in what appears to be the courtyard for many "+
	"houses.  Oddly though all of the shutters seem to be closed and "+
	"securely fastened.  All the doors appear to be bolted.\n";
   dest_dir=({
	"/players/bobo/krooms/vill/road4","north",
   });
   items=({
	"houses","All the residents of these homes look as if they are trying"+
		 " to keep someone out",
	"windows","They are closed and the shutters are locked",
	"doors","The doors all appear to be bolted from the inside",
   });
   replace_program("/room/room");
}
