/* islgen 1.0 clean - island room 10-9 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/whirl";

extra_reset(arg) {
	::extra_reset(arg);
	if (arg) return;
	destination = "players/qclxxiv/island/i_10_10";
	x = 10;
	y = 9;
}
