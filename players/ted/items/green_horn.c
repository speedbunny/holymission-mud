inherit "obj/treasure";
object knight, shield;

reset(arg) {
  if(arg) return;
 set_id("green horn");
 set_alias("horn");
 set_short("An Olive Green Horn");
 set_long(
"A beautifully carved horn, made from a green dragons skull.\n\n"+
"A small plaque reads:\n\nBlow horn to challenge Knight\n");
 set_weight(25);
}

get() {
  write("The horn is securly fastened to the tree!\n");
  return 0;
}

init() {
  ::init();
  add_action("blow"); add_verb("blow");
}

blow(str) {
 if(str == "horn" && !present("green knight")) {
    write("The Green Knight Comes out of his pavilion\n");
    say(this_player()->query_name()+" blows the horn.\n");
    say("The Green Knight comes out of his pavilion\n");
    knight = clone_object("players/ted/monsters/green_knight");
    call_other("players/ted/random_magic","make_item",knight,19);
    shield = clone_object("players/ted/armors/green_platemail");
    move_object(shield, knight);
    knight->init_command("wear armor");
    knight->set_ac(12);
    move_object(knight, environment(this_player()));
    knight->attack_object(this_player());
    destruct(this_object());
    return 1;
  }
}
