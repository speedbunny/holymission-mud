inherit "room/room";

reset(arg){

  if(arg) return;
    set_light(-2);

     short_desc="A tunnel";

   long_desc=
     "You have entered a dark cave, the walls of this cave are made of\n"
     "a jet black stone which seems to absorb light.  The only glimmer\n"
     "of light you see is the tunnel which you came in to the west, and\n"
     "a small hole to the east.\n";
     dest_dir=({"players/ambrose/avalon/entrance/entran2","west",
                "players/ambrose/avalon/entrance/cavern","hole"});

     items=({"walls","A dark black rock that seems to rip the light from "
                    +"your eyes",
             "tunnel","Looking behind you, you see the tunnel entrance.",
             "hole","A small hole which you might be able to enter"});
}
