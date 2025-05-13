#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
object loot1 /*, loot2*/ ;
object rasta;

query_qnewbie() { return 1; }
query_newbiehint() { 
	return "Don't attack the rastamen.\n";
}
extra_reset(arg) {
	loot1 = 0;
	if (!rasta) {
		PLACE_IN_THIS(rasta,"/players/qclxxiv/leaf1/rastaman");
		rasta->set_lines( ({ 
					"Hail Mi Idrin...Love Mi Idrin\n",
					"Have A Little Sup Of Mi Chalwa\n",
					"Jah Love Is What I Bring\n",
					"A So Mi Do Mi Thing\n",
					"Da Da Doo Da Day\n",
					}) );
   		rasta->set_long( "A rastaman, having long dreadlocks.\n");
	}
	if (arg) return;
	items = ({ "bushes", "Mostly elder trees, acacias and cacti",
			   "elder trees", "They don't carry elder berries yet",
			   "trees", "Mostly elder trees",
			   "acacias", "Beautiful acacia trees",
			   "cacti", "Various thorny cacti, some flowering",
			   "cannabis plants", "Some sweet smelling cannabis plants",
			   "cannabis", "Some sweet smelling cannabis plants",
			   "plants", "Some sweet smelling cannabis plants",
			   "orchids", "Some beautiful and sweet smelling orchids",
			   "dell", "You're right down in the middle of it!",
			   "hill", "A high, green covered hill",
			   "small hill", "A small, green covered hill"
			});
}

THREE_EXIT( "players/qclxxiv/leaf1/l5","north",
"players/qclxxiv/leaf1/l6","northwest",
"players/qclxxiv/leaf1/l7","east",
"A green dell",
"A green dell. All around there are elder trees, acacias and cacti.\n"+
"Some cannabis plants and a few orchids can be found here. To the east\n"+
"there is a small hill. To the north there is a higher green covered hill.\n"
,1)

dig(player) {
	if ("/players/qclxxiv/qquest/qmast"->lock_name2key(3,
			this_player()->query_real_name())==0) {
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


