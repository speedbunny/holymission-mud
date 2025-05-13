/* Coded by Tegerl, 7.3.1995 */
/* rooms/out/hut */
/* Exos - 04/29/97 Replace_program() and clone_list */

inherit "room/room";
void reset(int arg)
{
    if (!arg) {
	set_light(1);
	short_desc="Fisherman's hut";

	long_desc=
	"This is a fisherman's hut " +
	"and it is built on piers which reach out of the lake's surface. " +
	"It is a small hut and it is made of wood and is covered with thatch. " +
	"In front of the hut there are nets hanged up to dry.\n";   

	dest_dir=({
	  "players/tegerl/jabberwocky/rooms/out/lake2", "northwest",
	});

	items=({
	  "lake","The water is darkblue and you can see fishes under the surface",
	  "hut","This seems to be the hut of a fisherman",
	  "nets","These nets are fishernets and they have been used lately as they are still wet",
	  "net","This net is a fishernet and it has been used lately as it is still wet",
	});

	smell = "You smell fish.";
	clone_list=({
	  1, 1, "griselda", "/players/tegerl/jabberwocky/monsters/gris", 0,
	});
    }
    ::reset(arg);
    replace_program("room/room");
}
