inherit "obj/weapon";

void reset (int arg) {
  ::reset(arg);
     set_alt_name("limb");
     set_alias("branch");
     set_name("branch");
     set_hit_func(this_object());
     set_weight(4);
     set_value(1000);
     set_class(19);
     set_type(3);
     set_short("branch");
     set_long("A thorny branch that seems to be crossbred with nightshade.\n");
}

weapon_hit() {

   if (!random(4)) {
     write("Sap from the branch runs into the "+wielded_by->query_attack()->query_name()+"'s wounds.\n");
     wielded_by->query_attack()->add_poison(10);
   }
   return 1;
}

