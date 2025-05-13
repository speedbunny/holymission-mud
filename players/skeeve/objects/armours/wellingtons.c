inherit "/obj/armour";

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("wellingtons");
    set_alias("high boots");
    set_type("boot/leg");
    set_value(140);
    set_ac(1); /* Airborne: leg invalid armour type for ac */
    set_weight(4);
    set_size(0);
    set_short("A pair of wellingtons");
    set_long("It's nothing special at this hood.\n");
  } else if ( !environment(environment(this_object()))) 
    destruct(this_object());
}

config(tp) {
  if (tp->query_npc())
    set_size(tp->query_size());  
  return this_object();
}
