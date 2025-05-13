inherit "obj/monster";
object claw;

reset(arg) {
   ::reset(arg);
   if(!arg) {
   set_name("Mama Bear");
   set_alias("bear");
   set_alt_name("mama bear");
   set_aggressive(1);
   set_level(50);
   set_hp(5000);
   set_dex(55);
   set_str(55);
   set_race("animal");
   set_short("Mama Bear");
   set_long("Mama Bear doesn't look happy that you killed her cub!!\n" +
            "She might eat you for dinner!\n");
   set_spell_dam(75);
   set_chance(25);
   set_spell_mess1("Mama Bear slashes her opponent!\n");
   set_spell_mess2("Mama bear rips into your flesh with her claw!\n");
   set_no_steal();
   claw=clone_object("players/topaz/weapons/attach/bearclaw");
   move_object(claw,this_object());
   init_command("wield claw");
   }
}
