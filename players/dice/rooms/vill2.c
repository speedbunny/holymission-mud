

inherit "room/room";
object sign1;


reset(arg) { ::reset(arg);
   if(!arg) {

           if(!sign1)
     move_object(sign1 = clone_object("/players/dice/obj/sign1"),this_object());
     }

if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Village entry";
   long_desc =
     "You are walking in the village.\n"+
     "The houses are surrounding you completely now.\n"+
     "A small alley to the north can be spotted.\n"+
     "A sign is hanging on the corner of the alley. \n";

   dest_dir = ({
      "players/dice/rooms/vill1","west",
      "players/dice/rooms/vill3","east",
      "players/dice/rooms/alley","north"
       });

   items = ({
      "sign","A wooden sign with something written on it",
      "house","A small house, belongs to a coalminer family",
      "houses","Small houses belonging to coalminers",
      "alley","An alley leading north"
       });


}
