
inherit "obj/weapon";

reset(arg) {
  ::reset(arg);
  if(!arg) {

    name_of_weapon = "Bear claw";
    alt_name = "claw";
    alias_name = "bear claw";
    short_desc = "Claw of a HUGE bear"; 
    long_desc = "Claw of a HUGE bear. Its deadly sharp and nasty looking.\n";
    class_of_weapon = 20;
    type_of_weapon = 0;
    value = 5000;
    local_weight = 4;
    hit_func = this_object();
  }
}


