
inherit "room/room";
query_no_teleport() {return 1; }

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
     "You stand in the middle of an open plain\n"+
     "in the middle of the Twilight zone.\n"+
     "You see the southern part of the church to your west. \n"+
     "In the middle of the plain you see a bulb of light hanging\n"+
     "one meter from the ground. \n";

   dest_dir = ({
      "players/dice/2light/2l2","east",
      "players/dice/2light/2l4","west"
       });

   items =({
            "plain","It looks like a normal plain giantic pentagram",
            "church","A looks like a normal church",
            "bulb","A strange looking bulb of light, emitting a cold white light",
            "ground","Seems like glass, you can see through it\n"+
                     "but can not regonize anything below it.\n"+
                     "It seems like strange figures are moving below your feet\n",
            "figures","You can not regonize them from here",
            "zone","The Twilight Zone",
            "twilight zone","A strange, bizar world between fantasy and reality"
            });


   smell = "Smells weird here.\n";

 }
