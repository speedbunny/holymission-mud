inherit "obj/npc";

reset(int arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("billy the sailor");
    set_alt_name("billy");
    set_race("human");

    set_short("Billy the sailor");
    set_long("This is Billy the sailor. He was in duty on\n"+
	     "the famous ship \"Bounty\" and managed it\n"+
	     "to return.\n");
    set_gender(1);

    set_level(35);

    set_attacks_change(100);
    set_attacks(5);    

    set_al(150);
    set_aggressive(0);
    add_money(600);

    set_spell_mess1("Billy hits someone");
    set_spell_mess2("Billy hits you in the face");
    set_chance(60);
    set_spell_dam(70);

  }
}
