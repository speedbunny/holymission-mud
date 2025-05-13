

/* Coded by Tegerl, 8.3.1995 */
/* rooms/town/pub2 */


inherit "room/room";
void reset(int arg) 
{
::reset(arg);

if (arg) return;

set_light(1);
short_desc="A pub";

long_desc=
    "Welcome to the Pub at the dried up Oak Tree. " +
    "This pub is really cheap. Look at the menu to see what " +
    "they can offer here.\n";
  
dest_dir=({
    "players/tegerl/jabberwocky/rooms/town/street2", "east",
  });

items=({
    "menu"," ------------------------------\n" +
          "|                              |\n" +
          "|                              |\n" +
          "|     S O L D    O U T         |\n" +
          "|                              |\n" +
          "|                              |\n" +
           " ------------------------------",
});

smell = "The air could be fresh and clean, if that town wouldn't be there. So you can only smell waste and dump.";
  
  }

