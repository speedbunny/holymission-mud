inherit "/obj/weapon";

void reset(int i){
 ::reset(i);
 if (i) return;
 set_name("claws");
 set_alias("claw");
 set_short("The claws");
 set_long("Brown claws from lobster.\n");
 set_class(7);
 set_weight(2);
 set_value(120);
}
