inherit "room/room";


object cat ;
reset(arg) {
    if(!arg) {

	short_desc = "Let us see if this is the key to the new area.";

	long_desc = "This could be the entrance to a new world...what will\n" +
	"it bring ? Try to walk around and stay alive. Then you will probably see.\n";
	dest_dir = ({"players/muzmuz/workroom","stairs",
	  "players/muzmuz/testroom2","north"});


	cat = clone_object ("players/muzmuz/monster/cat");
	move_object(cat,this_object());

	set_light(1);

	return 1;

    }
}
