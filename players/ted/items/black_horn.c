inherit "obj/treasure";
object knight, sword;

reset(arg) {
  if(arg) return;
  set_id("black horn");
  set_alias("horn");
  set_short("A Midnight Black Horn");
  set_long(
"A large black horn, carved and inlaid with mother of pearl\n\n"+
"A small plaque reads:\n\nBlow horn to challenge Knight\n");
  set_weight(25);
}

get() {
  write("The horn is fastened to the oak tree\n");
  return 0;
}

init() {
  ::init();
  add_action("blow"); add_verb("blow");
}

blow(str) {
 if((str == "horn") && !present("black knight")) {
    write("The Black Knight Comes out of his pavilion\n");
    say(this_player()->query_name()+" blows the horn.\n");
    say("The Black Knight comes out of his pavilion\n");
    knight = clone_object("players/ted/monsters/black_knight");
    sword = clone_object("players/ted/weapons/unholy_avenger");
    move_object(sword, knight);
    call_other(knight, "init_command", "wield sword");
    call_other(knight, "set_wc", 30);
    move_object(knight, environment(this_player()));
    call_other(knight, "attack_object", this_player());
    destruct(this_object());
    return 1;
  }
}
