/* islgen 1.0 clean - island room 11-8 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/whirl";

extra_reset(arg) {
	::extra_reset(arg);
	if (arg) return;
	destination = "players/qclxxiv/island/i_10_8";
	x = 11;
	y = 8;
}
