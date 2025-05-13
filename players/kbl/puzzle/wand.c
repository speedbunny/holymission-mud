inherit "obj/treasure";

string finder;

id(str) { return str=="wand" || str=="glass wand" || str=="enter_puzzle_wand"; }

reset(arg) {
  if(arg) return;
  set_id("wand");
  set_alias("glass wand");
  set_value(200);
  set_short("A shining glass wand");
  set_long("A shining glass wand. There is something written on it.\n");
  set_read("On it are some runes, depicting a magical room with six stones hanging in the\n"
	+ "air. Some writing tells the story of how this room forms a natural prison and\n"
	+ "that this wand is the only way of leaving it without .... You're not sure what\n"
	+ "the rest of it says, it has become blurred, but it seems to talk about perfect\n"
	+ "symmetry and about a strange-looking stone.\n");
}

init() { ::init(); add_action("wave", "wave"); }

set_finder(str) {
  if(file_name(previous_object())!="players/moonchild/haunter/cave2") {
    log_file("moonchild.quest", ctime(time()) + ": " +
	this_player()->query_name() + " (level " + this_player()->query_level()
	+ ") (" + capitalize(this_player()->query_real_name()) + ")\n\t\t\t  "
	+ "tried to set wand finder to " + str + ".\n");
  }
  finder=str;
}

query_finder() { return finder; }

wave(str) {
  int result,tmp2;
  if(!id(str)) return 0;
  if(!sscanf(file_name(environment(this_player())),"players/moonchild/puzzle/puzzle#%d",tmp2)) {
    say(this_player()->query_name() + " waves a glass wand about. Nothing happens.\n");
    return write("You wave the glass wand about. Nothing happens.\n");
  }
  say(this_player()->query_name() + " waves a glass wand about.\n");
  environment(this_player())->church();
  return 1;
}
