/* islgen 1.0 clean - island room 1-1 (remove 'clean' if touched by hand) */
inherit "players/qclxxiv/island/whirl";

extra_reset(arg) {
	::extra_reset(arg);
	if (arg) return;
	destination = "players/qclxxiv/island/i_1_2";
	x = 1;
	y = 1;
}
