inherit "/obj/armour";

reset(arg){
 ::reset(arg);

if (arg) return;
set_name("lather jacket");
set_alias("jacket");
set_type("armour");
set_ac(1);
set_short("A knight jacket");
set_long("A knight lather jacket.\n");
set_size(0);
set_value(700);
set_weight(1);
}
