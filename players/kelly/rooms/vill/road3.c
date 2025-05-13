inherit "room/room";

object people;

reset(arg) {

    if (arg) return;

    set_light(1);
    short_desc="Village road";
    long_desc="You're on the village road. A grocery store is to the west.\n"+
              "An armoury is east. The road continues south and northeast.\n" +
              "To the north you can make out a gate.\n";
    dest_dir=({
               "players/kelly/rooms/vill/road4","northeast",
               "players/kelly/rooms/vill/road2","south",
               "players/kelly/rooms/vill/armoury","east",
               "players/kelly/rooms/vill/grocery","west",
               "/players/mangla/rooms/newbie/new0","north",
   });

   if(!present("man")) {
     people=clone_object("obj/monster");
     people->set_name("man");
     people->set_race("human");
     people->set_male();
     people->set_short("A man");
     people->set_long("A man who lives here.\n");
     people->set_level(10);
     people->set_al(50);
     people->set_move_at_reset();
   }
}

