

/* Tegerl, 24.3.1995 */
/* monsters/ring */


inherit "obj/armour";
void reset(int arg) 
{
::reset(arg);

if (arg) return;

set_name("ring");
set_alias("AnUglyLookingRing");
set_short("The king's ring");
set_long("The king's ring, it once was very beautiful.\n");  
set_weight(1);
set_ac(0);
set_value(0);
set_type("ring");
}
drop() {
 write ("As you drop the ring it snaps out of existance.\n");
 destruct(this_object());
return 1;
}

give() {
 write ("As you try to give the ring away it snaps out of existance.\n");
 destruct(this_object());
return 1;
}

