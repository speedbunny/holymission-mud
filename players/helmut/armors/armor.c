inherit "obj/armour";

reset(arg)
{ ::reset(arg);
    if(!arg)
    { set_name("armour");

	set_short("Armour of the First-Born");
	set_long("This remarkably light armour is dazzling to the eye.\n"+
	  "colours shifts and changes with the light.  You get\n"+
	  "the feeling that this seemingly flimsy armour is\n"+
	  "impenetrable.\n");

	set_type("armour");
	set_ac(5);
	set_value(50000);
	set_weight(2);
    }
}
query_mage_wear() {  return 1;  }
