inherit "obj/monster"; 

reset(arg) {
  ::reset(arg);
  if(arg) return;
 set_name("frost giant guard");
 set_alias("guard");
 set_short("A Frost Giant Guard");
 set_race("giant");
 set_long("This is a large clean shaven Frost Giant. He is about 10 feet tall and\n"+
"must weigh at least 350 pounds. He is glaring at you.\n");
 set_level(14);
 set_ac(6);
 set_hp(350);
 set_wc(25);
 set_al(-450);
}
