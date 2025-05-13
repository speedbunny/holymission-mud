inherit "room/room";

reset(arg) {
   if (arg) return;

   set_light(1);
   no_castle_flag = 1;

  short_desc = "Study room";
   long_desc = 
	"Here Dice comes in to concentrate and think...\n";

   dest_dir = ({
        "players/dice/2light/2l1","twilight",
        "players/dice/rooms/vill13","ccity",
        "players/dice/quest/q_entr","q_entr",
        "players/dice/rooms/testroom","test",
    }); 


   property = ({   "no_tport_in", "no_tport_out", "no_steal",
       "no_sneak" });

   smell = "This room smells like paint, and fresh cement.";
}

