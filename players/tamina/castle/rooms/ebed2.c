/*  This is the second Bedchamber in the East Wing  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(1);
	short_desc = "Bed Chamber";
	long_desc = 
"There is another large four-poster bed standing against the far wall\n"+
"when you enter this bedroom.  The room looks as though it were of a\n"+
"respectable living standard.  On the walls however, are obvious lighter\n"+
"patches where paintings, or portraits once hung, and the sunlight has\n"+
"faded the walls.  About the base of the bed are littered several signs\n"+
"of previous habitation, like bed-pans, and other oddments.\n";

	dest_dir = ({
          CROOMS + "ewing5","west",
        });

	items = ({
  "bed",
"It is a large four-poster bed, but looks in very bad condition, as if "+
"no one has bothered to look after it for quite some time",
  "oddments",
"Old, worn garments that appear to have belonged to a noble lady some "+
"time in the past",
  "bed-pans",
"Very old iron tins that smell reeaaaal baaaad",
     });

    ::reset (arg);
  
    RPR("room/room");
}
