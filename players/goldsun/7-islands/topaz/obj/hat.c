inherit "obj/armour";

void reset(int i){
 ::reset(i);
if (i) return;
set_name("grassy hat");
set_alias("hat");
set_type("helmet");
set_short("A grassy hat");
set_long("A grassy hat.\n");
set_size(3);
set_ac(1);
set_weight(1);
set_value(50);
}
