inherit "/obj/thing";

#include "/players/mangla/defs.h"

object tomovenin;

int drop() {

    destruct(TO);
    return 1;
}

int _wak(string str) {

    object whereto;
    object tomovenin;

    if (!str) {
	write("You have to tell me who to help.\n");
	return 1;
    }

    if(TP->RNAME != "nylakoorub" && TP->query_arch()) {
	write("You are unauthorized to use this object.\n" +
	  "Your name will not be noted this time but will\n" +
	  "be noted in the future. This object is only for\n" +
	  "use my Mangla and located in a secured directory.\n" +
	  "The sole fact that you would posses this object\n" +
	  "is a violation of the rules.\n");
	destruct(TO);
	return 1;
    }
    whereto = find_player(lower_case(str));
    if (objectp(whereto)) {
	tomovenin = clone_object("/players/mangla/gal/moveob");
	MOVE(tomovenin,whereto);
    }
    else {
	write("That person is not playing right now.\n");
	write("Please double check your recieves name and try again.\n");
    }
    return 1;
}

int _lock(string str) {

    object whereto;

    if(!str) {
	printf("You have to tell me who!!\n");
	return 1;
    }
    whereto = find_player(lower_case(str));
    if(whereto)
	MOVE(clone_object("/players/mangla/gal/locket"),whereto);
    else
	printf("No such person playing right now.\n");
    return 1;
}

int _doing(string str) {

    string abspath;
    string *temp,temp1;
    object tomove;
    object whereto;

    if (!str) {
	write("Move item ");
	return 0;
    }
    if (TP->RNAME != "nylakoorub" && TP->query_arch()) {
	write("You are unauthorized to use this object.\n" +
	  "Your name will not be noted this time but will\n" +
	  "be noted in the future. This object is only for\n" +
	  "use my Mangla and located in a secured directory.\n" +
	  "The sole fact that you would posses this object\n" +
	  "is a violation of the rules.\n");
	destruct(TO);
	return 1;
    }
    temp1 = str + " ";
    temp = explode(temp1, " ");
    if (temp1[0] != '/') {
	abspath = TP->query_path();
	temp[0] = "/" + abspath + "/" + temp[0];
    }
    if (file_size(temp[0]+".c") < 0) {
	write("The path name you have given is either non-existant\n" +
	  "or off-limits to you. Please try again.\n");
	return 1;
    }
    tomove = clone_object(temp[0]);
    if (!objectp(tomove)) {
	write("That object does not exist.\nCheck the path name again.\n");
	return 1;
    }
    whereto = find_player(lower_case(temp[1]));
    if (objectp(whereto)) {
	transfer(tomove,whereto);
    }
    else {
	write("That person is not playing right now.\n");
	write("Please double check your recieves name and try again.\n");
    }
    write("Object: " + tomove->short() + " successfully moved " +
      "to Player: " + whereto->RNAME + "\n");
    TELL(whereto,"You have received an item.\n");
    return 1;
}


int _ECHOALL(string str) {

    if (TP->RNAME != "nylakoorub" && TP->query_arch()) {
	write("You are unauthorized to use this object.\n" +
	  "Your name will not be noted this time but will\n" +
	  "be noted in the future. This object is only for\n" +
	  "use my Mangla and located in a secured directory.\n" +
	  "The sole fact that you would posses this object\n" +
	  "is a violation of the rules.\n");
	destruct(TO);
	return 1;
    }
    write("You echo all: '" + str + "'\n");
    shout(str + "\n");
    return 1;
}

int _cont_shut() {
    shutdown();
    return 1;
}

int _shut() {
    shout(BLINK+"SYSTEM: "+RESET+
      "Please type save at this time. There will be\n" +
      "a reboot in 30 seconds.\n");
    call_out("_cont_shut",30);
    return 1;
}


reset(arg) {
    ::reset(arg);
    if (arg) return;

    set_short("Item mover");
    set_name("mover");
    set_long(
      "\nThis is a device used to help Nylakoorub or an Arch with a player\n"+
      "problems. It moves an object directly to a player.\n" +
      "Use the syntax: 'movei <path> <playername>'\n\n" +
      "The path can be either relative or absolute.\n\n" +
      "There is one exception to this, the ninjas. Because of the\n" +
      "way the weapons are custom for each player. You will need to\n" +
      "use another command:\n" +
      "\t\tnin <playername>\n\n" +
      "This creates an invisible object on the player where they are\n" +
      "able to recieve a daito('daito_please') or shuto('shuto_please').\n" +
      "The temp item destructs after cloning one weapon to the player.\n\n");
    set_weight(1);
}

init() {
    ::init();
    add_action("_ECHOALL","echoa");
    add_action("_doing","movei");
    add_action("_wak","nin");
    add_action("_shut","do_it");
    add_action("_cont_shut","force_it");
    add_action("_lock","locket");
}


