inherit "players/qclxxiv/leaf6/scratcher";
reset(arg) {
	::reset(arg);
	if (arg) return;
	set_maxleft(25);
	set_maxhit(30);
	set_maxvalue(350);
	set_maxweight(7);
	set_short("A huge scratcher" );
	return 1;
}

