inherit "obj/food";

reset(arg){
  if (!arg) {
   set_name("flour");
   set_alias("some flour");
   set_short("some flour");
   set_long("some delicious wheat flour.\n");
   set_eater_mess("You eat some delicious wheat flour.\n");
   set_eating_mess(" eats some flour.\n");
   set_strength(1);
   set_value(2);
   set_weight(1);
  }
 }
