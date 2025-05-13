

inherit "room/room";

reset(arg){::reset(arg);
 if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Village";
   long_desc =
     "You are standing in the northeastern part of the village. \n"+
     "West of here you can see a HUGE tree trying to touch the clouds. \n"+
     "Not a sound can be heard all over the place,\n"+
     "but you like the peace and quiet here. \n";
   dest_dir = ({
      "players/dice/rooms/vill12","west"
       });

   items =({
            "tree","A strange looking tree standing in the middle of a plain west of here",
             "huge tree","A strange looking tree standing in the middle of a plain west of here",
            "plain","A large open plain",

            "village","A coalminer village",
            "clouds","Huge clouds crossing the sky",
            "sky","Waaaaaaaay up there is the sky",
            "large tree","A strange looking tree, standing in the middle of a plain west of here",
            "leaves","Strange looking leaves"
            });


   smell = "The smell of fresh woods fills the air .\n";

  }
