

inherit "room/room";

reset(arg){::reset(arg);
 if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Village";
   long_desc =
     "You are in the utter northwestern part of the village.\n"+
     "To the far east is a strange tree standing in the middle of an open plain.\n"+
     "Its leaves are hanging here, placing you in a shadow.\n";
   dest_dir = ({
      "players/dice/rooms/vill14","east"
       });

   items =({
            "tree","A strange looking tree standing in the middle of the plain east of here",
            "plain","A large open plain west of here",
            "village","A coalminer village",
            "large tree","A strange looking tree, standing in the middle of the plain west of here",
            "leaves","Strange looking leaves placing you in shadows",
            "shadow","A large shadow, protecting you from the sun"
            });


   smell = "The smell of fresh woods fills the air .\n";

  }
