inherit "/obj/armour";

reset(arg){
 ::reset(arg);

if (arg) return;
set_name("lather boots");
set_alias("boots");
set_type("boot");
set_ac(1);
set_short("A knight boots");
set_long("A lather knight boots.");
set_size(0);
set_value(100);
set_weight(1);
}
