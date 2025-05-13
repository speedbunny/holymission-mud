inherit "/obj/weapon";

#define DEX 0x02

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("dagger");
    set_alt_name("sharp dagger");
    set_alias ("danseuse_dagger");
    set_class(7);
    set_weight(1);
    set_type(DEX);
    set_short("A sharp, embellished dagger");
    set_long("This dagger once belonged to the danseuse.\n");
    set_value(100);
    set_hit_func(this_object());
  } else
    if (!environment(environment(this_object()))) 
      destruct(this_object());
}
/*
weapon_hit(ob) {
  if(ob->id("danseuse")) {
    write("The dagger refuses to hit her.");
    return "miss";
  }
  if(wielded_by->id("danseuse")) return random(11);
} */
