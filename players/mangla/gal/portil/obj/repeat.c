string command;

id(string str) { return (str=="repeater"); }

short() { return "A repeater"; }
long() { write("It works like converse but is usefull for repeating commands\nJust type repeat <command to repeat>\n");
}

get() { return 1; }
drop() { return 0; }

init() {
	add_action("repeat","repeat");
	}

repeat(string str) {
	if(!str) {
		notify_fail("What command do you wan to use with repeat?\n");
		return 0;
	}
	command=str;
	write("** to stop!\n]");
	input_to("more");
	return 1;
}

more(string more) {
	if(more=="**") return 1;
	command(command+" "+more,this_player());
	input_to("more");
	write("]");
	return 1;
}
