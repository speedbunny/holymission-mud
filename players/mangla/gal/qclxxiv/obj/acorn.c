inherit "obj/food";
reset(arg) {
  if(arg) return;
  set_name("acorn");
  set_short("a crispy acorn");
  set_long("It looks crispy and tasty.\n");
  set_value(3);
  set_weight(1);
  set_eater_mess("You nibble on a crispy and tasty acorn. Mjum mjum.\n"+
				 "You feel like a squirrel.  Squirtttttt!!!!!!!!!!\n" );
  set_strength(6);
}
