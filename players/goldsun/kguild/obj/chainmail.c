inherit "/obj/armour";

reset(arg){
 ::reset(arg);

if (arg) return;
set_name("bronze chainmail");
set_alias("mail");
set_type("armour");
set_ac(2);
set_short("A knight chainmail");
set_long("A knight bronze chainmail.\n");
set_size(0);
set_value(1300);
set_weight(2);
}
