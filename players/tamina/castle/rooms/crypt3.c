/*  This is the Crypt  */

#include "/players/tamina/defs.h"

inherit "room/room";
object tomb;

reset(arg) {
  if (arg) return ;

      	set_light(-1);
	short_desc = "The Crypt under Camelot";
	long_desc = 
"You creep into the eastern apse in the Crypt, in the utter silence "+
"that cloaks you.  Here, you can see one solitary sarcophagus standing "+
"alone and proud in the deep shadows of the cave.\n";

	dest_dir = ({
          CROOMS + "crypt2","west",
        });

	items = ({
  "shadows",
"Deep, black, almost moving figures in the dimmness",
     });

  tomb = CLO(COBJ + "tomb1");
  MO(tomb, TO);

}
