inherit "/players/qclxxiv/qquest/mappiece";
reset(arg) {
	/*
	if (!map) {
		map = allocate(7);
		map = ({
		" . . . . . |",
		" . . . . . |",
		" . . . . . |",
		" . . . . . |",
		" . . . . . |",
		"----------- ",
		  	});
	}
	*/
	if (!backside) {
		backside = allocate(7);
		backside = ({
		"|             ",
		"|  H hut    !d",
		"|  W well   el",
		"|  F firehouse",
		"|  S statue   ",
		"|  C chest  en",
		" -------------",
		  	});
	}
	if (arg) return;
	extraid = "lower right piece";
	pieceno = 4;
}
