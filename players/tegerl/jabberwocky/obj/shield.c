

/* Tegerl, 6.3.1995 */
/* monsters/shield */


inherit "obj/armour";
void reset(int arg) 
{
::reset(arg);

if (arg) return;

set_name("shield");
set_short("A shield");
set_long("This kind of shield is mainly used by guards.\n");  
set_weight(4);
set_ac(2);
set_value(1000);
set_type("shield");
}

