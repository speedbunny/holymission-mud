#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object loot;
object loot1 /*, loot2*/ ;
object spider1, bug1, louse1, fungus, spider2;

query_qnewbie() { return 1; }
extra_reset(arg) { 
	loot = 0;
	loot1 = 0;
	PLACE_IN_ROOM(louse1, LEAF+"louse");
	PLACE_IN_ROOM(bug1, LEAF+"sowbug");
	PLACE_IN_ROOM(spider1, LEAF+"spider");
	PLACE_IN_ROOM(spider2, LEAF+"spider");
	FRESH_IN_ROOM(fungus, LEAF+"fungus");
	if (arg) return;
	items = ({ 
				"bottom","It's covered with stinking moulds",
				"moulds","They are covering the entire stinking bottom here",
				"creatures","They have all hidden themselves again",
				"cockroaches","They have all hidden themselves again",
				"statue",
"A shining golden statue of a smiling man with a little staff and a bowl.\n"
+"It looks pretty ancient. There is an inscription at the pedestal",
				"inscription","An inscription is engraved at the pedestal",
			});
}

FOUR_EXIT( 
			LEAF+"q5","northwest",
			LEAF+"q10","west",
			LEAF+"q15","southwest",
			LEAF+"q8","east",
       	 "A dark, humid place with a mouldy smell",
"A dark, humid place with a mouldy smell. Completely out of place there is \n"
+"a golden statue standing here. You see dark creatures moving\n"+	
"around convulsively to the west, apparently frightened by your light.\n"+
"You shudder with horror as you recognize enormous cockroaches in them.\n", 0)

init() {
	::init();
	add_action( "do_get", "get" );
	add_action("read","read");
}

do_get( arg ) {
	if (!arg) return 0;
	switch (arg) {
		case "statue": write("It's way too heavy.\n"); break;
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
+"Negusa Qlxxxiv, Master of Gold Creation. ....(weird symbols follow).\n");
		s = (qm->lock_name2key(2, this_player()->query_real_name() ) == 5) ?
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

dig(player) {
	if ("/players/qclxxiv/qquest/qmast"->lock_name2key(3,
			this_player()->query_real_name())==6) {
		if (!loot1) {
			PLACE_IN_THIS(loot1,"/players/qclxxiv/qquest/map3");
			loot1->setup_map(this_player());
			log_file("qmap",this_player()->query_real_name()+" map3 "
						+ctime(time())+"\n");
			write_file("/players/qclxxiv/qquest/qmap",
					this_player()->query_real_name()+" map3 "
						+ctime(time())+"\n");
			return "You find a piece of map.\n";
		}
		else {
			return "You get the feeling someone was here earlier....\n"
					+"But maybe you just have to try later.\n";
		}
	}
	return "You find nothing.\n";
}
