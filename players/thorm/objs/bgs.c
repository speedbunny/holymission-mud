inherit "obj/monster";

reset (arg) {
::reset(arg);
 if (arg) return 1;
  set_name("bgs The Whimpy");
 set_alias("bgs","whimpy");
  set_race("unknown");
  set_male();
 set_level(1000);
  set_hp(1);
  set_sp(1);
  set_wc(0);
  set_ac(0);
 set_aggressive(0);
 set_long("This stupid little fellow seems to be very weak and\n"+
          "powerless...*grin*");
           
}
