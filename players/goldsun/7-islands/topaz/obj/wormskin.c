inherit "obj/armour";

void reset(int i){
 ::reset(i);
if (i) return;
set_name("wormskin");
set_type("armour");
set_short("A worm skin");
set_long("A yellow worm skin.\n");
set_size(4);
set_ac(4);
set_weight(3);
set_value(1750);
}
