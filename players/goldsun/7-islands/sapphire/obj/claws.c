inherit "obj/weapon";

void reset(int i){
 ::reset(i);

 if (i) return;
 set_name("claws");
 set_alias("claw");
 set_short("Crayfish claws");
 set_long("Red strong crayfish claws.\n");
 set_class(9);
 set_value(450);
 set_weight(2);
}
