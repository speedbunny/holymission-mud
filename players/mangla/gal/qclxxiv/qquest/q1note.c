inherit "/obj/treasure";
string monster_name;

reset(arg) {
	if (arg) return;
	set_id("note");
	set_short("A note");
	set_long("A note. Maybe you should read it.\n");
	monster_name = ({
			"one of those huge grabbits",
			"one of those bloody vipers",
			"one of those stupid vultures",
			"one of those nasty skunks",
			"one of those big whiteflies",
			"one of those silly greenbugs",
			"one of those redmargined aphids",
			"that stupid dwarf wizard",
			});
}

init() {
	::init();
	add_action("read","read");
}

read(arg) {
	if (id(arg)) {
		write("Now I had finally found the bloody piece,\n"
		 +"I had to loose it to " + 
		monster_name["/players/qclxxiv/qquest/qmast"->lock_name2key( 1,
						this_player()->query_real_name() )]
		+"...and it run away!\n" );	
		call_out("self_dest", 2);
		return 1; 
	}
	return 0;
}

self_dest() {
	write("The note crumbles to dust.\n");
	destruct(this_object());
}
