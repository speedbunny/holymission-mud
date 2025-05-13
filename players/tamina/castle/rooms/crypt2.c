/*  This is the Crypt  */

#include "/players/tamina/defs.h"

inherit "room/room";

reset(arg) {

      	set_light(0);
	short_desc = "A Crypt under Camelot";
	long_desc = 
"A distinctly dusty odour hits your nostrils as you eneter the old \n"+
"Crypt under Camelot.  It feels very cold in here amidst the stone\n"+
"sepulchres that lie at seemingly random places here.  In the bleak\n"+
"darkness around you, there can be seen passages leading off in several \n"+
"directions to deeper recesses of the Crypt.\n";

	dest_dir = ({
          CROOMS + "crypt4","north",
          CROOMS + "crypt0","south",
          CROOMS + "crypt3","east",
          CROOMS + "crypt1","west",
        });
	
	items = ({
  "sepulchres",
"These are tombs made of very cold stone, the ancient coffins of the "+
"past kings and queens who resided in Camelot",
  "recesses",
"These are the smaller rooms in the Crypt, meant to hold individual "+
"coffins, or tombs of the more important figures",
        });

    ::reset (arg);

    RPR("room/room");
}

