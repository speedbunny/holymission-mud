
inherit "obj/monster"; 

    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("pike");
    set_alt_name("river pike");
    set_level(18); 
   set_has_gills();
    set_hp(400);
    set_al(-1000); 
    set_race("fish"); 
    set_short("A big river-pike"); 
    set_long("You see a big dangerous looking pike\n"+ 
               "almost 6 feet long, hungrily staring at you.\n");
    set_wc(40);
    set_ac(6); 
    set_aggressive(1); 
    set_spell_mess2("The pike hurts you with its flipper !");
    set_spell_mess1("The pike makes a strong hit with its flipper !");
    set_chance(10); 
    set_spell_dam(random(20)); 
}
}

