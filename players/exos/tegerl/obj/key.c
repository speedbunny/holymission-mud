

/* Tegerl, 24.3.1995 */
/* monsters/key */


inherit "obj/thing";
void reset(int arg) 
{
::reset(arg);

if (arg) return;

set_name("key");
set_alias("jajaja");
set_short("large iron key");
set_long("A large iron key.\n");  
set_weight(1);
set_value(10);
}
drop() {
 write ("As you drop the key it snaps out of existance.\n");
 destruct(this_object());
return 1;
}

give() {
 write ("As you try to give the key it snaps out of existance.\n");
 destruct(this_object());
return 1;
}

