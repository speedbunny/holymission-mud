inherit "room/room";

object obj;
int a;

reset(arg) {

    set_light(1);
    short_desc="Altar room";
    long_desc="You're in the Altar room.\n"+
              "A big block of black rock stands in the middle of this room.\n";
    dest_dir=({
               "players/kelly/rooms/mythwood/cloister","east",
             });
   items=({
           "block", "The top of a bright sword looks out from the block.\n"+
                    "There is a round space in the rock beneath the sword",
           "rock",  "The top of a bright sword looks out from the block.\n"+
                    "There is a round space in the rock beneath the sword",
           "sword", "This must be a very valuable weapon",
           "space", "A round space, maybe something can be put in",
   });

}
