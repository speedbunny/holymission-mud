inherit "room/room";
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
short_desc="The lounge.";
long_desc=
"You have entered a lounge where the local police come to sit\n"+
"and relax.  There are couches all around the room as well as\n"+
"several games for their entertainment.  But at the moment the\n"+
"place seems to be deserted.\n";
items=({
	"couches","Worn out tattered old couches...comfy though",
	"games","There are a couple decks of cards and some dice here",
	});
    dest_dir=({
    "players/kelly/rooms/vill/bureau","down",
    "players/kelly/rooms/vill/quarters","south",
   });
}
