inherit "room/room";
object ob;
#include "/players/helmut/defs.h"

#if 0
if(!(present("bartender")) || !living(ob)) {
#endif
void reset( int arg )
{
    object ob;

    if ( !(ob=present("bartender",this_object()))
	|| !living(ob)) {
	  //    if(!(ob=present("bartender")) || !living(ob)) {
	  move_object(clone_object("players/helmut/monsters/bartender"),
	    this_object());
      }
      if (arg) return;
      set_light(1);
      short_desc= "The Raptor Pit";
      long_desc=
      "This is the famous Raptor Pit. The interior of this well-kept\n"+
      "pub is lit to a comfortable degree, and the patrons seem a gruff, but\n"+
      "friendly lot. When you look at the bar, however, you do a monstrous\n"+
      "double-take, JUST to make sure you weren't seeing things.  The\n"+
      "bartender is an old, battle-scarred Velociraptor, who watches his\n"+
      "joint with sharp, almost piercing eyes. He is nattily dressed in a\n"+
      "well-pressed, but beer stained, periwinkle sunfrock. Over this\n"+
      "stylish dress, he sports an immaculate, white lace apron.  He snarls\n"+
      "at you, and gestures with his toothy maw at the well worn sign above\n"+
      "the bar, which appears to be a menu. Then, he winks at you.\n";

      items=({
	"menu","A large, well-gnawed piece of oak. Something is\n"+
	"written on it",
	"sign","A small iron sign with something written on it",
	"table","A white ivory table",
	"tables","Solid oak tables",
	"chairs","Solid oak chairs. They look well chewed",
	"bar","An immense bar, made of solid teak"});

      dest_dir=({ 
	"players/helmut/rooms/jungle4","east",
      });

  }

    query_property(arg) {
	return arg=="no_fight";
    } 
    init() 
    {
	::init();
	AA("order","order"); 
	AA("order","buy"); 
	AA("read","read"); 
    }
    read(str) {
	if (str=="menu" || str =="sign"  || str=="drink" || str=="drinks") {
	    write(
	      "=======================================================\n"+
	      "=             Welcome to The Raptor Pit               =\n"+
	      "=======================================================\n"+
	      "= We offer:                                           =\n"+
	      "= 1 Dinkel Acker                             30 coins = \n"+
	      "= 2 Jack Daniels                             80 coins =\n"+
	      "= 3 Water Bucket (cures poison)              20 coins =\n"+
	      "= 4 Raptor's Blood                          600 coins =\n"+
	      "= 5 Tyrannosaur Sweat                      1500 coins =\n"+
	      "= You can consume also in numbers ---> <buy 1>        =\n");


	    return 1;
	}
    }
    order(str)
    {
	string name, short_desc,art, mess;
	int value, cost, strength, heal;
	int pois;
	object dummy;
	if (!str) {
	    write("The bartender snarls:sdhgfudgtsdbjfkauf????\n");
	    return 1;
	}
	if (str == "dinkel" || str == "1" || str == "dink" || str == "dinkel acker") {
	    mess = "MMMMMM, boy, those Germans sure know how to brew beer!";
	    heal=40;
	    value=30;
	    strength=10;
	    art ="alko";
	}
	else if (str == "jack" || str == "2" || str == "jack daniel's") {
	    mess = "Smooth as cornsilk....AAAAAH";
	    heal= 100;
	    value = 200;
	    strength = 20;
	    art ="alko";
	}
	else if (str == "water" || str == "3" || str == "bucket" || str == "water bucket") {
	    mess = "Cold, clear, and as crisp as a North Country Morning!";
	    heal = 10;
	    value = 20;
	    strength = -7;
	    pois = 1;
	    art = "alko";
	}
	else if (str == "blood" || str == "4" || str == "raptor blood") {
	    mess = "The bartender snarls as he gives you this potent brew,\n"+
	    "which sears your throat";
	    heal = 250;
	    value = 600;
	    strength = 30;
	    art = "alko";
	}
	else if (str == "sweat" || str == "5" || str == "tyrannosaur sweat") {
	    mess = "WWWWWWWWHHHHHHHHAAAAAAAAAMMMMMMMM!!!!!!!!!!!!!!!!";
	    heal = 600;
	    value = 1500;
	    strength = 50;
	    art = "alko";
	}

	if (call_other(TP, "query_money", 0) < value) {
	    write("The bartender snarls: asjhgasgajhfjhfdj, and waggles a\n"+
	      "menacing claw in your direction.\n");
	    return 1;
	}
	if (art=="alko") {
	    if (!call_other(TP, "drink_alcohol", strength)) {
		write("The bartender growls: grrrrhrgrgrhghggr, and shakes\n"+
		  "his toothy head, pointing to a breathalyzer.\n");
		return 1;
	    }
	    if (pois == 1)
	    {
		TP->add_poison(-this_player()->query_poisoned());

	    }
	}

	if(!mess)
	{
	    write("The bartender snarls: dsgfaiuyutgopsdhfag, and gestures to the menu\n"+
	      "with his slavering fangs.\n");
	    return 1;
	}
	write("You pay " + value + " coins.\n");
	call_other(TP, "add_money", - value);
	call_other(TP,"heal_self",heal*2);
	write(mess + ".\n");
	return 1;
    }
