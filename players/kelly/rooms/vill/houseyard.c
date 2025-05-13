inherit "room/room";
reset(arg) {
    if (arg) return;
    set_light(1);
    no_castle_flag=1;
short_desc="A courtyard.";
long_desc=
"You are standing in what appears to be the courtyard for many houses.\n"+
"oddly though all of the shutters seem to be securely fastened and the\n"+
"doors seem to bolted.\n";
    dest_dir=({
	"players/kelly/rooms/vill/road4","north",
    });
    items=({
	"houses","All the residents of these homeslook as if they are trying to keep someone out",
	"windows","They are closed and the shutters are locked",
	"doors","The doors all appear to be bolted from the inside",
    });
}
