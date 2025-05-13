
id(str) {
 return str == "rod" || str == "rod of resurrection" || str == "platinum rod";
}

short() {
  return "A Platinum Rod";
}

long() {
 write("This thin platimun rod is quite light and almost seems to glow.\n");
 return 1;
}

init() {
 if(environment() != this_player()) return 1;
 add_action("pray"); add_verb("raise");
 add_action("pray"); add_verb("resurrect");
}

drop() { return 0; }
get() { return 1; }
query_name() { return "Rod of Resurrection"; }
query_value() { return 1200; }
query_weight() { return 1; }
query_charges() { return "Unlimited"; }

pray(arg) {
 object ob;
  ob = present(arg, environment(this_player()));
  if(!ob) {
	write(arg+" must be present.\n");
	return 1;
  }
  if(!ob->query_ghost()) {
    write(arg+" is not a ghost!\n");
    return 1;
  }
 write("You touch "+arg+" with the rod.\n");
 say(this_player()->query_name()+" touches the ghost of "+arg+" with A Platimun Rod.\n");
  ob->remove_ghost();
 return 1;
}

query_info() {
	write("This is a rod of resurrection. Type 'raise <player>' to use.\n");
	write("This rod is the same as the priest restore spell.\n");
	return;
}
