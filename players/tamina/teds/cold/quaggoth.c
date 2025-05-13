inherit "room/room";

#include "/players/tamina/defs.h"

object quaggoth;
int i;

void reset(int arg) 
{
  if (!arg) 
  {
    set_light(1);
    short_desc = "Frozen Wasteland";
    long_desc =
"There is nothing as far as the eye can see\n"+
"except snow and ice.\n";

    dest_dir = ({
   TCOLD + "snow", "east"
    });

  }
  i = random(5);
  if (!present("quaggoth")) 
  {
    while(i < 6) 
    {
      i++;
      quaggoth = clone_object("obj/monster");

      quaggoth->set_name("quaggoth");
      quaggoth->set_race("ape");
      quaggoth->set_long("A Snow White Quaggoth-Ape.\n");
      quaggoth->set_level(8);
      quaggoth->set_wc(15);
      quaggoth->set_ac(4);
      quaggoth->set_al(-100);
    
      call_other("/players/tamina/teds/random_treasure", "make_item", quaggoth, 3);
      move_object(quaggoth, this_object());
    }
  }
}
