/* islgen 1.0 clean - island room 0-5 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/whirl";

extra_reset(arg) {
	::extra_reset(arg);
	if (arg) return;
	destination = "players/qclxxiv/island/i_0_6";
	x = 0;
	y = 5;
}
