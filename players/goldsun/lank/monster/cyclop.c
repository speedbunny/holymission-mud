inherit "/obj/monster";

reset(arg){
  
load_a_chat(40,({"Cyclop shouts: Muhahaha !\n",
	         "Cyclop says: I'll make my dinner from you.\n"}));

 ::reset(arg);
 if (arg) return;
set_name("cyclops");
set_race("giant");
set_short("Cyclops");
set_long("A large giant with one eye.\n");
set_wc(22);
set_gender(1);
set_ac(1);
set_aggressive(1);
set_al(-200);
set_level(17);
set_size(4);
}
