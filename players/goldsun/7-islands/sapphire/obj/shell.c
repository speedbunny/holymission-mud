inherit "obj/armour";

void reset(int i){
 ::reset(i);
if (i) return;
set_name("shell");
set_type("armour");
set_short("A turtle shell");
set_long("A green turtle shell.\n");
set_size(3);
set_ac(3);
set_weight(2);
set_value(450);
}
