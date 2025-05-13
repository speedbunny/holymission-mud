


inherit "/obj/std_shop";


void reset(int arg) 
{
  ::reset(arg);
      
   short_desc = "Monk Shop";
 long_desc =
 "You have entered a room in the eastern part of the "+
  "abbey. There is a counter here where a monk eyes you warily. "+
  "He has many items for sale, and is willing to give you money for "+
  "items you wish to get rid of. To the south is the meeting "+
  "room where monks congregate. The courtyard is to the west.\n";
   set_light(1);
   store = "/room/main_store";
   keeper = "Sleepy";

  items = ({"walls","The walls are made of red bricks",
            "desk","It's a wooden desk",
            "sign","The sign says: Type list please !"
            });

  dest_dir = ({ "/players/misticalla/guild/rooms/courtyard2","west",
           "/players/misticalla/guild/rooms/meeting","south" });


}

query_property(arg) 
{
   return arg=="no_fight";
}
