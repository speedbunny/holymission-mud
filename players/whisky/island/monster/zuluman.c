inherit "/obj/monster";
object o1,o2;
string a_chat_str;

reset(arg) {
  ::reset(arg);
 a_chat_str = ({
  "The Zuluman shouts: I kill you!\n",
  "The Zuluman shouts: I'll eat you !!!.\n",
  "The Zuluman smashes his zapper against you !!!.\n",
  "The Zuluman speaks some magic words.\n",
  "The Zuluman prepares for his mighty ZAPSPELL\n",
  "The Zuluman summons a flash from the sky\n"+
  "and hurts himself badly.\n",
  "The Zuluman turn his shrink against you !!!!!!!!!!.\n",
  "The Zuluman shouts: blood and frogs come over these world.\n",
  "The Zuluman shouts: I heat the oven.\n",
  "The Zuluman tries to run away but fails.\n",
  "The Zuluman tries to desintegrate you.\n",
  "The Zuluman shouts: Beware I eat also wizards.\n", 
  "The Zuluman shouts: I cook you !!!.\n" 
                                               });
 if (arg) return 1;

   set_name("zuluman");
   set_level(40);
   set_ac(14);
   set_hp(4000);
   set_size(4);
   set_short("The Zuluman");
   set_long("He looks like he wanna eat you.\n");
   set_gender(1);
   set_race("human");
   set_aggressive(1);
   set_al(-100);
   load_a_chat(40,a_chat_str);
   set_chance(20);
   set_spell_dam(20+random(80));
   set_spell_mess1("The Zuluman casts a mighty fireball");
   set_spell_mess2("The Zuluman casts a mighty fireball at you");
   o1=clone_object("players/whisky/island/obj/woodozapper");
   move_object(o1,this_object());
   init_command("wield zapper");
   o2=clone_object("players/whisky/island/obj/voodojacket");
   move_object(o2,this_object());
return 1;
  }
attack()
{
  if (::attack() && (!random(8)))
      attack();
}

hold(caller,time)
{
  if (time > 8)
     return ::hold(caller,random(8));
     return ::hold(caller,random(time));
}
