

inherit "/players/dice/rooms/sleep";


reset (arg) {

if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Parents bedroom";
   long_desc =
     "This is the bedroom of the coalminer and his wife.\n"+
     "Smells pretty sweaty here, and the bed in the middle\n"+
     "hasn't been cleaned for quite a while.\n"+
     "But a sort of a relief is hanging around here.\n";

   dest_dir = ({
      "players/dice/rooms/house1","southeast",
             });

   items =({
          "bed","A huge bed used by the coalminer and his wife.\n"+
          "It hasn't been cleaned for a while, so the sheets could\n"+
          "use a cleaning. Coaldust is lying all over the place.",
          "sheet","Dirty sheet on the bed",
          "sheets","Dirty sheets on the bed",
          "dust","Coaldust"
          });

   smell = "This room smells pretty sweaty, and a strange smell is coming\n"+
           "from the bed.\n";
 } 
