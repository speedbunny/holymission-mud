inherit "/obj/treasure";

/* default setting is to facilitate the notebook */
reset(arg) {
	if (arg) return;
	set_id("note");
	set_alias("note174");
	set_weight(0);
	set_value(3);
	set_short("A note"); 
	set_long("A small note, circa 10 by 7 cm in size.\n" );
}

init() {
	::init();
    if (read_msg)	/* in this case ::init does the add_action */
		return;
    add_action("read", "read");
}

read(str) {
    if (!id(str)) return 0;
	if (read_msg) write(read_msg);
	else write("The note is empty.\n" );
    return 1;
}

query_text() { return read_msg; }
