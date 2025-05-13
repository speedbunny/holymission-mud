inherit "obj/npc";
reset (arg) {
  ::reset(arg);
if (arg) return;
set_name("chasme");
set_alt_name("tana-ri");
set_size(4);
set_level(20);
set_al(-150);
set_ac(12);
set_aggressive(1);
set_wc(30);
set_race("demon");
set_short("chasme");
set_long("This Tana-Ri looks like a gigantic fly with the face of a human.\n");
set_attacks(2);
set_attacks_change(100);
add_money(400+random(400));
}
