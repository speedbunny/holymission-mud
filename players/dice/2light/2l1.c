

inherit "/players/dice/rooms/sleep";
object sign2;


reset(arg) { ::reset(arg);
   if(!arg) {

           if(!sign2)
     sign2=clone_object("players/dice/obj/sign2");
     move_object(sign2,this_object());
     }

if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "The twilight zone";
   long_desc =
     "You are walking in the twilight zone.\n"+
     "Here you find all things are different from \n"+
     "the normal life. Nothing is what it seems,\n"+
     "And all is nothing ......\n";
    dest_dir = ({
       "players/dice/2light/2l2","north"
       });

   items = ({
      "sign","A strange looking sign, hanging upside down in the air",
       "all","Nothing",
       "nothing","All",
       "zone","The twilight zone",
       "twilight zone","A strange place between fantasy and reality",
       });


}
