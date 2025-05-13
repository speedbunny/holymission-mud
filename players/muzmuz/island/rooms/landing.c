inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {
    short_desc = "Landing Point";
/*
     long_desc = "You are standing on the landing stage of the Island of Death. This is the " +
                 "only exit off the island, so you had better remember this location, or you will " +
                 "have problems leaving this island.\n";
*/
    long_desc = "You are standing at the landing for the " +
                "Island of Death. This is the only exit from the island " +
                "so remembering your way to this place would be a good " +
                "idea. Otherwise leaving this island will not be easy.\n"; 
                

   items = ({"ocean","The blue ocean",
             "island","the Island of Death. You feel depressed",
           });
    dest_dir = ({
                 "/players/muzmuz/island/rooms/di","east",
               });
   
    set_light(1);
    }
}
