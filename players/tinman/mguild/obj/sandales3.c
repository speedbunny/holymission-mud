inherit "obj/armour";

  reset(arg) {
   ::reset(arg);
   if (arg) return;

    set_id("sandales");
    set_alias("monks sandales");
    set_short("A pair of monks sandales");
    set_long("A brown pair of leather sandales\n");
    set_type("boot");
    set_ac(0);
    set_size(4);
    set_value(150);
    set_weight(1);
    }
    query_monk_wear() { return 1; }
