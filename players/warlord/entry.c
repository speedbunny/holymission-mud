#define TP	this_player()
#define TO      this_object()
#define TPN	TP->query_name()
#define TPP	TP->query_possessive()
 
inherit "room/room";
  int n;

 
reset(arg) {
  n=0;
  if (arg) return;
 
    set_light(1);
    short_desc = "In front of a strange house";
     long_desc="You are now standing in front of that strange house.\n"
        + "It looks dark and devilish. There is a @@door@@\n"
        + "leading to the north, but there seems no way to enter.\n"
        + "There is a small path leading back to the south\n";

    items = ({"house","A strange wooden house",
           "door","A big @@door@@ with no keyhole on it ",
        });
}
 
init() {
  ::init();
  add_action("search","search");
  add_action("unlock","unlock");
  add_action("open","open");
  add_action("knock","knock");
  add_action("smash","smash");
  add_action("north","north");
  add_action("picklock","picklock");
}


picklock(str) {
  if (str!="door") return; 
     write("The door has no keyhole !\n");
     say(TPN+" tries to use "+TPP+" picklock on the door, \n" +
        "but fails completely ...\n");
     return 1;
  }

north() {
  if (n==0) {
  write("You bang your head against the closed door.\n");
  say(TPN+" runs into the door. Not very effective, though.\n");
  return 1;
  }
  TP->move_player("north#players/warlord/workroom");
  return 1;
 }

knock(str) {
  if (str!="door") return; 
   write("You knock the door.... nothing happens !\n");
   say(TPN+" knocks the door .... nothing happens !\n");
     return 1;
  }

search (str) {
  write("You search and search...... but find nothing !\n");
  say(TPN+" searches around, but finds nothing !\n");
  return 1;
}

open (str) {
  write("You cant open the door, it is locked.\n");
  say(TPN+" tries to open the door but fails.\n");
  return 1;
}

unlock(str) {
     if (str!="door") return;
  write("You fail to unlock the door..... it has no keyhole !\n");
  say(TPN+" fails to unlock the door.\n");
  return 1;
}
smash(str) {
   if (str!="door") return;
   if(!present("hammer",TP)) {
     write("You try to smash the door....but nothing happens !\n");
     say(TPN+" tries to smash the door ... but fails !\n");
   return 1;
   }
   write("The door crumbles into tiny pieces !\n");
   say(TPN+" destructs the door with "+TPP+" hammer !\n");
   n=1;
  return 1;
 }

door() {
  if (n==0) { return "wooden door"; }
  return "broken door"; 
       }
   
    
      
