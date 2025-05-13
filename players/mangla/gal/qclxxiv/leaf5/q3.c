#include "/players/qclxxiv/myroom.h"  
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
#define LEAF "/players/qclxxiv/leaf6/"

object loot;
object loot1 /*, loot2*/ ;
object mould, beetle1, flea1, flea2;

query_qnewbie() { return 1; }
extra_reset(arg) { 
	loot = 0;
	loot1 = 0;
	FRESH_IN_ROOM(mould, LEAF+"mould");
	PLACE_IN_ROOM(beetle1, LEAF+"dungbeetle");
	PLACE_IN_ROOM(flea1, LEAF+"flea");
	PLACE_IN_ROOM(flea2, LEAF+"flea");
	if (arg) return;
	items = ({ 
				"path","It's hardly a path anymore actually",
				"wall","It's covered with stinking moulds",
				"trashcan", "It is not what is seems to be...maybe enter it?",
				"statue",
"A large statue of a big bearded man carrying a long sharp lance.\n"
+"The statue looks rather old. There is an inscription at the pedestal",
				"inscription","An inscription is engraved at the pedestal",
			});
}

THREE_EXIT( LEAF+"q4","west",
			LEAF+"q2","east",
			LEAF+"q7","southeast",
       	 "A dingy, dimly lit path",
"A dingy, dimly lit path. Everything is mouldy here. You can hardly see a\n"
+"thing here, although the large statue is hard to overlook.\n"
+"A dirty, rusty trashcan stands against a grubby wall to the north.\n"
 , 1)


init() {
	::init();
	add_action("trashcan","enter");
	add_action( "do_get", "get" );
	add_action("read","read");
}

do_get( arg ) {
	if (!arg) return 0;
	switch (arg) {
		case "statue": write("It's too heavy.\n"); break;
		case "trashcan": write("You can't seem to move it.\n"); break;
		default: return 0;
	}
	return 1;
}

trashcan(str) {
    if (str=="trashcan") { 
    	call_other(this_player(), "move_player", "via trashcan#"+LEAF+"q25" );
    	return 1;
	}
	return 0;  
}

read(arg) {
	string s;
	object qm;
	qm = "/players/qclxxiv/qquest/qmast";
	if (arg=="inscription") {
		write( "You read: \n"
+"Negus Qcxvii, Master of Monster Taming Magic....(weird symbols follow).\n");
		s = (qm->lock_name2key(2, this_player()->query_real_name() ) == 4) ?
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
			this_player()->query_real_name())==4) {
		if (!loot1) {
			PLACE_IN_THIS(loot1,"/players/qclxxiv/qquest/map3");
			loot1->setup_map(this_player());
			log_file("qmap",this_player()->query_real_name()+" map3 "
						+ctime(time())+"\n");
			write_file("/players/qclxxiv/qquest/qmap",
					this_player()->query_real_name()+" map3 "+ctime(time())+"\n");
			return "You find a piece of map.\n";
		}
		else {
			return "You get the feeling someone was here earlier....\n"
					+"But maybe you just have to try later.\n";
		}
	}
	return "You find nothing.\n";
}
