inherit "room/room";
reset(arg) {
    if (!arg) {
	set_light(1);
	short_desc = "A grave yard";
	long_desc = 
	"This is the grave of Tuppence the Tickle-Monster.\n"+
	"Even in death, the local people fear her, and the grave is fenced\n"+
	"off, behind a large black fence.\n";
	items = ({"fence","A high black fence, with rusty barbed wire.",
	  "grave","Maybe you could read it.",});
    }
}
