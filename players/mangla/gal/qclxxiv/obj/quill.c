inherit "/obj/treasure";

reset(arg) {
	if (arg) return;
	set_id("goose-quill");
	set_alias("quill");
	set_weight(0);
	set_value(10);
	set_short("A goose-quill"); 
	set_long("A goose-quill, with its point sharpened for writing.\n" );
}

