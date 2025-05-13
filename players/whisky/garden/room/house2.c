// Fixed the clone object for your cembalo 040394 Colossus 

#define	TP	this_player()
#define	TPN	TP->query_name()
#define TPPOS	TP->query_possessive()

inherit "room/room";
#include "../garden.h" 

int gotbones;

reset(arg) {

    if (!present("cembalo"))
	CO("cembalo");
    gotbones=0;
    if (arg) return;

    set_light(0);
    property = "no_teleport";
    short_desc = "In a strange House";
    long_desc = 
    "You have now entered that strange building and you find "+
    "yourself in a big dark hall. There are spider webs hanging "+
    "down the wall and some human bones lying on the floor. "+
    "To the north you can see a big oven with flames leaping "+
    "out of it. There is a rickety wooden stairway leading up "+
    "and down.\n";
    dest_dir = ({ ROOM+"/attic","up",
      ROOM+"/kitchen","east",
      ROOM+"/cellar","down",
      ROOM+"/house1","south" });

    items=({"wall","You only see dusty red bricks",
      "bones","You see some big heavy human bones lying on the floor",
      "oven","A big black oven with fire coming out of it.\n" +
      "It is used to make grilled meat of curious adventurers",
      "stairway","An old wooden stairway",
      "fire","A bright fire coming out from the oven",
      "door","A big iron door with a wooden sign on it",
      "webs","You see big grey spider-webs hanging down the wall",
      "sign","You see the letters <if you ever come in you'll never come out>"});
}

init() {
    ::init();
    add_action("unlock","unlock");
    add_action("open","open");
    add_action("read","read");
    add_action("get","take");
    add_action("get","get");
    add_action("climb","climb");
    add_action("move","north");
    add_action("move","west");
    add_action("search","search");

}
search(str) {
    if (str=="pocket") { return; }
    write("You search and search and found nothing.\n");                   
    return 1;
}
move(str) {
    if (!str) str=query_verb();
    switch(str) {
    case "north" :
	write("It seems to get slightly hotter ...\n\n");
	say("You are mad with horror as you see "+TPN+" leaving straight\n"
	  + "into the hot burning oven to the north !\n"
	  + "Screams of pain fill the room, it is horrible !!!\n\n");
	move_object(this_player(),ROOM+"/oven");
	return 1;
    case "west" :
	if (present("cembalo")) {
	    write("As you bump against the cembalo, you hear a beautiful chord.\n");
	    say(TPN+" bumps against the cembalo. A beautiful chord fills the room.\n");
	    return 1;
	}
	write("You bang your head on a closed door.\n");
	say(TPN+" hurts "+TPPOS+"self running into a closed door.\n");
	TP->reduce_hit_point(10+random(10));
	return 1;
    default : return::move(str);
    } 
}

climb(str) {
    if (str=="stairway")
	return move("up");
}

read(str) {
    if (str=="sign") {
	write("You read: \"If you ever come in you'll never come out.\"\n");
	return 1;
    }
}

get(str) {
    if (gotbones) {
	write("They have decayed too much.\n");
	return 1;
    }
    if (str=="bones") {
	gotbones=1;
	write("You pick up some bones.\n");
	say(TPN+" picks up some bones from the floor.\n");
	transfer(clone_object(OBJ+"/bones"),this_player());
	return 1;
    }
}

open(str) {
    object ob;

    switch(str) {
    case "oven":
	write("As you try to open the oven, you burn your fingers !\n");
	say(TPN+" tries to open the oven and burns "+TPPOS+" fingers.\n");
	TP->reduce_hit_point(10+random(10));
	return 1;
    case "door":
	write("You try to open the door, but it is locked.\n");
	say(TPN+" tries to open the door, but it is locked.\n");
	return 1;
    case "cembalo":
	if (ob=present("cembalo")) {
	    write("As you try to open the cembalo, it breaks into tiny pieces "
	      + "of wood.\n"
	      + "It was too old withstand the brute power of an adventurer "
	      +  "like you !\n");
	    say(TPN+" broke the cembalo with "+TPPOS+" clumsy hands.\n");
	    ob->self_destruct();
	    return 1;
	}
	write("There is no cembalo here. Some vulgar vandlas must "
	  + "have ruined it.\n");
	return 1;

    default: 
	write("You fail you can't open that, but you are on the right way.\n");
	say(TPN+" foolishly tries to open the door.\n");
	return 1;
    }
}

unlock(str) {
    switch(str) {
    case "oven" :
	write("You touch the oven, and burn your fingers !\n");
	say(TPN+" tries to unlock the oven, but only burns "+TPPOS+" fingers.\n");
	TP->reduce_hit_point(10+random(10));
	return 1;
    case "door" :
    case "the door":
	if (present("questkey",this_player())) {
	    write("You try to open the door.\n"+
	      "Yep, the key fits, but impossible to turn around.\n"+
	      "There seems to be too much rust on the key.\n");   
	    say(TPN+" tries to open the door but fails, the key seems to fit.\n"+
	      "but as hard "+TPN+" tries it seems unpossible to unlock the door.\n");
	    return 1;
	}
	else if (present("witchkey",this_player())) {
	    write("Suddenly the door begins to turn around and moves you inside "+
	      "a strange room.\n\n");
	    TP->move_player("through a magic door#"+ROOM+"/cell");
	    write("\nBut with a  >>> K L I C K <<< the door closes again !\n");
	    return 1;
	} else {
	    write("Sorry, but you don't have the proper key.\n");
	    say(TPN+" tries to open the hidden door but fails.\n");
	    return 1;
	}
    default:	
	write("You are a little bit confused, aren't you ?\n");
	say(TPN+" foolishly tries to open a "+str+".\n");
	return 1;
    }
}
