
inherit "players/dice/rooms/wakeup.c";

query_no_teleport() {return 1;}
object troll;

reset(arg) {
    ::reset(arg);
    if(!arg){
           if(!troll)
           troll=clone_object("/players/dice/obj/troll");
           move_object(troll,this_object());
           }

 if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Twilight zone";
   long_desc =
     "You are hanging up side down in the middle of an open plain\n"+
     "Things look really strange here, like all has been\n"+
     "turned up side down and inside out.\n";

   dest_dir = ({
      "players/dice/2light/2l3","east"
       });

   items =({
            "things","Really weird things, all hanging up side down in the\n"+
                     "air, and all look turned inside out :\n"+
                     "Or is it you who is turned over and over ?",
            "plain","It looks like a normal plain giantic pentagram",
            "zone","The Twilight Zone",
            "twilight zone","A strange, bizar world between fantasy and reality"
            });


   smell = "Smells weird here.\n";

 }
