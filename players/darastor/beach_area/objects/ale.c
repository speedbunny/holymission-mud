inherit "/obj/alco_drink";

void reset(int arg) {
    ::reset(arg);
    set_name("ale");
    set_alias("beer");
    set_empty_container("bottle");
    set_drinker_mess("Mmmm...tastes good.\n");
    set_drinking_mess(" drinks a beer.\n");
    set_strength(5);
    set_value(5);
    set_short("A bottle of ale");
    set_long("An old-looking bottle of ale.\n");
}
