inherit "/obj/food";

reset(arg){
 if (arg) return;
 set_name("nut");
 set_short("A hazelnut");
 set_long("A hazelnut. It seems to be very tasty.\n");
 set_eater_mess("Mnum Mnum. It tastes very well.\n");
 set_eating_mess(" eats a hazel nut.\n");
 set_weight(1);
 set_value(30);
 set_strength(10);
}
