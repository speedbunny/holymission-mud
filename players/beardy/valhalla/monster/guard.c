inherit "obj/npc";

#define TO this_player()

reset(int arg) 
{ ::reset(arg);
  if(arg) return 0;

  set_name("guard");
  set_alt_name("guard");
  set_race("human");

  set_short("a guard");
  set_long("This is one of Valhalla's castle guards. Leave them alone\n"+
	   "and you will have no problems at all.\n");
  set_gender(1);

  set_level(15);
  set_attacks_change(50);
  set_attacks(3);    

  heart_beat(1);

  set_al(0);
  set_aggressive(0);
  add_money(200);

  set_spell_mess1("Huratsch ! The guard makes a combat move.");
  set_spell_mess2("Huratsch ! The guard damaged your armour.");
  set_chance(25);
  set_spell_dam(40);

}

void heart_beat()
{ 
  if(!(this_object()->query_attack()))
    switch(random(10))
    { case 1 : command("west",TO);break;
      case 2 : command("north",TO);break;
      case 3 : command("east",TO); break;
      case 4 : command("south",TO); break;
    }
}
