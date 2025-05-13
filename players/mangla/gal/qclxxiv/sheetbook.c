/* Sheetbook - Qclxxiv  July 8(or so), 92
*/
#define PLAYERNAME this_player()->query_name()
int sheets;
string topsheet;
id(str) { return str == "sheetbook"; }

short() { if (sheets<1) return "remainders of a sheetbook"; 
		return "a sheetbook"; }
long()  { 
	write("This is a sheetbook. Use: 'note <some text>, tear off sheet'.\n");
    write("Wrap around for multiple lines. This will be improved in future.\n");
	write("Now you can leave a broadsheet for the mud's society etc.!!!\n");
    write("What you note on it will be visible for all if you tear and drop\n");
    write("a sheet at a good place." );
	write("I.e. ideal to pass playerkiller info to all!!!\n");
	write("There are "+sheets+" sheets left in the sheetbook.\n");
	if (sheets>0) {
		if (topsheet[sheets-1]) 
			write("The upper sheet reads:\n"+topsheet[sheets-1]+"\n");
		else write("The upper sheet is still empty.\n");
	}
}
get()	{ return 1; }
query_weight() { return 2+(sheets/5); }
query_value() { return sheets*10; }

reset(arg) {
	if (arg) return;
	sheets=3;
	if (!topsheet) topsheet = allocate(3);
	return 1;
}

init()  { 
	add_action("tear_sheet", "tear" );
    add_action("draw_sheet", "draw" );
    add_action("sheet_sheet", "sheet" );
    add_action("sheet_sheet", "note" );
	add_action("showcarbon","showcarbon" );
}

tear_sheet(str) {
	object sheet;
	if ((!str) || (str != "off sheet")) { return 0; }
	if (sheets<1) {
		write("No sheets left.\n");
		return 1;
	}
	sheet=clone_object("obj/weapon");  /*notes and sheets are weapons:-)*/
	sheet->set_id("sheet");
	sheet->set_alias("broadsheet"); 
	sheet->set_class(5);
	sheet->set_weight(0);
	sheet->set_value(0);
	sheet->set_short("A broadsheet:\n" + topsheet[sheets-1] );
	sheet->set_long("A broadsheet:\n" + topsheet[sheets-1] + "\n" );
	sheet->set_read("The sheet reads:\n" + topsheet[sheets-1] + "\n" );
	move_object(sheet,this_player());
	write("You tear off a broadsheet from your sheetbook.\n");
    say(PLAYERNAME+" tears off a broadsheet from a sheetbook.\n");
	sheets--;
	return 1;
}

draw_sheet(str) {
	if ((!str)) { return 0; }
	return sheet_sheet("A drawing of: "+str);	
}
sheet_sheet(str) {
	if ((!str)) { return 0; }
	if (sheets<1) {
		write("No sheets left.\n");
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
		write("You already dabbled this sheet full entirely.\n");
		return 1;
	}
	topsheet[sheets-1] = str;
	write("You scrawl a sheet full.\n");
    say(PLAYERNAME + " scrawls a sheet full.\n");
	return 1;
}

showcarbon(str) {
	int i;
	write("sheets written on this sheetbook: \n");
	for (i=2; i>=0; i--)
		if (topsheet[i])
			write( i + ":\n" + topsheet[i] + "\n" );
	return 1;
}


