#include "/players/qclxxiv/myroom.h"
#undef EXTRA_RESET
#define EXTRA_RESET extra_reset(arg);
query_qnewbie() { return 1; }
query_newbiehint() { 
	return "The dwarfs here are generally too strong for low level\n"
		+"players..however if you feel strong you might try a dwarf soldier.\n"
		+"Better not to attack other dwarfs though. Good food can be found\n"
		+"here, and the dwarfs arent aggresive, even though the area is not\n"
		+"further marked as safe.\n";
}

extra_reset(arg) {
	if (arg) return;
	items = ({ "trees", "Oaks, birches, and some beeches",
				"tree", "An old oak",
				"oak", "Another old oak",
				"beech", "An old smooth beech",
				"birch", "An old silvery birch",
				"oaks", "Old oaks",
				"beeches", "Old smooth beeches",
				"birches", "Old silvery birches",
				"wood", "A dense wood, made up of oaks, birches, and beeches",
				"birds", "They are somewhere in the trees, you can't see them"
			});
}

TWO_EXIT( "players/qclxxiv/circular/circ7","north",
"players/qclxxiv/leaf7/r6","southwest",
"Between some trees",
"It's weird, but in here there are actually trees growing....and to the\n"+
"west and southwest apparently there is a wood. You hear birds chirping.\n"+
"Be careful not to step on anything.\n",1)
