inherit "/obj/armour";

reset(arg) {
  ::reset();
    if (arg) return;

    set_name ("mail");
    set_alias("horn mail");
    set_short("A horn mail");
    set_long("A strong protection mail.\n");
    set_type("armour");
    set_ac(4);
    set_size(3);
    set_weight(2);
    set_value(900);



return 1;
}
