inherit "/obj/armour";

reset(arg) {
  ::reset();
    if (arg) return;

     set_name ("shield");
     set_alias("shield");
     set_short("iron shield");
    set_long("An iron shield, it seems to be very good.\n");
     set_type ("shield");
     set_size(3);
     set_weight(2);
     set_ac(1);
     set_value(500);


return 1;

}
