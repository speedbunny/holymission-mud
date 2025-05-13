inherit "/players/padrone/obj/thing";

reset(arg){
 ::reset(arg);

 set_name("sign");
 set_short("A wooden sign.\n");
 set_can_get(0);
 set_long("This is a wooden sign. There is something written on it.\n");
       set_read("\n      +--------------------------------+\n"+ 
                "      |                            N   |\n"+         
                "      |            Village        w+e  |\n"+
		"      |              /|\\           s   |\n"+
	        "      |               |                |\n"+
		"      |    Sherwood   |                |\n"+
                "      | <-------------+                |\n"+
		"      |    Nottingham |                |\n"+
                "      |               |                |\n"+         
	        "      |               |                |\n"+
                "      |              \\|/               |\n"+
	        "      |        Land of Lakmir          |\n"+
		"      +________________________________+\n"+
                "                     |X|\n"+ 
                "                     |X|\n"+ 
                "                     |X|\n"+ 
                "                     |X|\n"+ 
                "                     |X|\n"+ 
                "                     |X|\n"+ 
                "                     |X|\n");
}

