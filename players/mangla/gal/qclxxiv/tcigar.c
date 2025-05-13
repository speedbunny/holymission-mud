/* Cigar - Qclxxiv, parody on Spliff   trick version
*/
#define PLAYERNAME this_player()->query_name()
inherit "players/qclxxiv/cigar";

int touched;
id(str) { return (str == "cigar") || str == "trick cigar" 
				|| str == SORT || str=="cigar_trick"; }
short() { if (!touched) return "A trick cigar (havanna)";
			return ::short(); }
long()  { 
	if (!touched) 
		write(
"The 'trick' in the name will vanish if you give away or drop and get the\n"
+"cigar.  Have fun with it.\n" );
	::long();
}
get()	{ touched = 1; return 1; }

reset(arg) {
	::reset();
	if (arg) return;
	SORTKEY = "cigar_trick";
	return 1;
}

smoke_cigar(str) {
	::smoke_cigar(str);
	if (draws==5) {
		bang(environment(this_player()));	
		this_player()->set_alignment("blackened and sooty");
		write(
		"The cigar exploded in your face. You stand up, feeling very dizzy.\n");
		say(PLAYERNAME + " stands up again and is obviously very dizzy.\n");
		destruct(this_object());
	}
	return 1;
}

bang(aroom) {
	tell_room(aroom,
"######     #    #     #  #####    ###     ###     ###     ###\n"+
"#     #   # #   ##    # #     #   ###     ###     ###     ###\n"+
"#     #  #   #  # #   # #         ###     ###     ###     ###\n"+
"######  #     # #  #  # #  ####    #       #       #       #\n" );
	tell_room(aroom,
"#     # ####### #   # # #     #\n"+
"#     # #     # #    ## #     #   ###     ###     ###     ###\n"+
"######  #     # #     #  #####    ###     ###     ###     ###\n"
			);
}
