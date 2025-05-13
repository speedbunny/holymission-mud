inherit "room/room";

reset(arg) {
  if(!present("bear cub")) {
    object b;
    int i;
    for(i=random(2);i<4;i++) {
      move_object(b=clone_object("obj/monster"),this_object());
      b->set_name("bear cub");
      b->set_alias("cub");
      b->set_race("bear");
      b->set_short("A not-so-little bear cub");
      b->set_long("There's something strange about this bear cub.\n");
      b->set_gender(1+random(2));
      b->set_level(10+random(6));
      b->set_chance(20);
      b->set_spell_dam(40);
      b->set_spell_mess1("Bear cub lashes out!");
      b->set_spell_mess2("Bear cub hits you with "
	+ b->query_possessive() + " paw!");
      b->set_aggressive(1);
      b->set_al(-100);
    }
  }
  if(arg) return;
  short_desc="In a bear pit";
  long_desc="You have stumbled into what was once a bear pit.\n"
	+ "It appears that bear cubs spend a lot of time here.\n"
	+ "The exit to the south is rather narrow.\n";
  dest_dir=({ "players/moonchild/gnome/bears", "north",
	"players/moonchild/gnome/inpit", "south" });
  property=({ "no_teleport" });
}

move(str) {
  switch(query_verb()) {
    case "north":
	if(!present("bear cub")) return ::move(str);
	write("Your way is barred by the bear cub.\n");
	return 1;
	break;
    case "south":
	if(this_player()->query_weight()<10) return ::move(str);
	write("You are carrying too much to squeeze through!\n");
	return 1;
	break;
  }
}
