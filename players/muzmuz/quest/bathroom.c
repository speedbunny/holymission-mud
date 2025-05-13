inherit "room/room";

void reset(int arg)
{
   if(!arg)
   {

    short_desc = "Bathroom";
     long_desc = "You have entered the bathroom. It looks clean and in the middle of the\n" +
                 "room you can see a white bathtub. There is also an empty wash basin.\n";

       items =({"basin","It is empty",
                "bathtub","It is a rusty bathtub, full of water",
                "water","The water is dirty",
                             });
   
        dest_dir = ({"players/muzmuz/quest/hall","east",
                                });

        set_light (1);

}
}
  
