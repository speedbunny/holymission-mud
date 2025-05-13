
/* Booka */

inherit "obj/monster";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_name("booka");
    set_level(random(3)+3);
    set_alias("booka");
    set_alt_name("booka");
    set_al(10000);
    set_hp(this_object()->query_level()*12);
    set_sp(this_object()->query_level()*6);
    set_str(this_object()->query_level()-5);
    set_dex(this_object()->query_level()+8);
    set_wis(this_object()->query_level()+5);
    set_int(this_object()->query_level()+5);
    set_con(this_object()->query_level()-5);
    set_chr(this_object()->query_level()+3);
    set_short("booka");
    set_long("Only 1 foot tall. Has a rather large head on a thin body\n"+
             "with elvish features. Small wings might help take it to safety\n");
    set_move_at_reset();
    set_whimpy();
    load_chat(5,({
        "Booka sweeps up the area.\n", "Booka tells you: Get out of here!\n",
       "\"The cliffs are fun!\", Booka grins.\n","Booka farts rudely!\n",
      "Booka says: I HATE STRANGERS! Go away. GO!\n",
                 }));
    set_spell_mess1("Booka kicks you in the ankle");
    set_spell_mess2("Booka punches you in the privates!");
    set_chance(5);
    set_spell_dam(20);
  }
}
