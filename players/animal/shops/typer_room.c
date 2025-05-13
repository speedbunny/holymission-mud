short() { return "A small nondescript room"; }

long() {
	write("This room was built to rid you of your quicktyper.\n"+
	"Just type in gone, and the typer will be gone.\n");
	write("\nThe only exit is east.\n");
}

init() {
	add_action("east","east");
	add_action("gone","gone");
}

gone() {
	object ob;
	ob=present("quicktyper",this_player());
	if(!ob)  return 0;
	destruct(ob);
	write("Your quicktyper is now gone.\n");
	write("Now you can just use the box.\n");
	write("Which is all you will ever need.\n");
	return 1;
}
reset(arg) {
	if(arg) return;
	set_light(1);
}

east() {
	this_player()->move_player("east#players/animal/shops/shop_street3");
	return 1;
}
