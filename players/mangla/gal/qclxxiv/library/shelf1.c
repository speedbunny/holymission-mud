inherit "players/qclxxiv/library/shelf.c";

reset(arg) {	/* just wrap around default reset in order to make real books*/
	::reset(arg);
	if (arg) return;
	/* books are pointed to by b1 to b5. */
	b1->set_covertext("Qcxi - Monster Creating\n"); 
	b1->set_bookfile("/players/qclxxiv/library/monstercreating.txt");
	b2->set_covertext("Qcxx - Tidal Control\n"); 
	b2->set_bookfile("/players/qclxxiv/library/tidalcontrol.txt");
	b3->set_covertext("Qcxlvi - Weather Control\n"); 
	b3->set_bookfile("/players/qclxxiv/library/weathercontrol.txt");
	b4->set_covertext("Qlxxxiv - Turning Lead into Gold\n"); 
	b4->set_bookfile("/players/qclxxiv/library/leadintogold.txt");
	b5->set_covertext("Qclii - Alchemy against Insects\n"); 
	b5->set_bookfile("/players/qclxxiv/library/alchemyinsects.txt");
}
