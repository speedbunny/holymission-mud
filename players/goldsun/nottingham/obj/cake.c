inherit "/obj/food";

reset(arg){
 if (arg) return;
 set_name("cake");
 set_short("A piece of cake");
 set_long("A piece of strawberry cake.\n");
 set_eater_mess("Aahhhhhh. It tastes well.\n");
 set_eating_mess(" eats a piece of strawberry cake.\n");
 set_weight(1);
 set_value(120);
 set_strength(20);
}
