inherit "obj/monster";
reset (arg) {
  ::reset(arg);
if (arg) return;
set_name("manes demon");
set_alt_name("tana-ri");
set_size(1);
set_level(10);
set_al(-150);
set_ac(7);
set_aggressive(1);
set_wc(15);
set_race("demon");
set_short("manes demon");
set_long("This disgusting creature almost makes you puke.\n");
add_money(100+random(100));
}
