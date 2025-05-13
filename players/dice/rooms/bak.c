
inherit "room/room";

object bigmama;

reset(arg){::reset(arg);
           if(!bigmama)
  move_object(bigmama=clone_object("/players/dice/obj/bigmama"),this_object());


if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Bakery";
   long_desc =
     "You are standing in the Bakery of Big Mama.\n"+
     "The shop is filled with the smell of fresh bread, it's clean,\n"+
     "and you are getting really hungry.\n"+
     "A counter stands in the middle of the shop.\n";

   dest_dir = ({
      "players/dice/rooms/path4","south",
      "players/dice/rooms/bak_e","east"
             });
   items =({
            "counter","A large empty counter normally filled with bread",
            "bread","The counter is empty, there is no bread",
             "bakery","A large bakery"
             });


   smell = "Here the smell of fresh bread is the strongest.\n";
  }
