

inherit "obj/monster"; 

    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

  set_name("panther");
  set_alt_name("panther");
   set_level(35);
   set_hp(4500);
   set_al(-200);
    set_race("feline");
    set_short("A sleek, vicious, black panther");
  set_long("You see a dangerous black panther who looks very hungry.\n"+
           "It looks like he has decided to make you dinner!!!!\n");
   set_wc(30);
    set_ac(6); 
    set_aggressive(1);
  set_spell_mess2("The panther rips you with its claws and teeth");
    set_spell_mess1("The panther rips you with its claws and teeth");
   set_chance(65);
    set_spell_dam(random(50));
}
}

