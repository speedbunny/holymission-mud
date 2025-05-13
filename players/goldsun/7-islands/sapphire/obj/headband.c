inherit "obj/armour";

void reset(int i){
 ::reset(i);
 if (i) return;
 set_name("headband");
 set_short("A beaver headband");
 set_long("Brown headband made of beaver fur.\n");
 set_size(2);
 set_type("helmet");
 set_ac(1);
 set_value(100);
 set_weight(1);
} 
