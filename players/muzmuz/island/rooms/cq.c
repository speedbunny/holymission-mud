inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

       short_desc = "southwestern corner";
        long_desc = "This is the southwestern corner of the island. You are standing high above the\n" +
                    "ocean. To the northwest there are the swamps.\n";

       items = ({"ocean","The blue ocean",
                    "swamps","Huge swamps with mosquitos"});
         dest_dir =({"players/muzmuz/island/rooms/cp","north",
                     "players/muzmuz/island/rooms/dq","east",
                       });
        set_light (1); 
       }
}
