inherit "room/room";
reset(arg) {
   ::reset(arg);
   if(arg) return;
   set_light(1);
   short_desc="Beside stream";
   long_desc =
"You are standing beside a small stream. A steep embankment lies behind you,\n\
and looking upstream, you can see glimpses of the bridge through the bushes\n\
and trees to the north. A dangerous looking pile of logs blocks progress\n\
towards the bridge. There is a sign posted at the bottom of the embankment.\n\n\
Suddenly, you feel as if someone were watching you...\n";

   dest_dir=({
      "/players/stanley/room/stream/stream3","west",
   });

   items=({
   "sign","The sign is at the bottom of the embankment. Try reading it",
   "embankment","You can {climb embankment} back up to the bridge",
   "stream","The stream runs from the direction of the bridge on to the south.\n"
   + "The water looks slightly muddy",
   "pile","There must have been quite a flood at one time to carry all these logs\n"
   + "to this spot! If you are to get under the bridge, you are going to have\n"
   + "to deal with getting by this",
   "logs","There must have been quite a flood at one time to carry all these logs\n"
   + "to this spot! If you are to get under the bridge, you are going to have\n"
   + "to deal with getting by this",
   "tree","The tree is a tree",
   "trees","The trees pose no problems for you"
   });
}

init(arg) {
   ::init();
   add_action("_read","read");
   add_action("climb","climb");
}

climb(str) {
   if(!str) return 0;
   if(str=="logs" || str=="pile" || str=="logjam") {
      write("\nYou carefully pick your way over the pile of logs...\n\n");
      call_other(this_player(),"move_player","carefully over the pile of logs#players/stanley/room/stream/stream2");
      return 1;
   }
   if(str=="embankment") {
      write("\nYou climb up the embankment.\n\n");
      call_other(this_player(),"move_player","up the embankment#room/hump");
      return 1;
   }
   return 0;
}

_read(str) {
   if(!str) {
      write("Read what?\n");
      return 1;
   }
   if(str=="sign") {
      write("The sign says:\n\n" + 
        "                      IS I  Y UR LAS  CHAN E \n" +
        "                          URN BACK!!\n" +
        "                   DO N   GO  NDE  TH  B ID  !\n");
      return 1;
   }
}
