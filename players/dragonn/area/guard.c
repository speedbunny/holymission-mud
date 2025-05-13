inherit "/obj/monster";

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("guard");
  set_alias("guard");
  set_short("Guard of country Pavi");
  set_long("You see a large guard who is guarding the country known \n"+
           "as Pavi. Better don't attack him or he will just rip your \n"+
           "head like a apple.\n");
  set_race("elf");
  set_level(22);
  set_al(50);
  set_hp(680);
  add_money(1000+random(500));
  set_wc(15);
  set_ac(15);
  set_aggressive(1);
  return 1;
}


