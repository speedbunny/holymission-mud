inherit "obj/monster";
void reset(int arg){
::reset(arg);
if (arg) return;
 set_name("wolf");
 set_short("A wolf");
 set_race("wolf");
 set_alias("wolf");
 set_gender(2);
 set_long("She looks like she wouldn't want to be bothered.\n");
 set_level(3);
 set_hp(75);
}
