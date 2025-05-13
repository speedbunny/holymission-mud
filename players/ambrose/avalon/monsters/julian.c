inherit "obj/monster";

object sword,armor;

reset (arg){
 ::reset(arg);
 if(!arg){
set_name("Julian");
set_level(40);
set_gender(1);
set_race("human");
set_alias("julian");
set_al(60);
set_short("Julian the Huntsman");
set_long("This is Julian, he has long black hair, bright blue eyes and is\n"+
         "wearing a scaled white armor.  He is guarding the Unicorn.\n");
set_hp(12000);
set_wc(50);
set_ac(30);
set_aggressive(1);
set_spell_mess1("Julian shoves his sword through you and smiles.\n");
set_spell_mess2("Julian slices you across the front causing you agony.\n");
set_chance(50);
set_spell_dam(120);
sword=clone_object("players/ambrose/avalon/weapons/jsword");
armor=clone_object("players/ambrose/avalon/armour/jscale");
move_object(sword,this_object());
move_object(armor,this_object());
init_command("powerup");
 }
}
