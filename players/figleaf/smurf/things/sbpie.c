inherit "obj/food";

void reset(int arg) {

  ::reset(arg);
  if(arg) return;
  set_name("smurfberry pie");
  set_alias("pie");
  set_short("A smurfberry pie");
  set_long("A delicious looking smurfberry pie covered in whipped cream.\n");
  set_value(15);
  set_weight(1);
  set_strength(4);
  set_heal_amount(4);
  set_eater_mess("Mmmm, sweet and creamy. Delicious!\n");
  set_eating_mess(" snarfs down a whole smurfberry pie!\n");
}

