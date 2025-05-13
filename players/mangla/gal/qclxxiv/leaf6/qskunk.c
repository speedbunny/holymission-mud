inherit "/players/qclxxiv/leaf6/skunk";
#define PLACE_IN_THIS(OBJNAME, FILNAME)\
OBJNAME = place_in_this(OBJNAME,FILNAME,this_object());


second_life() {
	object loot1, loot2;
	if ("/players/qclxxiv/qquest/qmast"->lock_name2key(1,
			this_player()->query_real_name())==3) {
		PLACE_IN_THIS(loot1,"/players/qclxxiv/qquest/map1");
		loot1->setup_map(this_player());
		PLACE_IN_THIS(loot2,"/players/qclxxiv/qquest/fearstone");
		log_file("qmap",this_player()->query_real_name()+" map1 "
				+ctime(time())+"\n");
		write_file("/players/qclxxiv/qquest/qmap",
				this_player()->query_real_name()+" map1 "+ctime(time())+"\n");
	}
	return 0;
}

