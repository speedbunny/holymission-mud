inherit "/room/room";

#include "/players/matt/defs.h"

reset(arg) {
  if(arg) return;
  set_light(1);
  short_desc = "Mountain Road";
  long_desc =
    "    You are standing in a wide-open section of the mountain\n" +
    "road. Pine trees grow in clusters here, their branches heavy\n" +
    "with sparkling snow, and a frozen pond catches the light of\n" +
    "the sun, dazzling you with its brilliance. Though it is\n" +
    "still extremely cold here, there is no wind at all and it is\n" +
    "completely silent.\n" +
    "    The beauty of the scene before you is overwhelming. You\n" +
    "are utterly awestruck.\n";  

  dest_dir = ({
    NWROAD + "rooms/road22", "northeast",
    NWROAD + "rooms/road20", "south",
  });

  items = ({
    "road", "The road is very broad here, and covered with snow",
    "trees", "Tall snowy pines standing silently still",
    "pond", "A rather large pond covered with a layer of ice",
    "sun", "DAMN! You just really messed up your eyes",
    "scene", "This is the most beautiful you have seen in the area",
  });
  replace_program("/room/room");
}
