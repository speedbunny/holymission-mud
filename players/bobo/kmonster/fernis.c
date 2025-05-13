inherit "obj/monster";
 
object ring,spear,hide;
status arg;
 
reset(arg) {
 ::reset(arg);
 if(arg) return;
 set_name("fernis");
 set_level(20);
 set_male();
 set_al(-500);
 set_size(4);
 set_hp(5000);
 set_al(0);
 set_race("wolf");
 set_short("Fernis");
 set_long("The Fernis is a huge wolf. He has to glowings eyes and \n"+
          "long sharp teeth.\n");
 set_ac(18);
 set_wc(20);
 set_aggressive(1);
 set_spell_mess1("The fernis bites you terribly !");
 set_spell_mess2("You're severly wounded by the fernis teeth.");
 set_chance(25);
 set_spell_dam(50);
 
 hide=clone_object("/obj/armour");
 hide->set_name("hide");
 hide->set_alias("wolfshide");
 hide->set_short("A wolf's hide");
 hide->set_long("This is the fernis' hide. It's very tough.\n");
 hide->set_ac(3);
 hide->set_size(4);
 hide->set_type("armour/arm");
 hide->set_weight(2);
 hide->set_value(1520);
 move_object(hide,this_object());
 init_command("wear hide");
 
 ring=clone_object("/players/kelly/obj/draupnir");
 move_object(ring,this_object());
 
 spear=clone_object("/players/kelly/obj/gungnir");
 move_object(spear,this_object());
}
 

 
