inherit "obj/food";

reset(arg) {
  if (arg) return;
     set_name("smurf berry");
     set_short("smurf berry");
     set_alias("berries");
     set_alt_name("berry");
     set_long("Big red smurf berries.\nThey look yummy.\n");
     set_value(4);
     set_weight(1);
     set_eater_mess("You feel rather smurfy!\n");
     set_strength(5);
}
