inherit "room/room";
reset(arg) {
 if (!arg) {::reset(arg);

     short_desc ="hills";
      long_desc ="Standing on the top of the hill you see the dunes to the north. To the west\n" +
                 "there are more hills. To the east and to the south you can see the path,\n" +
                 "but the steepness of the hill in those directions doesn`t allow you to go \n" +
                 "there directly.\n" ;

       dest_dir = ({"players/muzmuz/island/rooms/hg","north",
                    "players/muzmuz/island/rooms/gh","west",
                           });
       items = ({"dunes","Huge dunes, covered with sand",
                 "path","A stony path",
                 "hills","Many little hills",
                             });
set_light (1);
return 1; }}
