inherit "players/qclxxiv/leaf6/scratcher";
reset(arg) {
	::reset(arg);
	if (arg) return;
	set_maxleft(25);
	set_maxhit(25);
	set_maxvalue(200);
	set_maxweight(5);
	set_short("A big scratcher" );
	return 1;
}

