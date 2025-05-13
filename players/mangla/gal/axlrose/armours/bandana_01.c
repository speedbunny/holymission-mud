/* Axlrose's Personal Bandana */
inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("bandana");
    set_type("helmet");
    set_ac(1);
    set_short("A Black Bandana");
    set_long("A black, sweaty bandana from a hard-ass rockin' concert.\n");
    set_size(3);
    set_value(125);
    set_weight(1);
}
