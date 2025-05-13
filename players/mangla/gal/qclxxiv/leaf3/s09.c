/* s09 */
#include "/players/qclxxiv/leaf3/leaf3room.h"
object loot;

ONE_EXIT( REGION+"s08", "southwest",
"At the end of the street",
"At the end of the street. To the north and east you look up to the steep dyke.\n"
+"A statue is standing where the street ends.\n",
1 )

towadden() { return "southwest"; }

init() {
	::init();
	add_action( "do_get", "get" );
	add_action("read","read");
}

extra_reset(arg) {
	loot = 0;
   if (arg) return;
   set_nodig(1); 
   items = ({
		"dyke", "A steep gray old dyke",
       "street" , "Just the end of a bumpy old bricked street",
				"statue",
"A statue of a bearded fisher-like man carrying a well-filled net.\n"
+"It looks rather old. There is an inscription at the pedestal",
				"inscription","An inscription is engraved at the pedestal",
   });
}

do_get( arg ) {
   if (!arg) return 0;
   switch (arg) {
	   case "statue": write("It's too heavy.\n"); break;
       case "street" : write("How do you plan to carry that?\n"); break;
       default: return 0;
   }
   return 1;
}

read(arg) {
	string s;
	object qm;
	qm = "/players/qclxxiv/qquest/qmast";
	if (arg=="inscription") {
		write( "You read: \n"
+"Negus Qcxv, Master of fishing spells. ....(weird symbols follow).\n");
		s = (qm->lock_name2key(2, this_player()->query_real_name() ) == 8) ?
"This is a secret message to the brave adventurer that will come and\n"
+"kill the evil dragon. Dig at the place you will meet in a vision.\n" : 0;
		qinscription(s);
		if (s) {
			if (!loot) {
				loot = clone_object("/players/qclxxiv/qquest/vicinstone");
				move_object(loot, this_player());
				write("PANG!....a stone actually FELL on your head!\n");
			}
			else write(
"You feel that you should come back here later, and read again,\n"
+"as you get the idea that something essential is missing....\n" );
		}
		return 1;
	}
	return 0;
}

