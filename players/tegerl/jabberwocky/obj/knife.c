

/* Tegerl's first weapon, coded 6.3.1995 */
/* monsters/knife */


inherit "obj/weapon";
void reset(int arg) 
{
::reset(arg);

if (arg) return;

set_name("knife");
set_short("A short tiny knife");
set_long("This tiny sword can be hidden very easy.\n"
       + "It is the best weapon for a merchand.\n");  
set_weight(1);
set_class(6);
set_value(20);

}

