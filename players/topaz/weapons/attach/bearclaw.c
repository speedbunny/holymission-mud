inherit "obj/weapon";

reset(arg) {
if (arg) return;

   set_name("bear claw");
   set_id("Bear claw");
   set_alias("bear claw");
   set_short("A Bear claw");
   set_alt_name("claw");
   set_long("This bear claw looks like it could dish out a lot of punishment!\n");
   set_value(6000);
   set_weight(8);
   set_type(3);
   set_hit_func(this_object());
}

weapon_hit(attacker) {
    write("The bear claw seems to come alive and gouges huge chunks\n" +
        "from "+attacker->query_name()+"'s body!\n");
   say(capitalize(wielded_by->query_real_name())+"'s bear claw seems to come alive and " +
        "gouges huge\nchunks out of "+attacker->query_name()+"'s body!\n");
   return 12+random(18);
}
