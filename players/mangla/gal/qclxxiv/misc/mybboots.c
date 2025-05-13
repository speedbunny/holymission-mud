inherit "/players/helenette/bboots";
int hidden;

query_auto_load() { return "players/qclxxiv/misc/mybboots:"; }

short() { 
	if (hidden) return 0;
	return ::short(); 
}

reset(arg) {
	if (arg) return;
	hidden =1;
}

init()  { 
	::init();
	add_action("hide", "hide" );
}

hide(arg) {
	if (id(arg)) {
		if (hidden) hidden=0; else hidden=1;
		return 1;
	}
	return 0;
}

