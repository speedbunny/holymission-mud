
#define TP this_player()->query_name()
#define TPN TP->query_name()

inherit "/room/room";

reset(arg) {
  if(arg) return;

  set_light(0);
  property = "no_teleport";
  short_desc = "In a toilet";
  long_desc =
  "You have entered the Witch's bathroom. You can see a large "+
    "toilet standing in the middle of the room, and on the wall you "+
  "see a toilet paper support. This place is warm and friendly "+
  "but it smells awful in here. There is a sign on the wall.\n";

  dest_dir = ({
    "/players/whisky/garden/room/kitchen", "west",
              });

items = ({"support","A little grey paper support invites you to tear somepaper",
         "toilet","A small lady-toilet with a grey loo inviting you to sit down",
         "toilet","A nice place, invites you to sit down and do your business",
         "sign",
         "You read: Oil makes the paper a bit softer,\n"+
         "          And it makes your sweety ready for love.\n"+
         "          I always get the best oil from the island,\n"+
         "          which you can reach by mounting a dragon\n"+
         "          next to my old friend the Sailor.\n"+
         "          There might be bushes, but they are \n"+
         "          easy to pass.\n"+
         "          So come on oil your hot sweety i am ready\n"+
         "          for you !\n\n"+
         "                            Xenja the Witch",  
         "wall","You see grey bricks"});
 }

init() {
  ::init();
  add_action("tear","tear");
  add_action("sit","sit");
  add_action("search","search");
 }

search(str) {
  if (str=="pocket") { return; }
  write("You are searching the "+(str)+" but find nothing special.\n");
 /*  say(TPN+" searches around, but finds nothing.\n"); shit on it */
  return 1;
 }
tear(str) {
  if (str!="paper") {
   write("You fail, but you are on the right way.\n");
   return 1;
   }

if (str=="paper") {
  object paper; /* Moonchild */
  paper=clone_object("players/whisky/garden/obj/paper");
  if(transfer(paper,this_player())) {
    write("You are carrying too much.\n");
    destruct(paper);
    return 1;
  } /* End Moonchild edit */
  write("You tear down a sheet of paper.\n");
   say(TP+" tears down a sheet of paper.\n");
  return 1;
  }
}

sit(str) {
   if (str=="loo" || str=="down") {
   write("AHHHH you pull off your trousers and enjoy that special feeling.\n");
   say(TP+" sits down the low and immediately looks friendlier.\n");
   write("But suddenly you get a tickling feeling...\n");
   write("You feel that now something strange will happen.\n");
   move_object(clone_object("players/whisky/garden/monster/tapeworm"),this_object());
return 1; }
  else {
   write("Where do you want to sit ????\n");
  return 1;
 }
}
