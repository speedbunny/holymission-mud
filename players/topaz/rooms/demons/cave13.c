inherit "room/room";

#include "/players/topaz/defs.h"

object topazdemon;
reset(arg) {
  if(!topazdemon) {
    move_object(topazdemon=clone_object(MDEMONS + "janitor"),this_object());
  }
  if(!arg) {

     short_desc = "Demon Janitor's room";
     long_desc = "This is the Demon Janitor's room.\n" +
                 "The Demon Queen keeps the Janitor around to keep\n" +
                 "her area clean, even if she thinks her husband is a\n" +
                 "slob.  The Janitor's room has assorted tools and\n" +
                 "cleaning supplies in it.\n";

      dest_dir = ({"players/topaz/rooms/demons/cave11","north",
 
                     });

     items =({"room","It is pretty neat here",
              "tool","Used to help him keep the Queen's area clean",
              "supplies","For cleaning the Queen's area",
              "cleaning supplies","For cleaning the Queen's area",
              });
       set_light (1);
return 1; }}
