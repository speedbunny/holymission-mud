

inherit "room/room";

object coal;

reset(arg) {
           if(!coal)
           coal=move_object(clone_object("/players/dice/obj/coal"),this_object());

if (arg) return;

   set_light(0);
   no_castle_flag = 1;

   short_desc = "Coal storage";
   long_desc =
     "This is the coal storage.\n"+
     "The smell is really bad here, and it really takes your breath away.\n"+
     "and dust is hanging all over the place.\n";

   dest_dir = ({
      "players/dice/rooms/house6","south",
             });

   items =({
          "coals","These are the coals found in the coalmine.",
          "dust","Coaldust"
          });

   smell = "The stence of coaldust is the strongest here.";
}
