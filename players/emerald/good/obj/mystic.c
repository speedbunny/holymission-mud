inherit "obj/monster";

reset(arg) {
  if(arg) return;
  ::reset();
  set_name("mystic");
  set_alias("wizard");
  set_level(19);
  set_hp(500);
  set_ep(10000);
  set_gender(1);
  set_short("An old mystic");
  set_wc(23);
  set_ac(11);
  set_no_steal(1);
  set_al(1000);
  set_chance(35);
  set_spell_mess1("The mystic waves his arms wildy!");
  set_spell_mess2("The mystic hits you with his spell.");
  set_spell_dam(30);
  load_chat(25,({
    "The Mystic says: Looking for something?\n",
    "The Mystic says: I have not seen it.\n",
    "The Mystic says: Want to see a magic trick?\n",
    "The Mystic says: Axe's are hard to find these days.\n",
    }) );
  load_a_chat(25,({
    "The Mystic screams!\n",
    "The Mystic curses!\n",
    "The Mystic does not look happy.\n",
    "The Mystic says: You will not see the end of me yet!\n",
    }) );
  set_dead_ob(this_object());
}
monster_died() {

  tell_room(environment(this_object()), "The mystic shouts: I will return!\n"+
            "You see his shade sink through the floor.\n");
// 171197: Sauron: This should return 0 - the mystic should die...
  return 0;
}
