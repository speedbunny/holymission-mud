/* islgen 1.0 clean - island room 3-11 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/whirl";

extra_reset(arg) {
	::extra_reset(arg);
	if (arg) return;
	destination = "players/qclxxiv/island/i_4_11";
	x = 3;
	y = 11;
}
