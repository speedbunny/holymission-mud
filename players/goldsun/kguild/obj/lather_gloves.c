inherit "/obj/armour";

reset(arg){
 ::reset(arg);

if (arg) return;
set_name("lather gloves");
set_type("glove");
set_alias("gloves");
set_ac(1);
set_short("A knight gloves");
set_long("A lather knight gloves.\n");
set_size(0);
set_value(100);
set_weight(1);
}
