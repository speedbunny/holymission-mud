

inherit "room/room";

object minson;

reset(arg){::reset(arg);
  if(!arg){
           if(!minson)
            minson=clone_object("/players/dice/obj/minson");
            move_object(minson,this_object());
            }

if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Miners son's room";
   long_desc =
     "This room is due to be rebuild.\n"+
     "But as the coalminer has no money left after the\n"+
     "rebuilding of his daughters room, he has to wait.\n";

   dest_dir = ({
      "players/dice/rooms/house1","east",
             });

   smell = "This room smells like dirty socks and sweat.\n";

 }
