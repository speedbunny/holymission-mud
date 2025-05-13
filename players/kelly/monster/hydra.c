inherit "obj/monster";

object hat,armour;

reset(arg) {
 ::reset(arg);
 set_name("hydra");
 set_level(18);
 set_hp(400);
 set_al(-500);
 set_size(5);
 set_alias("snake");
 set_alt_name("hydra");
 set_race("snake");
 set_short("A hydra");
 set_long("The hydra is a very big seasnake race and very dangerous.\n");
 set_ac(16);
 set_wc(20);
 set_aggressive(1);
 set_spell_mess1("The Hydra hits her opponent with its spiked tail!");
 set_spell_mess2("You're hit by the hydra's spiked tail");
 set_chance(45);
 set_spell_dam(60);
 
 hat=clone_object("/players/kelly/obj/brownie_hat");
 move_object(hat,this_object());
 
 armour=clone_object("/obj/armour");
 armour->set_name("armour");
 armour->set_type("armour/arm/leg");
 armour->set_alias("scale");
 armour->set_ac(4);
 armour->set_size(5);
 armour->set_weight(6);
 armour->set_short("The hydra's scale armour");
 armour->set_long("This is a very tough armour, that could cover your body, arms and legs.\n");
 armour->set_value(5000);
 move_object(armour,this_object());
 init_command("wear armour");
 
 
}
 
