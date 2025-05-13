inherit "/obj/monster";
object stare;

reset(arg) {
  ::reset(arg);
  if (arg) return 1;
  set_name("dracula");
  set_alt_name("count dracula");
  set_alias("count");
  set_short("Count Dracula");
  set_long("This is the master of the the Undead .. He loves new people to bring\nover... he has his eye on you... Just watch out for his stare....\n");
  set_race("vampire");
  set_level(80);
  add_money(4000);
  set_al(-1000);
  set_ac(20);
  set_aggressive(1);
  set_chance(30);
  set_spell_mess2("Count Dracula stares at you. You feel his evil aura "+
		  "draining your energy.");
  set_spell_mess1("Count Dracula stares at his opponent.");
/*
  set_dead_ob(this_object());
*/
  set_spell_dam(70);
/*
  stare=clone_object("players/warlord/weapons/stare");
  transfer(stare,this_object());
*/
  }
/*

  monster_died(ob) {
  if (!present("cross",this_player())) {
  write("You have vainly tried to kill Dracula, but you\n"+
        "forget that he is undead.......\n"+
        "Dracula regenerates and rises from the DEAD!!\n");
        move_object(clone_object("players/warlord/monsters/dracula"),
                    environment(this_object()));
        destruct(stare);
        destruct(this_object());
        return 1;
        }
        else {
             return 0; }
}
*/
