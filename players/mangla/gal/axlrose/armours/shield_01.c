/* Axlrose - Human Army */
/* Soldier's Small Shield */
inherit "obj/armour";

reset(arg) {
    ::reset(arg);
    if (arg) return;
    set_name("circular wooden disc");
    set_alt_name("small shield");
    set_alias("disc");
    set_type("shield");
    set_ac(1);
    set_short("A leather and wooden small shield");
    set_long
    ("A two foot circular diameter hardwood shield with metal bands lacing \n"
      +"the edges while crisscrossing the center from compass points.  The back \n"
      +"has dried leather stretched across while two leather straps are sewn in \n"
      +"for forearm gripping.\n");
    set_size(3);
    set_value(100);
    set_weight(2);
}
