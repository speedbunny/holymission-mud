

/* Coded by Tegerl, 24.3.1995 */
/* rooms/castle/knight */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"

void reset(int arg) 
{
if (!arg);
{
clone_list=({1,1,"knight",PATH+"monsters/kni",0});
set_light(1);
short_desc="A desperate area";

long_desc=
    "This is a desperate area north of the town. " +
    "To the south you can still see a huge door, " +
    "but you don't know what there will be when you continue your way further north.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/castle/jabb", "north",
    "players/tegerl/jabberwocky/rooms/castle/door", "south",
  });

items=({
    "castle","It is a big old castle, but it is in a very bad condition",   
    "door","It is a huge wooden door, it is the door you came through",
    "ground","Your footprints seem to be the only ones around here",
});

property = ({ "no_teleport" });

smell = "The air could be fresh and clean, if that town wouldn't be there. So you can only smell waste and dump.";
  
  }

::reset(arg);
replace_program("room/room");
}