

inherit "room/room";

reset(arg) {
   if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Construction";
   long_desc =
     "This room is under construction.\n";
   dest_dir = ({
       "players/dice/rooms/vill6","west"
       });
   items =({
           });


   smell = "The smell of fresh Paint is very strong.";
}
