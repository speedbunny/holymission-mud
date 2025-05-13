/* Notebook - Qclxxiv  jun 24, 92
*/
#define PLAYERNAME this_player()->query_name()
int notes;
string topnote;
id(str) { return str == "notebook"; }

short() { if (notes<1) return "remainders of a notebook"; 
		return "a notebook"; }
long()  { 
	write("This is a notebook. Use: 'note <some text>, tear off note'.\n");
	write("Now you can leave a message for your party fellows etc.!!!\n");
	write("There are "+notes+" notes left in the notebook.\n");
	if (notes>0) {
		if (topnote[notes-1]) 
			write("The upper note reads: "+topnote[notes-1]+"\n");
		else write("The upper note is still empty.\n");
	}
}
get()	{ return 1; }
query_weight() { return 1+(notes/5); }
query_value() { return notes*5; }

reset(arg) {
	if (arg) return;
	notes=10;
	if (!topnote) topnote = allocate(10);
	return 1;
}

init()  { 
	add_action("tear_note", "tear" );
    add_action("note_note", "note" );
    add_action("draw_note", "draw" );
	add_action("showcarbon","showcarbon" );
}

tear_note(str) {
	object note;
	if ((!str) || (str != "off note")) { return 0; }
	if (notes<1) {
		write("No notes left.\n");
		return 1;
	}
	note=clone_object("players/qclxxiv/obj/gnote");
	if (topnote[notes-1])
		note->set_read("The note reads:\n" + topnote[notes-1] + "\n" );
	move_object(note,this_player());
	write("You tear off a note from your notebook.\n");
    say(PLAYERNAME+" tears off a note from a notebook.\n");
	notes--;
	return 1;
}

draw_note(str) {
	if ((!str)) { return 0; }
	return note_note("A drawing of: "+str);	
}

note_note(str) {
	if ((!str)) { return 0; }
	if (notes<1) {
		write("No notes left.\n");
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
	if (topnote[notes-1]) {
		write("You already dabbled this note full entirely.\n");
		return 1;
	}
	topnote[notes-1] = str;
	write("You scrawl a note full.\n");
    say(PLAYERNAME + " scrawls a note full.\n");
	return 1;
}

showcarbon(str) {
	int i;
	write("notes written on this notebook: \n");
	for (i=9; i>=0; i--)
		if (topnote[i])
			write( i + ": " + topnote[i] + "\n" );
	return 1;
}


