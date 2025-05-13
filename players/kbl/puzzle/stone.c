inherit "obj/treasure";

string finder;

reset(arg) {
  if(arg) return;
  set_id("stone");
  set_alias("puzzle_quest_stone");
  set_value(250);
  set_short("A small stone");
  set_long("A small shimmering black stone. It looks as if it may have\n"
	+ "magical properties. There is something written on it.\n");
  set_read("There is something written on it, it reads like: ..l th. .am.\n");
}

set_finder(str) {
  if(file_name(previous_object())!="players/moonchild/puzzle/lake_bottom") {
    log_file("moonchild.quest", ctime(time()) + ": " +
        this_player()->query_name() + " (level " + this_player()->query_level()
        + ") (" + capitalize(this_player()->query_real_name()) + ")\n\t\t\t  "
        + "tried to set stone finder to " + str + ".\n");
  }
  finder=str;
}

query_finder() { return finder; }
