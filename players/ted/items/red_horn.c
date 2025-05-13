inherit "obj/treasure";
object knight;

reset(arg) {
  if(arg) return;
  set_id("red horn");
  set_alias("horn");
  set_short("A Blood Red Horn");
  set_long(
"This massive horn was carved from the skull of a red dragon.\n\n"+
"A small plaque reads:\n\nBlow horn to challenge Knight\n");
  set_weight(25);
}

get() {
  write("The horn is securly fastened to the oak tree\n");
  return 0;
}

init() {
  ::init();
  add_action("blow"); add_verb("blow");
}

blow(str) {
 if(str == "horn" && !present("red knight")) {
    write("The Red Knight Comes out of his pavilion\n");
    say(this_player()->query_name()+" blows the horn.\n");
    say("The Red Knight comes out of his pavilion\n");
    knight = clone_object("players/ted/monsters/red_knight");
    call_other("players/ted/random_armor","make_item",knight,16);
    call_other("players/ted/random_magic","make_item",knight,16);
    move_object(knight, environment(this_player()));
    call_other(knight, "attack_object", this_player());
    destruct(this_object());
    return 1;
  }
}
