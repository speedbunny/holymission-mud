inherit "/obj/armour";
#define ENV environment
#define TP this_player()
#define QNAME query_name()
 
reset(arg) {
  ::reset(arg);
  if(!arg) {
      set_name("T-shirt");
      set_id("T-shirt");
      set_alias("shirt");
      set_ac(0);
      set_short("An OFFICIAL Coed Naked NetSurfing T-Shirt");
      set_long("	 ------______------    \n"+
 	       "        |   	       	   |    \n"+
	       "        |__  COED NAKED  __|    \n"+
               "	  |  NETSURFING  |      \n"+
               "          |              |      \n"+ 
	       "	  |              |      \n"+
               "	  |   Stay  On   |      \n"+
               "	  |  For  Hours  |      \n"+
  	       "	  |______________|	\n");
      set_value(0);
      set_weight(0);
  }
}

