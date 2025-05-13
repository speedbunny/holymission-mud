

inherit "room/room";

reset(arg){::reset(arg);
 if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Village";
   long_desc =
     "You are in the northwestern part of the village.\n"+
     "To the east is a strange looking tree standing in the middle of an open plain.\n"+
     "Its leaves are hanging here, placing you in a shadow.\n";
   dest_dir = ({
      "players/dice/rooms/vill12","east",
      "players/dice/rooms/vill15","west"
       });

   items =({
            "tree","A strange looking tree east of here",
            "plain","A large open plain west of here",
            "village","A coalminer village",
            "shadow","Ordinary shadow",
            "shadows","Just normal shadows",
            "large tree","A strange looking tree, standing in the middle of the plain east of here",
            "leaves","Strange looking leaves placing you in shadows"
            });


   smell = "The smell of fresh woods fills the air .\n";

  }
