

/* Tegerl, 15.3.1995 */
/* rooms/castle/yard */


inherit "room/room";
#define PATH "players/tegerl/jabberwocky/"
#define SAY(x) tell_room(this_object(),x)

object pl;  

void reset(int arg)
{
  ::reset(arg);
  if (arg) return;
set_light(1);
short_desc="Yard in front of the castle";

long_desc=
    "This is a yard in front of the castle. " +
    "You now can see the castle in its full beauty, or let's  " +
    "say in its disgusting uglyness. " +
    "In fact it is very old and worn down. " +
    "The mortar falls from the walls and you wonder when this " +
    "castle will fall in.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/castle/door", "north",
    "players/tegerl/jabberwocky/rooms/castle/way1", "east",
    "players/tegerl/jabberwocky/rooms/town/street6", "west",
  });

items=({
    "castle","It is a big old castle, but it is in a very bad condition",   
    
});

smell = "The air could be fresh and clean, if that town wouldn't be there. So you can only smell waste and dump.";
}
void init()
{
  ::init();
  if (interactive(this_player()))
  {
      pl = this_player();
     SAY("Suddenly the air is filled with enormous noise, you look at the castle\n");
     SAY("and you can see that a tower tumbles and falls in.\n");
  }   
}