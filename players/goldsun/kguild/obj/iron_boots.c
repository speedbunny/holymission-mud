inherit "/obj/armour";

reset(arg){
 ::reset(arg);

if (arg) return;
set_name("iron boots");
set_type("boots");
set_ac(2);
set_short("A knight boots");
set_long("A shiny iron knight boots with Carmaalot sign.\n");
set_size(0);
set_value(800);
set_weight(2);
}
