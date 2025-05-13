#include "/players/qclxxiv/myroom.h"
object tree, stem;

NO_EXIT( "In the crown of a tree", "", 1)

set_tree(ob) { tree = ob; }
set_stem(ob) { stem = ob; }

long(arg) {
	if (!arg) {
		write(	
		"In the crown of "+lower_case(tree->ishort())
		+". Apparently you can enter the\n"
		+"hollow stem here, or go down again.\n");
/*		show_inventory_pl(arg, this_player());*/
		return 1;
	}
	return 0;
}

init() {
	::init();
	add_action("down","down");
	add_action("enter","enter");
	add_action("enter","into");
}

down(arg) {
	this_player()->move_player("down",environment(tree));
	return 1;
}

enter(arg) {
	if (arg!="stem" && arg!="tree" && arg!="hollow stem") return 0;
	this_player()->move_player("into hollow stem",stem);
	return 1;
}
