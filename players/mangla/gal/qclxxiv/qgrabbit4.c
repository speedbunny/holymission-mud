inherit "/players/qclxxiv/grabbit4";
#define PLACE_IN_THIS(OBJNAME, FILNAME)\
OBJNAME = place_in_this(OBJNAME,FILNAME,this_object());


second_life() {
	object loot1, loot2;
	if ("/players/qclxxiv/qquest/qmast"->lock_name2key(1,
			this_player()->query_real_name())==0) {
		PLACE_IN_THIS(loot1,"/players/qclxxiv/qquest/map1");
		PLACE_IN_THIS(loot2,"/players/qclxxiv/qquest/fearstone");
	}
	return 0;
}

