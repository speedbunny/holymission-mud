inherit "obj/monster";
 reset(arg) {    
  ::reset(arg);
  if (arg) return;
  
   set_name("father rabbit");
     set_alt_name("rabbit");
    set_short("An angry father rabbit");
    set_long("A big brown father rabbit\n");
    set_level(2);
    set_size(2); 
    set_aggressive(1);
    set_spell_mess1("The father rabbit hits you with its claw");
    set_spell_mess2("The father rabbit bites you in your leg");
    set_chance(40);
    set_spell_dam(2);
  }
