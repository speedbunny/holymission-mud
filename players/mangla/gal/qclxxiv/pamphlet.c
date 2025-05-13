/* Pamphlet - Qclxxiv  later than July 8(or so), 92
// Goes with lpamphlet.c !!!
*/
#define PLAYERNAME this_player()->query_name()
int sheets;
string topsheet;
id(str) { return str == "pamphlet" || ((sheets<1)&&(str=="film")); }

short() { if (sheets<1) return "film from backside of a pamphlet"; 
		return "a Pamphlet"; }
long()  { 
	write("This is a Self-adhesive Pamphlet (Semi-permanent placable).\n"+
		"Use: note <some text>, tear off pamphlet, drop pamphlet'.\n");
    write("Wrap around for multiple lines. This will be improved in future.\n");
	write("If you do this for the first time, perhaps it is best to practice\n"+
			"with a (much cheaper) notebook first.\n" );
	write("Now you can leave a Pamphlet for the mud's society etc.!!!\n");
    write("What you note on it will be visible for all if you tear and drop\n");
    write(
		"a Pamphlet at a good place. It cannot be taken up after dropping!!!\n" );
	write("I.e. ideal to pass playerkiller info to all!!!\n");
	write("Moreover, now, you as a player can give a place in the mud a\n"+
		"personal note (until next game reboot). A good description can\n"+
		"look like a monster, player, object, etc. at first sight!!!!!\n");
	if (sheets>0) {
		if (topsheet[sheets-1]) 
			write("The Pamphlet reads:\n"+topsheet[sheets-1]+"\n");
		else write("The Pamphlet is still left unwritten.\n");
	}
}
get()	{ return 1; }
query_weight() { return 2*sheets; }
query_value() { return sheets*500; }

reset(arg) {
	if (arg) return;
	sheets=1;
	if (!topsheet) topsheet = allocate(1);
	return 1;
}

init()  { 
	add_action("tear_sheet", "tear" );
    add_action("sheet_sheet", "pamphlet" );
    add_action("sheet_sheet", "note" );
	add_action("showcarbon","showcarbon" );
}

tear_sheet(str) {
	object sheet;
	if ((!str) || (str != "off pamphlet")) { return 0; }
	if (sheets<1) {
		write("What do you want to tear off?\n"+
		"Only the film from the pamphlet's backside is left.\n");
		return 1;
	}
	sheet=clone_object("players/qclxxiv/obj/lpamphlet");  
/*
	sheet=clone_object("obj/weapon");  
	sheet->set_id("pamphlet");
	sheet->set_alias("pamflet"); 
	sheet->set_class(9);
	sheet->set_weight(32000);
	sheet->set_value(500);
*/
	sheet->set_short(topsheet[sheets-1] );
	sheet->set_long("A pamphlet:\n" + topsheet[sheets-1] + "\n" );
	sheet->set_read("The pamhlet reads:\n" + topsheet[sheets-1] + "\n" );
	move_object(sheet,this_player());
	write("You tear off the protective film of the Pamphlet.\n");
    say(PLAYERNAME+" tears off the protective film of a Pamphlet.\n");
	sheets--;
	return 1;
}

sheet_sheet(str) {
	if ((!str)) { return 0; }
	if (sheets<1) {
		write("Only a Pamphlet's protective film left.\n");
		return 1;
	}
	if (!present("quill", this_player())) {
		write("But you have no quill...\n");
		return 1;
	}
	if (!present("ink", this_player())) {
		write("But you have no ink...\n");
		return 1;
	}
	if (topsheet[sheets-1]) {
		write("You already dabbled this Pamphlet full entirely.\n");
		return 1;
	}
	topsheet[sheets-1] = str;
	write("You scrawl a Pamphlet full.\n");
    say(PLAYERNAME + " scrawls a Pamphlet full.\n");
	return 1;
}

showcarbon(str) {
	int i;
	write("Pamphlet written on this film: \n");
	for (i=0; i>=0; i--)
		if (topsheet[i])
			write( /* i + ":\n" + */ topsheet[i] + "\n" );
	return 1;
}
