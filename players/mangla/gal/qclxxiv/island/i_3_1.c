/* islgen 1.0 clean - island room 3-1 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/whirl";

extra_reset(arg) {
	::extra_reset(arg);
	if (arg) return;
	destination = "players/qclxxiv/island/i_2_1";
	x = 3;
	y = 1;
}
