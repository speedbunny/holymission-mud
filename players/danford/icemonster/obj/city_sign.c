

inherit "obj/treasure" ;

reset(arg) {
	if(!arg)  {
		set_id("sign");
		set_short("A sign");
		set_long("A sign. There's something written on it.\n");
		set_read("      Welcome to Surf City!\n"+
		         "Surf City is one of the nicest places you've ever seen!\n"+
		         "You will surely like it! Visit our nice Pizzeria or have\n"+
		         "some Ice-Cream but be sure you are smiling because due to\n"+
		         "an accident in the fabrics of time a few years ago time began\n"+
		         "to stand still on a nice Saturday afternoon\n"+
		         "----------------------------------------------------------------\n"+
		         "Be kind to all citizens and watch out for the Ice-Caves!\n");
		         
		set_weight(50);
		set_value(2);
	}
}

                  
