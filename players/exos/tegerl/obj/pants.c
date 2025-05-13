

/* Tegerl, 24.3.1995 */
/* obj/pants */


inherit "obj/thing";
void reset(int arg) 
{
::reset(arg);

if (!arg) {

set_name("pants");
set_alt_name("dirty pants");
set_short("dirty pants");
set_long("The king's pants.\n");
set_value(0);
}
}
drop() {
 write ("As you drop the pants, they crumble to dust.\n");
 destruct(this_object());
return 1;
}

give() {
 write ("As you try to give the pants away, they crumble to dust.\n");
 destruct(this_object());
return 1;
}
 
