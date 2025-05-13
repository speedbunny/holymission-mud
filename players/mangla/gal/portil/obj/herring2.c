#define FILENAME "players/portil/obj/title_changer"
id(str) {return str=="herring";}
short() {
        return "A herring"; }
long() { 
        write("It is a herring. It could well be red.\n"); }
get() { return 1; }
drop() { return 1; }
query_auto_load() { return FILENAME + ":"; }

init () {
  if (this_player()->query_real_name()=="portil") {
    shadow(this_player(),1);
    }
    add_action ("eat", "eat");
}

eat(string str) {
	if(str!="herring") {
		notify_fail("Eat what?\n");
		return 0;
	}
	write("You eat the herring.\n");
	destruct(this_object());
	return 1;
}

string query_title() {
	string name;
	switch(random(10)) {
		case 0:
			return "takes up as much space on you screen as possible with his title                     Oh yes he does.                                                                   Well if you dont believe me.                                                                   In fact he going to have another line.                                                    Eponone tells you: Hello!";
		case 1:
			return "changes his title too often";
		case 2:
			return "lover of all things in the kipper clan";
		case 3:
			return "loves small furry animals (OOo-eerrr)";
		case 4:
			name=capitalize(this_player()->query_real_name());
			return "tells you: "+name+" is the best mudder I know!";
		case 5:
			return "says: Blark is useless at football";
		case 6:
			return "thinks that Manchester United are THE best";
		case 7:
			return "can`t wait to go to Alton Towers!";
		case 8:
			return "eats small animals for fun (Grrrrr)";
		case 9:
			return "pokes you in the eye";
	}
}
