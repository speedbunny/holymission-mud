inherit "obj/monster";
void reset(int arg) {
::reset(arg);
if(!arg) {
set_name("long worm");
set_race("bug");
set_short("Long worm");
set_long("This long worm is crawling around in the mud.\n");
set_alias("worm");
set_level(17);
set_al(400);
set_ac(8);
set_wc(18);
}
}
