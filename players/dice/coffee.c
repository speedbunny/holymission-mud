inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("coffee monster");
  set_alias("monster");
  set_short("Coffee monster");
set_long("A small little cup of coffee with 2 legs and 2 arms.\n");
   set_level(40);
   set_race ("coffeejar");
  set_al(10000);
  set_hp(1);
  set_ep(0);
  set_wc(30);
  set_ac(5);
  set_aggressive(0);
   load_chat(10,({"Coffee monster says: Dice is idle.\n",
                 "Coffee monster says: Dice is getting his coffee.\n",}));
  add_money(0);
  return 1;
}


