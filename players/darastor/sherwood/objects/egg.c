inherit "/obj/food";

reset(arg){
 if (arg) return;
 set_name("egg");
 set_short("A bird egg");
 set_long("A bird egg. It seems to be very tasty.\n");
 set_eater_mess("Mnum Mnum. It tastes well.\n");
 set_eating_mess(" eats an egg.\n");
 set_weight(1);
 set_value(30);
 set_strength(10);
}
