inherit "obj/food";
reset(arg) {
  if(arg) return;
set_name("peanuts");
set_short("A bag of peanuts");
set_long("A bag of peanuts left here by a fleeing peasant");
  set_value(2);
  set_weight(1);
 set_heal_amount(2);
set_eater_mess("The peanuts crunch in your mouth and taste mighty fine.\n");
  set_strength(2);
}
