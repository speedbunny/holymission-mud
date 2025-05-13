

inherit "obj/monster"; 

    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

   set_name("boa constrictor");
   set_alt_name("boa");
    set_level(18); 
    set_hp(800);
    set_al(-10); 
    set_race("snake");
   set_short("A large Boa Constrictor");
   set_long("You see a huge snake several meters in length. You can\n"+
            "imagine how horrible it would be to suffocate in its coils.\n");
    set_wc(18);
    set_ac(6); 
    set_ep(700);
    set_aggressive(1);
   set_spell_mess2("The snake wraps around you and squeezes the air from you!");
   set_spell_mess1("The snake strikes with its teeth!");
   set_chance(65);
   set_spell_dam(random(30));
}
}

