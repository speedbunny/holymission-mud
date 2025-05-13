inherit "room/room";

reset(arg) {
  if(!present("bear")) {
    object c;
    move_object(c=clone_object("players/moonchild/gnome/crystal"),make_bear(2));
    c->set_type(2);
    make_bear(1);
  }
  if(arg) return;
  short_desc="In a bear pit";
  long_desc="This is the northern end of the bear pit.\n";
  dest_dir=({ "players/moonchild/gnome/cubs", "south" });
  property=({ "no_teleport" });
}

make_bear(arg) {
  object b;
  move_object(b=clone_object("obj/monster"),this_object());
  b->set_name("bear");
  b->set_short("A huge bear");
  b->set_long("This is a huge bear. But there's something terribly wrong.\n");
  b->set_gender(arg);
  b->set_level(18);
  b->set_hp(440);
  b->set_wc(26);
  b->set_ac(15);
  b->set_chance(36);
  b->set_spell_dam(70);
  b->set_spell_mess1("Bear lashes out!");
  b->set_spell_mess2("Bear claws you in the face. Blood spurts out!");
  b->set_aggressive(1);
  b->set_al(-150);
  return b;
}
