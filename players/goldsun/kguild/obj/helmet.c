inherit "/obj/armour";

reset(arg){
 ::reset(arg);

if (arg) return;
set_name("helmet");
set_type("helmet");
set_ac(1);
set_short("A knight helmet");
set_long("A shiny knight helmet.\n");
set_size(0);
set_value(150);
set_weight(1);
}
