inherit "obj/monster";

reset (arg) {
::reset(arg);
 if (arg) return 1;
  set_name("Etmol");
set_level(1);
set_alignment(1000);
set_alias("Etmol", "etmol");
  set_race("elf");
  set_male();
  set_hp(630);
  set_wc(10);
  set_sp(1035);
  set_ac(10);
 set_aggressive(0);
 set_long("He is Etmol.\n He is unmarried.\nEtmol has a scar on his "+
          "left ear, his right hand, his right leg, his left hand, "+
          "his nose and his right ear.\n");
add_money(100000);
}
