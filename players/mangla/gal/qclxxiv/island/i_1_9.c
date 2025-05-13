/* islgen 1.0 clean - island room 1-9 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/whirl";

extra_reset(arg) {
	::extra_reset(arg);
	if (arg) return;
	destination = "players/qclxxiv/island/i_1_10";
	x = 1;
	y = 9;
}
