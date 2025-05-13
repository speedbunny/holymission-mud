inherit "obj/thing";
#include "/players/trout/defs.h"
	
reset(tick){
	::reset(tick);
	if(tick) return;
	set_name("painting");
	set_can_get(1);
	set_weight(2);
	switch(RAN(5)){
		case 0: set_long("This is a lovely painting of an aquatic "+
			"scene. It's a trout original! \n");
			set_value(700);
			break;
		case 1: set_long("This is a rather dark, evil painting of "+
			"the Yama Kings of Hell. It's an Akira original! "+
			"There is some writing on the painting! \n");
			set_read("Visit the Yama Kings of Hell at vulture."+
			"king.ac.uk port=2020 \n");
			set_value(1100);
			break;
		case 2: set_long("This is a painting of a nature "+
			"scene. A lone man stands in the woods, playing "+
			"a lute. He looks like a bard. This painting is "+
			"an Exos original! \n");
			set_value(2000);
			 break;
		case 3: set_long("This painting is a incredible scene of "+
			"Daimyo Tokugawa locked in combat with the dreaded "+
			"Ryo! \n");
			 set_value(1400);
			  break;
		case 4: set_long("This painting depicts the famous battle of "+
			" Nagashino, where Oda Nobunga and Tokugawa Ieyasu "+
			"combined forces to defeat Takeda Shingen. \n");
			set_value(1850);
			break;
	}
	}
