inherit "/obj/armour";

   reset(arg) {
     ::reset(arg);
    if (arg) return;
    
     set_name("bear fur");
     set_alias("fur");
     set_type("cloak");
     set_ac(1);
     set_size(4);
     set_short("A brown bear fur");
     set_long("The powerful protection of the brown bear.\n");
     set_value(400);
     set_weight(1);

}
