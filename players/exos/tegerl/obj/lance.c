

/* Tegerl, 6.3.1995 */
/* monsters/lance */


inherit "obj/weapon";
void reset(int arg) 
{
::reset(arg);

if (arg) return;

set_name("lance");
set_short("A lance");
set_long("This kind of lance is mainly used by guards.\n");  
set_weight(5);
set_class(18);
set_value(2500);

}

