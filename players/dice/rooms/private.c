


inherit "room/room";
reset (arg) {

if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Private";
   long_desc =
     "This is the private room of DICE and MAXXINE.\n"+
     "It's well decorated, and no mess or work to be seen at all,\n"+
     "They are a happy couple, and love eachother well.\n"+
     "Roses are seen all around here.\n"+
     "A beautiful picture is hanging here.\n";

   dest_dir = ({
             });

   items =({
          "picture","A beautiful picture of Dice and Maxxine reading JUST MARRIED"
          
          });

   smell = "The smell of roses is all around here, you feel good.\n";
}
