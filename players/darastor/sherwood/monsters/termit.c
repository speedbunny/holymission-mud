inherit "/obj/monster";
void reset(int arg)
 {
 ::reset(arg);
 if (arg) return;
set_name("termite");
set_race("ant");
set_short("An evil red termite");
set_long("An evil red termite. It seems very dangerous.\n");
set_wc(5);
set_ac(1);
set_hp(100);
set_al(-100);
set_aggressive(1);
set_level(1);
set_size(1);          
}
