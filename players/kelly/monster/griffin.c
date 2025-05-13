inherit "obj/monster";
 
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("griffin");
 set_level(18);
 set_race("dragon");
 set_size(5);
 set_hp(750);
 set_wc(18);
 set_ac(25);
 set_al(750);
 set_short("A griffin");
 set_long("A griffin. It's a very tough creature.\n");
 set_aggressive(0);
}
 
 
