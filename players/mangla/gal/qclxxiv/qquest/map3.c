inherit "/players/qclxxiv/qquest/mappiece";
reset(arg) {
	/*
	if (!map) {
		map = allocate(7);
		map = ({
		"| . . . . .",
		"| . . . . .",
		"| . . . . .",
		"| . . . . .",
		"| . . . . .",
		"| . . . . .",
		" ----------",
		  	});
	}
	*/
	if (!backside) {
		backside = allocate(7);
		backside = ({
		"            |",
		"ont dig     |",
		"sewhere!    |",
		"            |",
		"Q: here u   |",
		"ter island  |",
		"------------",
		  	});
	}
	if (arg) return;
	extraid = "lower left piece";
	pieceno = 3;
}
