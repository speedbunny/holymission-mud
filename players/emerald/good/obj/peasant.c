inherit "/obj/monster";

reset(arg) {
  if(arg) return 1;
  ::reset();
  set_name("peasant");
  set_alias("villager");
  set_race("peasant");
  set_level(9);
  set_al(400);
  set_short("A peasant");
  set_ac(4);
  set_wc(8);
  set_long("A talkative villager of the mountain village.\n");
  load_chat(10,({
    "The peasant says: Where is the King?\n",
    "The peasant says: Find the King!\n",
    "The peasant says: Look everywhere for him!\n",
    "The peasant says: Check the trees!\n",
    "The peasant says: He is too fat and lazy.\n",
    "The peasant says: The mystic is a wise man.\n",
    "The peasant says: Buy a shot, they are good!\n",
  }));
}
