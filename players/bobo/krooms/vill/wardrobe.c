inherit "/room/room";

void reset(int arg) {
   ::reset (arg);
   if (arg) return;
   set_light(1);
   short_desc="The lounge.";
   long_desc=
	"You have entered a lounge where the local police come to sit and "+
	"relax.  There are couches all around the room as well as several "+
	"games for their entertainment.  But at the moment the places seems "+
	"to be deserted.\n";
   dest_dir=({
	"/players/bobo/krooms/vill/quarters","south",
	"/players/bobo/krooms/vill/bureau","down",
   });
   items=({
	"couches","Worn out tattered old couches...comfy though",
	"games","There are a couple decks of cards and some dice here",
   });
   replace_program("/room/room");
}
