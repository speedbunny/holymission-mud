

/* Tegerl, 9.3.1995 */
/* obj/corpse */


inherit "obj/treasure";
void reset(int arg) 
{
::reset(arg);

if (!arg) {

set_name("corpse");
set_alt_name("skleleton");
set_weight(20);
set_short("A very ugly corpse");
set_long("This is a very ugly corpse.\n"
       + "It isn't dead that long, because.\n"
       + "you can still realize a face, but.\n"
       + "there is no meat on the bones anymore.\n"
       + "A horrible monster must have done this.\n"
       + "Was it Jabberwocky ???\n");
set_value(0);
}
}
