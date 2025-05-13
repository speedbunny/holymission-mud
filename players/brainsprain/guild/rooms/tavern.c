/*=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+ Thieves' Tavern =+=+=+=+=+=+=+=+=+=+=+=+=+=+=*/
#define TP     this_player()
#define NF     return notify_fail

inherit "room/room";

void reset(int arg)
{
    ::reset(arg);
    if (!arg)
    {
	set_light(1);
	short_desc= "Thieves Tavern";
	long_desc=
	"This is the Thieves Tavern.\n"
	+ "Peering through the murk, you notice "
	+ "a menu on the wall and a few washed-up "
	+ "cat burglars and boxmen, mumbling "
	+ "into their drinks.\n";
	items=({
	  "menu","It is written in a language you can fortunately read",
	  "burglars","You see in their faces how the stress finally got to them",
	  "boxmen","These experts in safe-cracking lost their fine senses of "
	  +"touch and hearing,\nleaving them jobless and pitiful",
	  "guy","A thin, wiry guy with shifty eyes",
	});
	dest_dir = ({ "/guild/master"->query_room(1), "south" });
    }
}

void init()
{
    ::init();
    add_action("order","order"); 
    add_action("order","buy"); 
    add_action("read","read"); 
}

int read(string str)
{
    if (str=="menu" || str=="sign") {
	write("\nThieves Tavern\n"
	  +"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n"
	  +"Beverages:\n"
	  +"  Dagger in the back      1000\n"
	  +"  Hand in the purse        500\n"
	  +"  Knife in the heart       100\n"
	  +"  Rogue beer                30\n"
	  +"  Pickpocket high           30\n"
	  +"Meals:\n"
	  +"  Burglar salad            500\n"
	  +"  Safecracker spaghetti    200\n"
	  +"  Cutpurse delight          30\n"
	  +"=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+\n");

	return 1;
    }
}

int order(string str) {
    string type, mess;
    int value, strength, heal;

    if(!str) 
    {
	write("The guy behind the bar says, 'Can I take your order or what?'\n");
	return 1;
    }

    switch(str) {
    case "dagger in the back":
    case "dagger":
	mess = "You gasp and wonder if this drink is lethal";
	heal = 85;
	value = 1000;
	strength = 40;
	type = "alco";
	break;
    case "hand in the purse":
    case "hand":
	mess = "The smooth drink slides down your throat";
	heal = 42;
	value = 500;
	strength = 20;
	type ="alco";
	break;
    case "knife in the heart":
    case "knife":
	mess = "You do a shot of whisky";
	heal = 15;
	value = 100;
	strength = 10;
	type = "alco";
	break;
    case "rogue beer":
    case "beer":
	mess = "You relax and sip on a cool beer";
	heal = 2;
	value = 30;
	strength = 3;
	type = "alco";
	break;
    case "pickpocket high":
    case "high":
	mess = "You think a little more clearly now";
	value = 30;
	strength = -3;
	type = "alco";
	break;
    case "burglar salad":
    case "salad":
	mess = "You eat a healthy salad";
	heal = 42;
	value = 500;
	strength = 20;
	type = "food";
	break;
    case "safecracker spaghetti":
    case "spaghetti":
	mess = "You make an awful mess, but what great pasta";
	heal = 25;
	value = 200;
	strength = 15;
	type = "food";
	break;
    case "cutpurse delight":
    case "delight":
	mess = "You head feels less fuzzy and you think clearer";
	heal = 0;
	value = 30;
	strength = -2;
	type = "food";
	break;
    default:
	write("The guy behind the bar looks at you and grumbles.\n");
	return 1;
	break;
    }

    if(TP->query_money() < value)
    {
	write("The guy behind the bar grumbles about paying for it and walks away.\n");
	return 1;
    }

    if (type=="alco") {
	if(!TP->drink_alcohol(strength))
	{
	    write("The guy behind the bar grumbles about drunks and walks away.\n");
	    return 1;
	}
    }

    else if(type=="food") {
	if(!TP->eat_food(strength))
	{
	    write("They guy behind the bar says, 'Aren't you done yet?'\n");
	    return 1;
	}
    }

    write("You grudgingly shell out " + value + " coins.\n");
    TP->add_money(-value);
    TP->heal_self(heal);
    write(mess + ".\n");
    say(TP->query_name() + " orders something.\n");
    return 1;
}
