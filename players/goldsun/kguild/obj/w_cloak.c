inherit "/obj/armour";

reset(arg){
 ::reset(arg);

if (arg) return;
set_name("white cloak");
set_type("cloak");
set_ac(1);
set_short("A knight cloak");
set_long("A knight white cloak with Carmaalot sign.\n");
set_size(0);
set_value(200);
set_weight(1);
}
