inherit "/players/qclxxiv/qquest/mappiece";

reset(arg) {
	/* 
		if (!map) {
		map = allocate(7);
		map = ({
		"___________ ",
		" . . . . . |",
		" . . . . . |",
		" . . . . . |",
		" . . . . . |",
		" . . . . . |",
		" . . . . . |",
		  	});
	}
	*/
	if (!backside) {
		backside = allocate(7);
		backside = ({
		" _____________",
		"|  Island of t",
		"|  @ whirl   &",
		"|  . beach   |",
		"|  - dell    $",
		"|  ^ dune    #",
		"|  + forest  ^",
		  	});
	}
	if (arg) return;
	extraid = "upper right piece";
	pieceno = 1;
}

