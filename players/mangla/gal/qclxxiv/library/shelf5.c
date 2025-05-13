inherit "players/qclxxiv/library/shelf.c";

reset(arg) {	/* just wrap around default reset in order to make real books*/
	::reset(arg);
	if (arg) return;
	/* books are pointed to by b1 to b5. */
	b1->set_covertext("Qcxliv - Fighting the Island Dragon\n"); 
	b1->set_bookfile("/players/qclxxiv/library/fightingdragon.txt");
	b2->set_covertext("Qcxv - Fishing Spells and Curses\n"); 
	b2->set_bookfile("/players/qclxxiv/library/fishingspells.txt");
	b3->set_covertext("Qcxxi - Farming Spells and Curses\n"); 
	b3->set_bookfile("/players/qclxxiv/library/farmingspells.txt");
	b4->set_covertext("Qclxxii - Heraldry of the Leaf\n"); 
	b4->set_bookfile("/players/qclxxiv/library/heraldry.txt");
	b5->set_covertext("<a77a3IE <0A1I8a1Io7 - 9XA8II"); 
	b5->set_bookfile("/players/qclxxiv/library/unreadable.txt");
}
