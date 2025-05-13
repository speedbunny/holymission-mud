

inherit "/obj/monster";
string *a_chat_str;

void reset(int flag) 
{
  ::reset(flag);

 a_chat_str = 
 ({
    "The Drake throws a fireball at you.\n",
    "The Drake massacres you with its tail.\n",
    "The Drake burns you to ashes.\n",
    "The Drake hits you with its claw.\n"
                                               });
  if (flag == 0) 
  {
    set_name("black firedrake");
    set_no_steal();
    set_alt_name("drake");
    set_alias("firedrake");
    set_level(24);
    set_size(5);
    set_short("A huge black Firedrake");
    set_long("It stares at you with glowing eyes.\n");
    set_gender(1+random(2));
    set_ac(6);
    set_race("drake");
    set_aggressive(1);
    set_al(-800);
    set_spell_mess1("C H hhhhhhhhhhhhhh");
    set_spell_mess2("C H hhhhhhhhhhhhhh");
    set_chance(8);
    set_spell_dam(20+random(80));
    load_a_chat(40,a_chat_str);
/*
    move_object(clone_object("/players/whisky/obj/pois_potion"),this_object());
*/
   }
}
