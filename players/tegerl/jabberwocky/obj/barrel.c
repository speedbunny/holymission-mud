

/* Tegerl's first weapon, coded 6.3.1995 */
/* obj/barrel */


inherit "obj/container";
void reset(int arg) 
{
::reset(arg);

if (!arg) {

set_name("barrel");
set_weight(2);
set_max_weight(12);
set_long("This is a very beautiful barrel.\n"
       + "A master must have made it.\n");
set_value(25);
set_can_close(1);
}
}
