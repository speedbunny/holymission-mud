

/* Tegerl, 22.3.1995 */
/* rooms/castle/chap */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"

void reset(int arg) 
{

if (!arg);
{

set_light(1);
short_desc="In a chapel";

long_desc=
    "It is very silent here. This is the chapel of the castle. " +
    "This chapel looks very nice and you think that it might be " +
    "true, that people like church much more in times of troubles.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/castle/hall3", "south",
  });

items=({
    "castle","It is a very old castle and it is in a very bad contition",
    "walls","The walls look very ugly",
    "wall","The wall looks very ugly",
   
});

smell = "You smell waste and dump.";
  
  }

::reset(arg);
replace_program("room/room");
}