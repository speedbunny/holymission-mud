

/* Tegerl, 28.3.1995 */
/* monsters/oldarm */


inherit "obj/armour";
void reset(int arg) 
{
::reset(arg);

if (arg) return;

set_name("armour");
set_alias("AWornDownArmour");
set_short("An old armour");
set_long("An old ugly armour.\n");  
set_weight(6);
set_ac(1);
set_value(10);
set_type("armour");
}

drop() {
 write ("As you drop the armour, it falls into pieces.\n");
 destruct(this_object());
return 1;

}

give() {
 write ("As you try to give the armour away, it falls into pieces.\n");
 destruct(this_object());
return 1;
}

