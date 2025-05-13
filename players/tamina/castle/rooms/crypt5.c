/*  This is the Crypt  */

#include "/players/tamina/defs.h"

inherit "room/room";
status cloned;
object thing;

reset(arg) {

  cloned = 0;
  if (arg) return ;

      	set_light(-1);
	short_desc = "A Crypt under Camelot";
	long_desc = 
"You take the long west passage which leads into a very small alcove.\n"+
"Here, sign of habitation can be clearly seen - but who (or what) \n"+
"habitates here, you cannot yet say.  A  mound of hay lies rather\n"+ 
"untidily in one corner, with a refuse pile strewn over another corner.\n"+ 
"Signs of the left-overs of meals can be seen lying all across the floor.\n";

	dest_dir = ({
          CROOMS + "crypt6","east",
        });

	items = ({
  "hay",
"An untidy heap of dirty, hay that lies in a thin layer across one of the "+
"corners",
  "pile",
"A where the person who lives here has decided to defacate",
  "left-overs",
"Parts of bones, and other such delights",
     });

}

init() 
{
  ::init();
  call_out("thing", 6, TP);
}

thing (obj) 
{
  int i;

  if (cloned == 1) return 0;

  if (!present (obj, TO)) return 0;

  tell_room (TO,
    "  Suddenly, the mound of hay starts to stir, as if waking from a \n"+
    "  heavy slumber...\n"+
    "  Then, amidst the bits of dirty hay, you can see a pair of glinting\n"+ 
    "  fangs, and can hear a deep, low growling which sends shivers up \n"+
    "  your spine.  Perhaps you might survive...\n");

  thing = CLO (CMONS + "dog");
  MO (thing, TO);

  cloned = 1;

  return 1;

}
