inherit "/obj/armour";

reset(arg){
 ::reset(arg);

if (arg) return;
set_name("red cloak");
set_type("cloak");
set_ac(2);
set_short("A knight cloak");
set_long("A knight red cloak with Carmaalot sign.\n");
set_size(0);
set_value(400);
set_weight(2);
}
