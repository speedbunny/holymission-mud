

inherit "room/room";

reset(arg) {
   if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Village";
   long_desc =
     "You are walking in the village.\n"+
     "The houses are all around.\n"+
     "A small cloud of dust is hanging in the air.\n"+
     "A sign is hanging on the corner of the alley west from here.\n";

   dest_dir = ({
      "players/dice/rooms/vill2","west",
      "players/dice/rooms/vill4","east",
       });

   items = ({
       "sign","A great sign, but you can't read it",
      "house","A small house",
      "houses","Small houses",
      "dust","A small cloud of dust, hanging above the road",
      "road","A path leading east and west, a small trail can be spotted.",
      "trail","A trail leading east",
      "cloud","A cloud of dust" 
     });
}
init(){
   ::init();
      add_action("read","read");}
read(str){
  if(!str){
   notify_fail("Read what ?\n");
   return 0;
   }
   if(str == "sign") {
   write ("You can not read the sign. \n");
   return 1;
   }


}
