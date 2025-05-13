inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

    short_desc = "dune";
     long_desc = "You are inside the dunes. The air is hot here and there isn`t even a slight\n" +
                 "breeze. The sand seems to burn and you look for a cooler place to stay.\n",

         items =({"dunes","Huge dunes, covered with sand",
                  "sand","Hot white sand"});
     dest_dir = ({"players/muzmuz/island/rooms/dd","north",
                  "players/muzmuz/island/rooms/df","south",
                  "players/muzmuz/island/rooms/ce","west",
                  "players/muzmuz/island/rooms/ee","east",

                    });

     set_light (1); 
     }
}
