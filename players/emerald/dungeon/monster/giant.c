inherit "obj/monster";

reset(arg) {
  ::reset(arg);
  if(arg) return;
    set_name("giant");
    set_race("giant");
    set_long("He towers above you, a muscle-bound killer.\n");
    set_level(35);
    set_al(-400);
    set_ac(18);
    set_wc(15);
    set_aggressive(1);
    add_money(768);
}
