/*coded by tatsuo for the samurai guild*/
inherit "/obj/armour";

 reset(arg) {
 ::reset(arg);
 if (arg) return;

    set_name("Holy Mail");
    set_alias("mail");
    set_type("armour");
    set_size(3);
    set_short("Holy Mail");
    set_long("This is the holy priest mail made by hachiman for his high priest\n"+
             "It is made of gold and magically enhanced to protect the wearer from\n"+
             "harm.\n");
     set_ac(2);
     set_weight(2);
     set_value(1200);

 }
