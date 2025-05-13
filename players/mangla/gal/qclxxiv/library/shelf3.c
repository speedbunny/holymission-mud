inherit "players/qclxxiv/library/shelf.c";

reset(arg) {	/* just wrap around default reset in order to make real books*/
	::reset(arg);
	if (arg) return;
	/* books are pointed to by b1 to b5. */
	b1->set_covertext("Qclxv - Frog Spells and Defrogging\n"); 
	b1->set_bookfile("/players/qclxxiv/library/frogspells.txt");
	b2->set_covertext("Qclvi - Elementary Spells For Space-Folding\n"); 
	b2->set_bookfile("/players/qclxxiv/library/spacefolding.txt");
	b3->set_covertext("Qclix - Techniques of Temporal Magic\n"); 
	b3->set_bookfile("/players/qclxxiv/library/temporalmagic.txt");
	b4->set_covertext("Qcxxiv - Cursing Objects\n"); 
	b4->set_bookfile("/players/qclxxiv/library/cursingobjects.txt");
	b5->set_covertext("Qcxxvi - Cursing Creatures\n"); 
	b5->set_bookfile("/players/qclxxiv/library/cursingcreatures.txt");
}
