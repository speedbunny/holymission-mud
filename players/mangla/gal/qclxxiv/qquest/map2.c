inherit "/players/qclxxiv/qquest/mappiece";
reset(arg) {
	/*
	if (!map) {
		map = allocate(7);
		map = ({
		" __________",
		"| . . . . .",
		"| . . . . .",
		"| . . . . .",
		"| . . . . .",
		"| . . . . .",
		"| . . . . .",
		  	});
	}
	*/
	if (!backside) {
		backside = allocate(7);
		backside = ({
		"____________ ",
		"he Dragon   |",
		" mail       |",
		" lance      |",
		" poison     |",
		" compass    |",
		"dig(4x)     |",
		  	});
	}
	if (arg) return;
	extraid = "upper left piece";
	pieceno = 2;
}
