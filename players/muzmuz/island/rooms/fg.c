inherit "room/room";

void reset(int arg) 
{
     if(!arg)  
     {
  
     short_desc ="dunes";
      long_desc ="You are at the southern end of the dunes. South from you there are hills and\n" +
                 "north from you nothing than sand covered dunes. They don`t look inviting, but\n" +
                 "maybe there is something worth being looked for.\n";

       dest_dir =({"players/muzmuz/island/rooms/ff","north",
                         "players/muzmuz/island/rooms/eg","west",
                         "players/muzmuz/island/rooms/gg","east",
                        "players/muzmuz/island/rooms/fh","south",
                               });

       items =({"dunes","Huge dunes, covered with sand",
                  "sand","Hot white sand",
                  "hills","Little hills",
                         });
       set_light (1);
       }
}
