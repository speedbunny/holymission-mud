inherit "room/room";
reset(arg) {
  if(!arg) {

     short_desc = "Demon hallway";
     long_desc = "This is the dining room of the demons.\n" +
                 "It is still pretty clean here.  There is a little\n" +
                 "bit of food on the floor, and the table is pretty messy,\n" +
                 "but nothing like you'd expect from these demons.\n" +
                 "For some reason these demons must keep it clean back\n" +
                 "here.\n" +
                 "There is a small doorway to the south and another one\n" +
                 "to the southwest.\n";

      dest_dir = ({"players/topaz/rooms/demons/cave10","north",
                   "players/topaz/rooms/demons/cave12","southwest",
                   "players/topaz/rooms/demons/cave13","south",
 
                     });

     items =({"cave","What a scary cave",
              });
       set_light (1);
return 1; }}
