inherit "obj/monster";
 
reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("treant");
 set_race("tree");
 set_long("This is a huge tree which somehow resembles a man.\n");
 set_level(18);
 set_hp(1500);
 set_ac(12);
 set_wc(25);
 set_al(300);
}
