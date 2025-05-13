inherit "room/room";
object hobbit;

reset(arg) {
  /* if (!hobbit || !living(hobbit) )
    { hobbit=clone_object("players/bug/monsters/hobbit1");
      transfer(hobbit,this_object());
    } */
   if(arg) return;
   set_light(1);
   short_desc="The village road";
   long_desc="You're standing on a small crossing in the middle of\n"+
             "the village, west is a pub. East another road leads\n"+
             "to the river. back north are more small halfling\n"+
             "houses, south is a small building.\n";
   items=({"crossing","a crossing of the main village road",
           "village","A hobbit village",
           "pub","the village pub",
           "road","a ordinary road",
           "river","a small river which lies east from here",
           "houses","small houses, almost impossible for bigfolk to enter",
           "building","a small building",});
   dest_dir=({"players/shaka/village/pub","west",
              "players/shaka/village/vil4","east",
              "players/shaka/village/vil2","north",
              "players/shaka/village/vil15","south",});
}
