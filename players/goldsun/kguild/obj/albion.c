inherit "/obj/weapon";

reset(arg){
 ::reset();
if (arg) return;
set_name("albion");
set_alias("sword");
set_short("Albion");
set_long("The ancient Albion. A one of seven mystical swords.\n");
set_weight(4);
set_value(2000);
set_class(20);
}
