inherit "obj/armour";

void reset(int i){
 ::reset(i);
if (i) return;
set_name("tigerfur");
set_alias("fur");
set_type("armour");
set_short("A tigerfur");
set_long("A nice fur of medium tiger.\n");
set_size(3);
set_ac(3);
set_weight(3);
set_value(1600);
}
