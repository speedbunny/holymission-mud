

/* Coded by Tegerl, 24.3.1995 */
/* rooms/castle/king */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"

void reset(int arg) 
{
if (!arg);
{
clone_list=({1,1,"king",PATH+"monsters/king",0,
             2,1,"herold",PATH+"monsters/herold",0,
             3,2,"guard",PATH+"monsters/guard",0,
             4,2,"merchant",PATH+"monsters/merchant",0});
set_light(1);
short_desc="Audience chamber";

long_desc=
    "This is the audience chamber of the king. " +
    "The room is in a lousy condition. You think that the king " +
    "might be out of money. You can hardly believe that this room " +
    "should be the place from where the decisions for the whole country are made.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/castle/hall3", "west",
  });

items=({
    "castle","It is a big old castle, but it is in a very bad condition",   
    "walls","The walls look very ugly and seem to be very weak",
    "wall","The wall looks very ugly and seems to be very weak",
    "ceiling","The ceiling looks very ugly and there is almost no mortar left on it",
    "ground","You think that the floor is made of stone, but you are not sure because there lies a lot of mortar and dust on the ground",
});

smell = "You smell waste and dump.";
  
  }

::reset(arg);
replace_program("room/room");
}
