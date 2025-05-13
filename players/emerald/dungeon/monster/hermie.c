inherit "obj/monster";


reset(arg) {
  ::reset(arg);
  if (arg) return;
    load_chat(10,({
      "Hermie dances with you, crushing your feet.\n",
      "Hermie takes your hands for a snowy polka.\n",
      "Hermie looks for someone to dance with.\n",
    }));
    set_name("hermie the dancing snow-being");
    set_alias("hermie");
    set_race("snowman");
    set_long("Hermie the dancing snow-being looks at you with a vacant\n" +
      "expression and a friendly grin.  But there must be SOME reason he's\n" +
      "locked up in the dungeon....\n");
    set_level(22);
    set_ac(23);
    set_wc(20);
    set_al(-500);
    set_aggressive(0);
    add_money(125);


}
