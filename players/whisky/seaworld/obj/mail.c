inherit "/obj/armour";


reset(arg) {
  ::reset();
    if (arg) return;

    set_name("mail");
    set_alias("platinum mail");
    set_short("A platimum mail");
    set_long("A strong protection mail against enemies.\n");
    set_type("armour");
    set_ac(4);
    set_size(3);
    set_weight(2);
    set_value(1000);

return 1;
}
