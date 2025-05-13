inherit "obj/npc";

reset(int arg) 
{ ::reset(arg);
  if(!arg) 
  { set_name("berzerker");
    set_alt_name("berzerker");
    set_race("berzerkian_follower");

    set_short("berzerker (follower)");
    set_long("This is a berzerkian follwer.\n");
    set_gender(1);

    set_level(15);
   set_attacks_change(50);
  set_attacks(2);

    set_al(-20);
    set_aggressive(1);
    add_money(200);

    set_spell_mess1("The berzerkian does a combat move");
    set_spell_mess2("The berzerker hits you with his but");
    set_chance(25);
    set_spell_dam(30);

  }
}
