inherit "obj/monster"; 

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("warg");
 set_race("wolf");
 set_long("This is a huge black wolf with blodshot eyes and mangy fur.\n");
 set_aggressive(1);
 set_level(5);
 set_wc(12);
 set_ac(4);
 set_al(-100);
}
