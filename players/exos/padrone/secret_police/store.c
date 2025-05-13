/* secret_police/store.c */

inherit "/room/room"; // whisky

object rope;

void reset(int arg) 
{
    ::reset(arg);
    if (!rope || !present(rope, this_object())) {
	rope = clone_object("obj/rope");
	move_object(rope, this_object());
    }
    if (!arg)
    {
	set_light(1);
	dest_dir =
	({
	  "players/padrone/secret_police/backroom", "east",
	});
	short_desc = "The store room for the shop";
	long_desc =
	"You are in the store room for this shop.\n"+
	"It is remarkably empty.\n";
    }
}

