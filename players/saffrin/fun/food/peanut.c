inherit "obj/food";

reset(arg) {
  if(arg) return;
  set_name("peanut");
  set_alias("nut");
  set_alt_name("pea");
  set_short("peanut");
  set_long("A yummy peanut.\n");
  set_value(2);
  set_weight(1);
 set_heal_amount(2);
  set_eater_mess("CRUNCH!!!  CRUNCH!!!  CRUNCH!!!  You crunch down the peanut.  "+
      	 "Yummy!!!!!!!\n");
  set_strength(2);
}
