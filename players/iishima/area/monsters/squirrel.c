inherit "obj/monster";

void reset(int arg){
::reset(arg);
if (arg) return;
set_name("squirrel");
set_race("squirrel");
set_short("A squirrel");
set_ac(0);
set_alias("squirrel");
set_long("This little squirrel looks very upset. His eyes seem to glow.\n");
set_level(2);
set_hp(60);
set_gender(1);
}
