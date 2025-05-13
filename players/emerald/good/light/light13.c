#define TP this_player()
inherit "room/room";

#define TPN this_player()->query_name()

void reset(int arg) {

  if (arg) return;

  set_light(1);

  short_desc="Stream";
  long_desc="You have come to a small stream in the middle of a wooded " +
            "area.  The stream look quite cool and refreshing, surrounded "+
            "by willows.  Small animals come here often to drink.\n";

  dest_dir=({"players/emerald/good/light/light11","east",
           });

  items=({"stream","The stream is more of river, fast and deep.  But the "+
                   "water looks to be very inviting..",
          "area","The stream is surrounded by woods",
          "trees","Willow trees with long, trailing limbs",
          "animals","Muskrats and groundhogs",
        });

  ::reset();

}


void init() {
   ::init();
   add_action("_swim","swim");
   add_action("_swim","enter");
}

_swim(arg) {
  call_out("swim1",2);
  return 1;
}

swim1() {
  write("You enter the cold waters of the stream.\n\n");
  call_out("swim2",2);
}

swim2() {
   write("You are trying to swim against the strong current.\n" +
         "The current is VERY strong here.\n");
  call_out("swim3",2);
}

swim3() {
  write("The current is TOO strong, you are pulled under the water.\n");
  call_out("swim4",2);
}

swim4() {
  write("You see your life flash before your eyes.\n");
  call_out("swim5",2);
}

swim5() {
  write("You start to gasp for air, you might not survive.\n");
  call_out("swim6",2);
}

swim6() {
  string name;
  object corpse, ob;
  ob = this_player();
  write("You 'awaken' and find yourself lying on a beach.\n\n" +
        "You have DIED! You see your corpse lying here besides you" +
        " on the beach here.\n\nIt seems you DID die, but for some"+
        " reason you are still alive!\n Must be a miracle!\n");
  name = (this_player()->query_name());
  corpse = clone_object("obj/corpse");
  corpse->set_name(this_player()->query_name());
  TP->move_player("swimming#players/emerald/good/evil/evil7");
  say(name+ " comes floating down the river, DEAD!\n\n");
  say(name + " shouts: I am alive!\n");
  move_object(corpse, environment(ob));

  return 1;
}
