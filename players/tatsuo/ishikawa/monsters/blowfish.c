

inherit "obj/monster"; 

    
  reset(arg) {
    ::reset(arg);
  if (!arg) {

  set_name("baboon");
    set_alt_name("baboon");
    set_level(10);
    set_hp(500);
    set_al(20);
    set_race("monkey");
   set_short("A ugly Baboon");
   set_long("You see a short squat baboon. He is grazing with his mates\n"+
            "at the base of a tree. You can see its razor sharp teeth\n"+
            "when it yawns.\n");
    set_wc(18);
    set_ac(6); 
   set_aggressive(0);
  set_spell_mess2("The baboon sinks it's teeth into you!!!");
  set_spell_mess1("The baboon sinks it's teeth into you!!!");
  set_chance(50);
  set_spell_dam(random(25));
}
}

