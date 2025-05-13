
inherit "obj/monster";

void reset(int flag) 
{
   ::reset(flag);

    if (flag == 0) 
    {
       set_name("mad drake");
       set_alt_name("drake");
       set_short("A mad drake");
       set_long("A huge blue mad drake.\n");
       set_race("drake");
       set_gender(1);
       set_aggressive(1);
       set_level(50);
       set_size(5);
       set_al(-500);
       set_chance(6);
       set_spell_dam(60+random(130));
       set_spell_mess1("The drake burns you to ashes.");
       set_spell_mess2("The Drake sticks its bloody claw deep into your corpse.");
      load_a_chat(40,({"The Drake massacres you with its tail.\n"+
      "The Drake tries to tear off your leg.\n"+
      "The Drake bites you in your arm..\n",""}));
      move_object(clone_object("players/whisky/hole/obj/drakescale"),
                   this_object());
/*
      move_object(clone_object("/players/whisky/obj/sanct_potion"),
                   this_object());
*/
  }
}
