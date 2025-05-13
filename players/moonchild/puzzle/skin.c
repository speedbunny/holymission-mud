inherit "obj/armour";

string finder;

query_ninja_wear() { return 1; }
query_monk_wear() { return 1; }
query_mage_wear() { return 1; }

reset(arg) {
  if(arg) return;
  ::reset();
  set_name("skin");
  set_alias("puzzle_quest_skin");
  set_ac(1);
  set_value(250);
  set_short("Magical snake skin");
  set_long("This is magical snake skin. It shimmers with the light and\n"
	+ "must surely have some kind of protective properties.\n");
}

wear(str) {
  if(!id(str)) return;
  if(this_player()->query_real_name()!=finder)
	return write("You don't seem to be able to wear it. It doesn't seem to want to fit you.\n");
  return ::wear("skin");
}

set_finder(str) {
  if(file_name(previous_object())!="players/moonchild/puzzle/undermon") {
    log_file("moonchild.quest", ctime(time()) + ": " +
        this_player()->query_name() + " (level " + this_player()->query_level()
        + ") (" + capitalize(this_player()->query_real_name()) + ")\n\t\t\t  "
        + "tried to set stone finder to " + str + ".\n");
  }
  finder=str;
}

query_finder() { return finder; }
