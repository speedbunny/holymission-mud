inherit "/obj/monster";

object o1;
reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("blitz, kirk's cat");
  set_alias("blitz");
  set_alt_name("cat");
  set_short("Blitz, Kirk's cat");
  set_long("This is Blitz.  He is Kirk's pet.  Isn't he cute?\n");
  set_race("cat");
  set_level(8);
  set_al(1000);
  set_aggressive(0);
  set_whimpy();
o1=clone_object("players/jake/weapons/clawz");
move_object(o1,this_object()); 
init_command("wield cat claws");
  return 1;
}

query_moncreator() { return "jake"; }

query_monmaker() { return 1; }
