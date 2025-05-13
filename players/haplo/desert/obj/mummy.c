
inherit "obj/monster";


reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_name("mummy");
    set_level(30);
    set_al(-250);
    set_alias("mummy");
    set_short("mummy");
set_long("This long dead Pharoah whose tomb you have deserted with your\n"+
"presence. Leave now lest he decide to kill you and forever entomb your soul\n"+
"enslaved for eternity to him.\n");
     set_wc(12);
    set_ac(25);
set_aggressive(0);
    load_chat(8,({
                  "The Mummy growls in rage.\n",
                  "The Mummy seeks your life force.\n",
                 }));
    set_dead_ob(this_object());
    set_spell_mess1("The Mummy hurls a curse at you!");
    set_spell_mess2("The Mummy sucks you life force from  you");
    set_chance(20);
    set_spell_dam(20);
  }
}

