
id(str) {return str == "word" || str == "the word of speech";}
short() {return "The Word of free speech";}
long() {return "It enables you to talk and emote freely.\n";}
get() {return 1;}
drop() {return 1;}
query_weight() {return 0;}
query_value() {return 0;}
reset() { }
init() {
    if (environment() == this_player())
	write("You have the Word now!\n");
}
