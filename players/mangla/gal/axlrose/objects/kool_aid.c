/* Nae's Tropical Punch Kool-Aid */
inherit "obj/soft_drink";

reset(arg) {
    ::reset(arg);
    if(arg) return;
    set_name("tropical punch kool-aid");
    set_alt_name("bottle");
    set_alias("kool-aid");
    set_short("Tropical Punch Kool-Aid");
    set_long("A dark, pinkish-red sugary liquid consumed in large amounts.\n");
    set_drinker_mess
      ("The cool, sticky sweet, wet taste of Tropical Punch Kool-Aid sure has \n"
      +"taken care of that never ending thirst!\n");
    set_drinking_mess(" tips " + (this_player()->query_possessive()) + " head back and drinks deeply from the bottle \n"
      +"of Tropical Punch Kool-Aid...the thirst is completely quenched.\n");
    set_value(50);
    set_weight(1);
    strength=10;
}

