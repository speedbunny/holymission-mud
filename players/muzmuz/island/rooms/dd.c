inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

    short_desc = "dune";
     long_desc = "You are inside the dunes. As you stand still and listen carefully, you hear\n" +
                 "a ghost of the sound of an ocean. But it is too quiet to notice where it \n" +      
                 "comes from.\n";

        items = ({"dunes","Huge dunes, covered with sand",
                  "sand","Hot white sand"});
      dest_dir = ({"players/muzmuz/island/rooms/dc","north",
                   "players/muzmuz/island/rooms/de","south",
                   "players/muzmuz/island/rooms/cd","west",
                  "players/muzmuz/island/rooms/ed","east",

                       });

      set_light (1); 
      }
}
