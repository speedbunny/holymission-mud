inherit "room/room";

void reset(int arg) 
{
  if(!arg) 
  {

    short_desc = "anchoring place";
     long_desc = "This is the anchoring place. You can see a landing stage. To the north you\n" +
                 "can see a little hill. There is a path leading to the east. You see the\n" +
                 "wonderful bay to the west and you decide to call it a romantic place.\n";

        items = ({"stage","A stage made of wood",
                  "ocean","The ocean seems to be lifeless",
                  "hill","A little hill",
                  "path","A stony path"});
    dest_dir = ({
                 "players/muzmuz/island/rooms/dj","south",
                 "players/muzmuz/island/rooms/landing","stage",
                 "players/muzmuz/island/rooms/ei","east",
                    });

     set_light (1); 
     }
}
