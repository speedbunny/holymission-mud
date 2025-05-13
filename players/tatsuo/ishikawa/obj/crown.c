/*coded for ishikawa by gandalf*/
inherit "obj/armour";

reset (arg) {
    ::reset(arg);
    if (arg) return;

    set_name("Crown of Ishikawa");
    set_alias("crown");
    set_type("armour");
    set_size ("any");
    set_short("The crown of Ishikawa");
    set_long("The crown of Ishikawa. It is a magical crown that is used by the elder\n"+
             "to help his people prosper and live in peace.\n");
      "the scales of the Serpent King. It appears\n"+
    set_weight(1);
    set_ac(1);
    set_light(1);
    set_value(6000);
}
