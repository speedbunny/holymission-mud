inherit "room/room";
reset(arg) {
  if(!arg) {

    short_desc = "most romantic place";
   long_desc ="This is the most romantic place you have ever seen. The air is warm and you\n" +
              "can feel a slight breeze. The moon shines brightly from above. You are \n " +   
              "standing in the white sand and you can hear the sea. Behind you is a bar.\n" +
              "You can hear the tender music which is played there and you feel you want to\n" +
              "dance. There are some shells in the sand and some wood you could use to light\n" +
              "a romantic fire. Athough the moon shines brightly you can see many stars and \n" +
              "if you wait some time, you will see some shooting stars.\n" ;
      dest_dir = ({"players/muzmuz/workroom","leave",
                   "players/muzmuz/rooms/sweet","honeymoon",
                        });

set_light (1);
property = ({"no_teleport"});
return 1;}}
