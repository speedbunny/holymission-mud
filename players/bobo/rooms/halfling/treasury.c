inherit "room/room";
reset (arg) {
   clone_list=({
      1, 1, "sword","/players/bobo/obj/hsword", 0,
      2, 1, "coins","obj/money",({"set_money", 1000}),
      3, 1, "shield","/players/bobo/obj/hshield", 0,
   });
   ::reset (arg);
   set_light(1);
   short_desc="In a halfling hole.";
   long_desc=
      "You come down here and see that the halflings were holding out on\n"+
      "you. They not only know how to make walls of stone but also they\n"+
      "are rich. There are statues scattered throughout the room watching\n"+
      "you and the halfling's money, weapons, and armours. You can also see\n"+
      "that pillars similar to the ones above are lining this room as well.\n";
   dest_dir=({
      "/players/bobo/rooms/halfling/leader.c","up",
      });
   items=({
      "armour","There are various armours attatched to statues about the room",
      "money","There is money all about you, all you have to do is find it and collect it",
      "pillars","White stone pillars are keeping the roof from colapsing",
      "statues","Statues of they are all types of humanoid are down here, all very well armed",
      "stone","The stone on the wall is rough and porous, but very servicable",
      "walls","The walls are made of porous stone and are very bumpy",
      "weapons","The statues are well armed, too bad you can't take them from the statues",
      });
   replace_program("room/room");
}
