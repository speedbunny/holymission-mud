inherit "obj/weapon";

void reset(int i)
{
 ::reset(i);
 if (i) return;
 set_name("hell hammer");
 set_alias("hammer");
 set_short("A hell hammer");
 set_long("A hell hammer. It looks sharp and dangerous.\n"+
	  "There is a Cermor's sign on it.\n");
 set_weight(5);
 set_class(19);
 set_value(7000);
}  
