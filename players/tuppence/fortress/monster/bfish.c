inherit "obj/monster";
void reset(int arg) {
::reset(arg);
if(!arg) {
set_name("barracuda");
set_aggressive(1);
set_race("fish");
set_short("Barracuda");
set_long("A big mean barracuda looks at you and snaps his jaws in your direction\n");
set_alias("barracuda");
set_level(30);
set_al(-500);
set_ac(11);
set_wc(27);
}
}
