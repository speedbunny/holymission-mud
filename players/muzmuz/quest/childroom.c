inherit "room/room";
object girl;
void reset (int arg)
{ 
   if (!girl) 
   {
     girl = clone_object("/players/muzmuz/quest/child");
             move_object(girl,this_object());
                } 
   if(!arg)
   {

     short_desc = "Childroom";
      long_desc = 
      "You entered the room of the little girl. You can see many toys lying around.\n" +
      "You can also see an empty cage in the middle of the room.\n";

        dest_dir =({"/players/muzmuz/quest/uphall","west",
                           });

         items = ({"toys","Many toys lying around",
                   "cage","It is empty",
                              });

        set_light (1);
     }
}

                  
