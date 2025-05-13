/*coded for ishikawa by gandalf*/
inherit "obj/armour";

reset (arg) {
    ::reset(arg);
    if (arg) return;

    set_name("Serpent Mail");
    set_alias("mail");
    set_type("armour");
    set_size ("any");
    set_short("The Serpentmail");
    set_long("The mighty armour of the Serpent King.\n"+
      "It looks like an armour made from\n"+
      "the scales of the Serpent King. It appears\n"+
      "to be very good armour, wearable by all.\n");
    set_weight(2);
    set_ac(4);
    set_light(1);
    set_value(2000);
}
