inherit "obj/armour";

void reset(int i){
 ::reset(i);
 if (i) return;
 set_name("shield");
 set_type("armour");
 set_short("A shield");
 set_size(2);
 set_long("A lobster shield.\n");
 set_value(30);
 set_ac(1);
 set_weight(1);
}
