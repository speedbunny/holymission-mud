inherit "obj/monster";
void reset(int arg) {
::reset(arg);
if(!arg) {
set_name("yellow snake");
set_race("snake");
set_short("Yellow snake");
set_long("A plain yellow snake.\n");
set_alias("snake");
set_level(20);
set_al(400);
set_ac(10);
set_wc(20);
}
}
