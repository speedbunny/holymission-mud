inherit "obj/npc";
reset (arg) {
  ::reset(arg);
if (arg) return;
set_name("babau");
set_alt_name("tana-ri");
set_size(4);
set_level(20);
set_al(-150);
set_ac(10);
set_aggressive(1);
set_wc(20);
set_race("demon");
set_short("babau");
set_long("This Tana-Ri looks almost like a living skeleton.\n");
set_attacks(1);
set_attacks_change(100);
add_money(200+random(200));
}
