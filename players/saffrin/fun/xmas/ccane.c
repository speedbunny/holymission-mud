inherit "obj/food";

reset(arg) {
  if(arg) return;
  set_name("candy cane");
  set_alias("candy");
  set_alt_name("cane");
  set_short("a candy cane");
  set_long("A great big red and white striped candy cane.\n");
  set_value(2);
  set_weight(1);
 set_heal_amount(2);
  set_eater_mess("CRUNCH!!!  CRUNCH!!!  CRUNCH!!!  You crunch down the candy cane.  "+
		 "Yummy!!!!!!!\n");
  set_strength(2);
}
