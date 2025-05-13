/* cell.c (C) Whisky */ 
#define	TP	this_player()
#define TPN TP->query_name()
 
inherit "room/room";
int counter;
 
reset(arg) {
counter = 0;
    if (arg) return;
 
    set_light(0);
    property = "no_teleport";
   short_desc = "In a cell";
    no_castle_flag = 0;
    long_desc = 
        "You have entered the black cell of the strange buildling. "+
        "There are spider webs hanging down the wall and you see a "+
        "big cage in the northern corner of this room. There are "+
        "human remains lying on the floor. If you look down you "+
        "see an iron gully and if you look up you can see a "+
        "small fireladder leading up. You are lost and will never "+
        "ever leave this evil place.\n";
items= ({"wall","You see dirty red bricks",
         "webs","You see big grey spider-webs hanging down the wall",
         "cage","You see a big cage",
         "jack","Jack looks very thin and sad",
         "gully","You see a big iron gully and a small dungeon going down",
         "door","You see a closed iron door without a keyhole",
         "dungeon","You see a small dungeon inviting you to leave down", 
         "remains","You see human bones, flesh, and dried blood",

         "bones","You see big human bones",
         "ladder","You see a small iron fireladder leading up",
         "fireladder","You see a small iron fireladder leading up"});
}
 
 
init() {
  ::init();
  add_action("open","open");
  add_action("get","get");
  add_action("climb","climb");
  add_action("search","search");
  add_action("break_cage","break");
  add_action("unlock","unlock");
  add_action("say","say");
  add_action("tell","tell");
  add_action("enter","enter");
}
search(str) {
 if (str=="pocket") { return; }
    else {
    write("You are searching around, but you find nothing special.\n");
    say(TPN+" searches around, but finds nothing.\n");
    return 1;
    }
}  
unlock(str) {
  switch (str) {
  case "door": 
  case "the door":
    write("Sorry, but the door has no keyhole.\n");
    say(TPN+ " tries to unlock the door but fails.\n");
    return 1;
  case "cage":
   case "the cage":
   write("Sorry, but the cage has no keyhole.\n");
    say(TPN+ " tries to unlock the cage but fails.\n");
    return 1;
  }
}
open(str) {
  switch (str) {
   case "door":
   case "the door":
   write("Sorry, but the door is locked.\n");
   say(TPN+" tries to open the door, but it's locked.\n");
   return 1;
   case "cage":
   case "the cage":
   write("Sorry, but the cage is locked, it seems you need something to break it.\n");
   say(TPN+" tries to open the cage but fails.\n");
   return 1;
   case "gully":
   case "the gully":
   write("The gully is already open.\n");
   return 1;
}
}

say(str) {
  if (str=="hoppla jump") {
     write("As you say hoppla jump your wizardshat gets mad and " +
	   "jumps happily on your head.\n");
     say("Suddenly the wizardshat jumps and hopples happily on " +
	  TPN+ "'s head.\n");
     return 1;
  }
}

tell(str) {
  if (str=="hermes hi") {
    write("Hermes tells you: rehi !!!\n");
    return 1;
  }
}

enter(str) {
  if (str=="dungeon") {
     write("You want to leave down the small dungeon " +
	   "but you are much too fat.\n"+
	   "You should have stayed some days in the witch's prison.\n");
     say(TPN+" tries to leave down the dungeon but fails.\n");
     return 1;
  }
}

break_cage(str) {
  object rucksack;
  /*
  if (!present("wsoul",this_player())) {
  this_player()->move_player("to a hotter place#players/whisky/garden/room/oven");
  return 1;
  }
    */
  if (present("crowbar",this_player())) {
  if ((str=="cage" || str=="the cage" || str=="cage with crowbar") && counter < 1) { 
     write("K L I C K the cave opens and Jack jumps out.\n"+
           "Jack smiles happily\n"+
	   "Jack says: Thank you for helping me, but I could have managed "+
		      "it alone.\n"+
	   "Jack says: But well, here you have a little present for "+
		      "helping me.\n"+
 	   "Jack gives you his rucksack.\n"+
	   "Jack waves happily and leaves down the dungeon.\n");
     this_player()->set_quest("witchquest");
     shout("Jack shouts: Well, "+TPN+" helped me to get free.\n");
     rucksack=clone_object("players/whisky/garden/obj/rucksack2");
     if(transfer(rucksack,TP)) {
	write("You are carrying too much.\n");
	move_object(rucksack,this_object());
     }
     say(TPN+ " opens the cave and lets Jack free.\n");
     say("Jack waves happily and leaves down the dungeon.\n");
     counter = 1;
     return 1;
  } else {
     write("Ups, you seem to be too slow, there was already someone who broke the cage.\n"); 
     say(TPN+" tries to free Jack but fails.\n");
     return 1;
  } 
  return 1;
  }
  else {
   write("You try to break the cage, but you are much too weak.\n");
    say(TPN+" tries to break the cage but fais.\n");
   return 1;
  }
}

climb(str) {
  if (str!="fireladder" && str!="ladder") 
     write("Climbing What ?? You are a little bit confused aren't you.\n");
  else {
     write("You are climbing up the fireladder, what will happen ??\n");
     say(TPN+" climbes up the fireladder.\n");
    TP->move_player("up the fireladder#players/whisky/garden/room/attic2");
  }
  return 1;
}

get(str) {
  if (str=="bones") {
   write("The bones are magically fixed on the floor, you can't take them.\n");
   say(this_player()->query_name()+ " tries to pick up the bones but fails.\n");
   return 1;
  }
}


