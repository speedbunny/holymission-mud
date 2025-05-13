

inherit "room/room";

object litrat;

reset(arg){
      ::reset(arg);
         if(!arg){
           if(!litrat){
           litrat=clone_object("/players/dice/obj/litrat");
           move_object(litrat,this_object());
           }
   if (arg) return;
   set_light(1);
   no_castle_flag = 1;

   short_desc = "Pub";
   long_desc =
     "These are the glowing ashes of the pub BACKSTAGE.\n"+
     "The last night it opened his doors, the people partied so hard \n"+
     "that the building was left in ashes.\n"+
     "The owner has not shown his face in town for a couple of weeks now,\n"+
     "people don't know what has happened to him. \n";

   dest_dir = ({
      "players/dice/rooms/alley","south",
             });

   items =({
          "ashes","Glowing ashes, you burn your hands touching them",
          "doors","They are partially burned, and totally wrecked",
          "ash","Glowing ash, you burn your hands touching it",
           "building","There is nothing left to see at the building,"+
                      " it's ruined",
          "owner","He is not here, he has fleed out of town",
          "backstage","What's left of it",
          "pub","What's left of it",
          });


   smell = "The smell of glowing ashes tortures you nose \n";
 }
}
