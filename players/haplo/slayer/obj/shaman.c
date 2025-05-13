inherit "obj/monster";
object sword,staff;

reset(arg)
{
   ::reset( arg );
   
   if ( arg )
      return;
 
    set_name("shaman");
    set_alias("orc shaman");
     set_race("orc");
   set_level(10);
   set_size(3);
    set_al(-300);
   set_short("An orc shaman");
   set_long("This is the mighty Orc Shaman, leader of the forest orcs. He is \n"+
            "not only a very strong fighter but possess powerful magic. He \n"+
            "is dressed in leather skins common among orcs, but is wearing a \n"+
            "golden crown a symbol of his status.\n");
    set_wc(10);
    set_ac(1);
    set_aggressive(1);
    set_chance(20);
     set_spell_mess1("Bolts of fire shoot from the Shaman's fingers at you!");
    set_spell_mess2("The Shaman calls down lightning from the sky doing great harm to you.");
    set_spell_dam(20);

   sword=clone_object("/players/haplo/slayer/obj/slayer");
   staff=clone_object("/players/haplo/slayer/obj/staff");
   move_object(sword,this_object());
  move_object(staff,this_object());
   init_command("wield sword");
}
