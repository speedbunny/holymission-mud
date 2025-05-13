inherit "/players/padrone/obj/thing";

reset(arg){
 ::reset(arg);

 set_name("sign");
 set_short("A wooden sign.\n");
 set_can_get(0);
 set_long("This is a wooden sign. There is something written on it.\n");
       set_read("\n      +--------------------------------+\n"+ 
                "      |                                |\n"+         
                "      |        ~ W E L C O M E ~       |\n"+
		"      |                                |\n"+
	        "      |   THIS IS A WORLD WHERE CLOUD  |\n"+
		"      |  PEOPLE RULE.  THEY DON'T MIND |\n"+
                "      |    YOUR PRESENCE AS LONG AS    |\n"+
		"      |  YOU AREN'T CAUSING PROBLEMS.  |\n"+
                "      |                                |\n"+         
	        "      |     To the WEST is a forest.   |\n"+
                "      |                        _______/\n"+
	        "      |     To the EAST is a _/\n"+
		"      +_____________________/\n"+
                "                     |#|\n"+ 
                "                     |#|\n"+ 
                "                     |#|\n"+ 
                "                     |#|\n"+ 
                "                     |#|\n"+ 
                "                     |#|\n"+ 
                "                     |#|\n");
}

