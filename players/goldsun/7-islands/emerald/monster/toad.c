inherit "/obj/monster";

void reset(int arg)
 {
 load_chat(25,({"Toad says: Hribit. Hribit.\n"}));

 ::reset(arg);
if (arg) return;
set_name("toad");
set_race("frog");
set_short("An ugly toad");
set_long("An ugly toad.\n");
set_level(5);
set_frog(1);
set_wc(3);
set_ac(1);
set_al(-30);
set_size(1);          
}
