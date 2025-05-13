inherit "room/room";
reset(arg) {
  if(!arg) {

     short_desc = "Demon hallway";

     long_desc = "You step into the brightly lit hallway.\n" +
                "Everything is sparkling clean!  Wow!  You never thought that\n" +
                 "the demons would have someplace like this!  This place\n" +
                 "is nice enough that you start to relax.  Maybe these demons\n" +
                 "aren't so bad after all.  Then you notice the statues and\n" +
                 "murals.  They're disgusting!  They depict horrible deeds\n" +
                 "and beastly monsters.  You think you might be sick.\n" +
                 "The hallway continues to the south while a small alcove\n" +
                 "is to the east.\n";
      dest_dir = ({"players/topaz/rooms/demons/cave9","north",
                   "players/topaz/rooms/demons/cave11","south",
                   "players/topaz/rooms/demons/cave14","east",
 
                     });

     items =({"hall","A well lit hallway",
              "hallway","A well lit hallway",
              "statue","An ugly beast ripping apart a human child",
              "statues","They show various cruel and sickening acts",
              "mural","A big picture of a demon drinking blood",
              "murals","Big pictures showing disgusting things",
              "alcove","Hmm...could be interesting in there",
              "everything","Sparkling clean!  You could eat off the floor",
              "floor","You really wouldn't mind eating off this floor",
              });
       set_light (1);
       smell = "It even smells clean here.";
return 1; }}
