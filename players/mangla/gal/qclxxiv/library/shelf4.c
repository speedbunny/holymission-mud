inherit "players/qclxxiv/library/shelf.c";

reset(arg) {	/* just wrap around default reset in order to make real books*/
	::reset(arg);
	if (arg) return;
	/* books are pointed to by b1 to b5. */
	b1->set_covertext("Qcxxviii - Cursing Regions\n"); 
	b1->set_bookfile("/players/qclxxiv/library/cursingregions.txt");
	b2->set_covertext("Qxlvii - On Plants\n"); 
	b2->set_bookfile("/players/qclxxiv/library/onplants.txt");
	b3->set_covertext("Qlvii - On AgriMagical Spells\n"); 
	b3->set_bookfile("/players/qclxxiv/library/agrimagicalspells.txt");
	b4->set_covertext("Qclxxiii - A History Of The Leaf\n"); 
	b4->set_bookfile("/players/qclxxiv/library/history.txt");
	b5->set_covertext("Qcxx - The `Island Dragon'\n"); 
	b5->set_bookfile("/players/qclxxiv/library/islanddragon.txt");
}
