inherit "/obj/food";

reset(arg){
 if (arg) return;
 set_name("meat");
 set_short("A piece of roast meat");
 set_long("A piece of roast meat.\n");
 set_eater_mess("Aahhhhhh. It tastes well.\n");
 set_eating_mess(" eats a piece of roast meat.\n");
 set_weight(1);
 set_value(2);
 set_strength(10);
}
