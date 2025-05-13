inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

    short_desc = "hill";
     long_desc = "You are standing on a hill. To the south you can see the anchoring place.\n" +
                 "To the north there are the dunes. The bay looks very nice from here.\n";

        items = ({"anchoring place","A little jetty where boats can anchore",
                  "dunes","Huge dunes, covered with sand",
                  "sand","White sand",
                  "bay","A nice bay with an anchoring place"});
     dest_dir = ({
                  "players/muzmuz/island/rooms/ch","west",
                  "players/muzmuz/island/rooms/eh","east",
                   });
    set_light(1); 
    }
}
