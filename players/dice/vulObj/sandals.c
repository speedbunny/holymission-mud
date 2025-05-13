inherit "/obj/armour";

reset(arg) {
    ::reset(arg);
    if (arg) return 1;
    set_name("sandals");
    set_type("sandals");
    set_short("Old sandals");
    set_long("These are old brown worn out sandals.\n"+
      "They once belonged to an old monk who travelled a long way with them.\n");
set_value(10);
set_size(3);
set_weight(1);
return 1;
}

