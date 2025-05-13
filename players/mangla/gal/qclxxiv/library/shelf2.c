inherit "players/qclxxiv/library/shelf.c";

reset(arg) {	/* just wrap around default reset in order to make real books*/
	::reset(arg);
	if (arg) return;
	/* books are pointed to by b1 to b5. */
	b1->set_covertext("Qcxxvii - On A Calculating Automata\n"); 
	b1->set_bookfile("/players/qclxxiv/library/calculatingautomata.txt");
	b2->set_covertext("Qxlviii - Mining and Minerals\n"); 
	b2->set_bookfile("/players/qclxxiv/library/minesminerals.txt");
	b3->set_covertext("Qcxxxviii - Dragon Extermination\n"); 
	b3->set_bookfile("/players/qclxxiv/library/dragonextermination.txt");
	b4->set_covertext("Qcxvii - Dangerous Monsters\n"); 
	b4->set_bookfile("/players/qclxxiv/library/dangerousmonsters.txt");
	b5->set_covertext("Qclxxiv - On Magic Weapons\n"); 
	b5->set_bookfile("/players/qclxxiv/library/magicweapons.txt");
}
