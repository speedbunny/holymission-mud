id(str) { return str == "lump" || str == "onyx" || str == "lump of onyx"; }
short() { return "A lump of onyx"; }
long()  { write(
"This lump of onyx is actually Qclxxiv's Magical Newbie Guide!\nType help onyx.\n"); }
get()	{ return 1; }
query_weight() { return 0; }
query_value() { return 2; }

init()  { 
	add_action("help", "help" );
	add_action("qstart", "qstart" );
	add_action("qcheck", "qcheck" );
	add_action("qhint", "qhint" );
}

help(arg) {
	if (id(arg) && environment(this_object())==this_player()) {
		write(
"Qclxxiv's Magical Newbie Guide is only useful for those people that have\n"
+"not reached the level eight of world experience yet.\n\n"
+"The spells it allows to the one who carries it are:\n"
+"qstart      - go to the entrance of the castle of the Q's.\n"
+"              herein monsters of all levels, good weapons and\n"
+"              armours, and good loot can be found for all.\n"
+"qcheck      - check whether you are still in newbie area,\n"
+"              note that the outer rooms of newbie area will\n"
+"              already be described as non-newbie area, so if\n"
+"              you always turn around when the qcheck says so,\n"
+"              you'll not come in regions with aggressive or too\n"
+"              dangerous monsters. Note that sometimes higher-level\n"
+"              folks scare dangerous monsters into newbie areas, so\n"
+"              stay alert nevertheless.\n"
+"              Note also that safe doesn't mean you can fight with all\n"
+"              monsters and creatures, use your brains and use the hints.\n"
+"qhint       - reveal secret hints in certain rooms.\n"
+"              If you reached level five and can still use this guide,\n"
+"              it may not be a bad idea to start on Island Dragon...\n"
			);
		return 1;
	}
	else if (id(arg) ) {
		write("You don't have the onyx.\n");
		return 1;
	}
	return 0;
}

qlegal(tp) {
	if (!tp->query_npc() && tp->query_level()<=7) return 1;
	write(
"You are above level seven, and are no longer allowed to use this guide.\n");
	if (tp->query_level()>30) {
		write("However, because you are a wizard, you may use it after all.\n");
		return 1;
	}
	return 0;
}

qstart(arg) {
	if (!qlegal(this_player())) return 1;
	write("Well, this really is a newbie teleport only, since you could\n"
+"probably not yet afford a real one anyway. Go to the main shop on the\n"
+"main road (in the main village), and go one place to the south, that\n"
+"is, stand in front of the shop. Now the way to the Seven-fingered Leaf is\n"
+"as follows: nine times to the west (arrive at clearing)\n"
+"then, four times north, one time east, and one time north, and you'll\n"
+"be in the entry hall of the Leaf.\n"
		);
	return 1;
}

qcheck(arg) {
	if (!qlegal(this_player())) return 1;
	if (environment(this_player())) {
		if (environment(this_player())->query_qnewbie()) {
			write("This is a rather safe place to be.\n");
			return 1;
		}
	}
	write("This is no longer guaranteed to be a rather safe place.\n");
	return 1;
}

qhint(arg) {
	string s;
	if (!qlegal(this_player())) return 1;
	if (environment(this_player())) {
		s = environment(this_player())->query_newbiehint();
		if (s)  {
			write("Hint:\n"+s+"\n");
			return 1;
		}
	}
	write("There are no secrets that I may reveal here.\n");
	return 1;
}
