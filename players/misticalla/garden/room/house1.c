
#define TP  this_player()
#define TPN TP->query_name()
#define TPOBJ   TP->query_objective()
#define TPPOS   TP->query_possessive()
 
inherit "room/room";
#include "../garden.h" 

object key;
int counter;
 
reset(arg) {
counter = 0;
    if (arg) return;
 
    set_light(0);
    short_desc = "In front of a strange house";
    no_castle_flag = 0;
    long_desc = 
        "You are now standing in front of that strange building. "+
        "It looks dark and devilish. You can see a waterchannel leading"+
         "down from the roof and to a mat at your feet. There is "+
         "the strange smell of gingerbread in the air. A wooden "+
         "door leads further to the north and a path leads back "+
         "to the south.\n";
    dest_dir = ({ ROOM+"/forest9", "south" });
    items = ({"building","A strange building looking like a witchhouse",
             "waterchannel","A metal, black painted waterchannel leading down from the roof to your feet",
           "door","A big wooden door with a small keyhole on the left side",
           "channel","A metal, black painted waterchannel leading down from the roof to your feet",
           "bulge","A little bulge, maybe there is something under it. Search?",
            "roof","You can see the contours of a big shingled roof",
           "keyhole","You see a small keyhole",
           "mat","You see a brown mat with a little bulge in the middle"});
}
 
init() {
  ::init();
  add_action("climb","climb");
  add_action("do_search","search");
  add_action("unlock","unlock");
  add_action("open","open");
  add_action("pick","pick");
  add_action("pick","lift");
  add_action("pick","get");
  add_action("pick","take");
  add_action("pick","raise");
  add_action("knock","knock");
  add_action("north","north");
  add_action("picklock","picklock");
}

picklock(str) {
  if (str=="door" && present("picklock",TP)) {
     write("You can't open a magical door by stupidly using a picklock ...\n");
     say(TPN+" the thief tries to use "+TPPOS+" picklock on the door.\n" +
    capitalize(TPOBJ)+" fails completely ...\n");
     return 1;
  }
}

north() {
  write("You bang your head against the closed door.\n");
  say(TPN+" runs into the door. Not very effective, though.\n");
  return 1;
}

knock(str) {
string msg;

  if (str=="door") {
     msg=" at the door. Knock "; 
     switch(random(14)) {
     case 0: msg+="knock ";
     case 1: msg+="knock ";
     case 2: msg+="KNOCK ";
     case 3: msg+="knark ";
     case 4: msg+="knock ";
     case 5: msg+="KNARK ";
     case 6: msg+="knerk ";
     case 7: msg+="KNERK ";
     case 8: msg+="knurk ";
     case 9: msg+="KNURK ";
     case 10: msg+="knork ";
     case 11: msg+="KNORK ";
     case 12: msg+"Knarrrrrrkkkkrrrr ";
     }
     msg+="...\n";
     write("You knock"+msg);
     say(TPN+" knocks"+msg);
     return 1;
  }
}

climb(str) {
  if (str!="waterchannel" && str!="channel" ) {
    write("You fail, but you are on the right way.\n");
    say(TPN+" tries to climb up to the roof but fails.\n");
    return 1;
  }
  write("You are climbing up the waterchannel.\n");
  TP->move_player("up the waterchannel#"+ROOM+"/waterchannel");
  return 1;
}

do_search ( str ) {
  
  if (str=="mat" && counter <=8) {
      write("As put your fingers under the mat you find a glowing golden key.\n");
      say(TPN+" lifts the mat and finds a key.\n");
      key=clone_object("players/whisky/garden/obj/key");
      move_object(key,this_object());
      counter++;
   } else if (str=="mat" && ( counter ) ) {
     write("Seems that someone was faster than you !\n");
     say(this_player()->query_name()+" searches the mat but finds nothing.\n");
   } else {
     return ( 0 );
  }
  return ( 1 );
 }

pick(str) {
  if (str=="mat") {
     write("You fail, the mat is fixed with two rusty nails on the ground.\n");
     say(TPN+" tries to pick up the mat, but it's nailed to the floor.\n");
     return 1;
  }
}


open (str) {
  write("You cant open the door, it is locked.\n");
  say(TPN+" tries to open the door but fails.\n");
  return 1;
}

unlock(str) {
  if (present("whiskeykey",TP)) {
     write("Suddenly the door begins to turn around and moves you inside the house.\n");
     TP->move_player("suddenly into the house#"+ROOM+"/house2");
     return 1;
  }
  write("You fail to open the door.\n");
  say(TPN+" fails to open the door.\n");
  return 1;
}
