
inherit "/obj/monster";

string *a_chat_str;

void reset(int flag) 
{
  ::reset(flag);

    a_chat_str = 
   ({
    "The Drake throws a fireball at you.\n",
    "The Drake spits pure whisky into your face.\n",
    "The Drake tries to go through the field, but fails.\n",
    "The Drake hits you with its claw.\n"
                                               });
 if (flag == 0) 
 {
    set_name("drunken drake");
    set_alt_name("drake");
    set_alias("drunken drake"),
    set_level(35);
    set_size(5);
    set_short("A drunken Drake");
    set_long("It stares at you with glowing eyes.\n");
    set_gender(2);
    set_race("drake");
    set_aggressive(1);
    set_al(-800);
    set_spell_mess1("H I C K !");
    set_spell_mess1("The drake spits pure alcohol at you.");
    set_chance(8);
    set_spell_dam(40+random(120));
    move_object(clone_object("/players/whisky/obj/sanct_potion"),this_object());
    move_object(clone_object("/players/whisky/hole/obj/tail"),this_object());
    load_a_chat(40,a_chat_str);
   }
 }
