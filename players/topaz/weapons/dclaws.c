inherit "obj/weapon";

reset(arg) {
if (arg) return;

   set_name("dragon claws");
   set_id("dragons claws");
   set_alias("claw");
   set_alt_name("claws");
   set_short("Razor sharp dragon's claws");
   set_long("These dragon's claws are VERY sharp!\n");
   set_value(8000);
   set_weight(9);
/*  set_two_handed(); */
   set_hit_func(this_object());
}

weapon_hit(attacker) {
    write("You get in two hits with the remarkable dragon claws!\n");
   say(capitalize(wielded_by->query_real_name())+" gets in two hits with the" +
       "remarkable dragon claws!\n");
   return 14+random(6);
}

magic_hit2(attacker) {
    return 12+random(8);
}
