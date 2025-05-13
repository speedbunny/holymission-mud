#include "/players/qclxxiv/myroom.h"
object loot;
object loot1 /*, loot2*/ ;
object beechnut,acorn;

#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);

extra_reset(arg) {
	loot = 0;
	loot1 = 0;
    if (!beechnut) {
    	beechnut = clone_object("players/qclxxiv/obj/beechnut");
    	move_object(beechnut, this_object());
    }
    if (!acorn) {
    	acorn = clone_object("players/qclxxiv/obj/acorn");
    	move_object(acorn, this_object());
    }
	if (arg) return;
	items = ({ "trees", "Oaks, beeches, and some birches",
				"tree", "A large beech",
				"beech", "A large beech",
				"birch", "An old silvery birch",
				"wood","A dense wood, made up of oaks, birches, and beeches",
				"woods","Dense woods, made up of oaks, birches, and beeches",
				"oaks", "Big old oaks, carrying acorns",
				"acorns", "Those in the trees are still green\n"+
							"and besides they are hanging far too high for you",
				"birches", "Some birches, nearly silverish white",
				"beeches", "Beautiful beeches carrying lots of beechnuts",
				"beechnuts", "Those in the trees are not ripe yet\n"+
							"and besides they are hanging far too high for you",
				"honeysuckle","Richly smelling honeysucle, embracing the trees",
				"ferns","Huge dark green ferns, covering most of the soil",
				"track", "A tiny track, covered with tiny footprints",
				"path", "A very small path, covered with tiny footprints",
				"statue",
"A crystal statue of a thick-set man holding a pick-axe.\n"
+"It looks ancient. There is an inscription at the pedestal",
				"inscription","An inscription is engraved at the pedestal",
			});
}

THREE_EXIT( "players/qclxxiv/leaf7/r2","northeast",
"players/qclxxiv/leaf7/r5","west",
"players/qclxxiv/leaf7/r8","southwest",
"A rather dense wood, consisting mostly of oaks, birches, and beeches",
"A rather dense wood, consisting mostly of oaks, birches, and beeches.\n"+
"Amidst the trees stands an ancient crystal statue, somewhat out of side.\n"+
"Some honeysucle, and some ferns are thriving amongst the threes.\n"+
"It looks like you're trodding some small path, but surely this is a VERY\n"+
"small path. It seems to go from northeast to southwest, but to the west\n"+
"another small track leads into even denser woods.\n" ,1)

init() {
	::init();
	add_action( "do_get", "get" );
	add_action("read","read");
}

do_get( arg ) {
	if (!arg) return 0;
	switch (arg) {
		case "statue": write("It's too heavy.\n"); break;
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
+"Negus Qxlviii, Master of Mining and Minerals. ..(weird symbols follow).\n");
		s = (qm->lock_name2key(2, this_player()->query_real_name() ) == 7) ?
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
			this_player()->query_real_name())==7) {
		if (!loot1) {
			PLACE_IN_THIS(loot1,"/players/qclxxiv/qquest/map3");
			loot1->setup_map(this_player());
			log_file("qmap",this_player()->query_real_name()+" map3 "
						+ctime(time())+"\n");
			write_file("/players/qclxxiv/qquest/qmap",
					this_player()->query_real_name()+" map3 " +ctime(time())+"\n");
			return "You find a piece of map.\n";
		}
		else {
			return "You get the feeling someone was here earlier....\n"
					+"But maybe you just have to try later.\n";
		}
	}
	return "You find nothing.\n";
}
