

/* Tegerl, 28.3.1995 */
/* obj/oldlanc */


inherit "obj/weapon";
void reset(int arg) 
{
::reset(arg);

if (arg) return;

set_name("lance");
set_alias("ABadLance");
set_short("An old lance");
set_long("This lance is really a bad weapon.\n");  
set_weight(6);
set_class(1);
set_value(10);

}

