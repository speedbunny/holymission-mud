
inherit "obj/monster"; 

    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("trout");
    set_alt_name("rainbow throut");
    set_level(14); 
   set_has_gills();
    set_hp(300);
    set_al(-10); 
    set_race("fish"); 
    set_short("A big rainbow trout"); 
    set_long("You see a big trout. It looks hungry, \n"+ 
               "but it seems harmless.\n");
    set_wc(30);
    set_ac(4); 
    set_spell_mess2("The trout hurts you with its flipper !");
    set_spell_mess1("The trout makes a hit with its flipper !");
    set_chance(20); 
    set_spell_dam(random(8)); 
    move_object(clone_object("players/whisky/lake/obj/herb"),this_object());
}
}

