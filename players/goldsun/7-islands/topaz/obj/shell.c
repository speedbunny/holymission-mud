inherit "obj/armour";

void reset(int i){
 ::reset(i);
if (i) return;
set_name("shell");
set_type("armour");
set_short("A turtle shell");
set_long("A gray turtle shell.\n");
set_size(3);
set_ac(4);
set_weight(3);
set_value(1700);
}
