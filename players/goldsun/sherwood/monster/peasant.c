inherit "/obj/monster";
void reset(int arg)
 {
 ::reset(arg);
 if (arg) return;
set_name("pheasant");
set_race("animal");
set_short("A forest pheasant");
set_long("A forest pheasant.\n");
set_wc(6);
set_ac(3);
set_al(100);
set_aggressive(0);
set_level(10);
set_size(3);
}
