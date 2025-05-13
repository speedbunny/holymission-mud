inherit "obj/monster";

reset(){
::reset();
set_name("green dragon");
set_race("dragon");
set_short("Green dragon");
set_ac(4);
set_wc(5);
set_alias("dragon");
set_long("This dragon has long, sharp teeth and huge evil eyes.\n");
set_level(13);
set_chance(15);
set_spell_mess1("The green dragon breaths fould smelling gas at $N");
set_spell_mess2("The green dragon exhales a cloud of foul gas, causing you to choke");
set_spell_dam(25);
set_hp(170);
set_gender(1);
}
