/* Coded by Tegerl, 7.3.1995 */
/* rooms/out/hut */

inherit "room/room";
void reset(int arg)
{
object gris;
::reset(arg);

if (!present("griselda",this_object()))
  gris=clone_object("/players/tegerl/jabberwocky/monsters/gris");
  move_object(gris,this_object());

if (arg) return;
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
  
  }
