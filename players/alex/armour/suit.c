inherit "obj/armour";
 
reset(arg) {
::reset(arg);
    if(arg) return;
    set_name("A suit of heavy platemail");
    set_alt_name ("platemail");
    set_alias("suit");
    set_short ("A suit of platemail");
    set_long ("This armour looks VERY hevy it was worn by alex during\n"+
              "his fighting days and even he had to embody the suit with\n"+
              "a life of its own to make it move.\n");
    set_type ("armour");
    set_ac(12);
    set_weight(19);
    set_value(4000);
}
 
