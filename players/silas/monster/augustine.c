inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("augustine");
  set_alias("dwarf");
  set_short("Augustine");
  set_long("He is a very old dwarf who has been working in these mines for many years. A\nrecent accident cost him his right arm, but he still manages to walk around\nand spread the lore of the land in spite of this handicap.\n");
  set_race("dwarf");
  set_level(10);
  set_al(500);
  set_hp(300);
  set_wc(10);
  set_ac(4);
  set_aggressive(0);
  set_whimpy();
  set_move_at_reset();
  add_money(200+random(300));
  load_chat(20,({
    "Augustine says: Hello there, my fine friend!\n",
    "Augustine says: You don't look like a miner to me.\n",
    "Augustine says: I wish I had my right arm back, want to sell me yours?\n",
    "Augustine whistles a merry tune.\n",
    "Augustine moves to shake your hand and then notices that his right arm\n"+
    "is missing.\n",
  }));
  return 1;
}

