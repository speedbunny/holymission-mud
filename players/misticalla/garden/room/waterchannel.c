 
 
inherit "room/room";
 
reset(arg) {
    if (arg) return;
 
    set_light(0);
    property = "no_teleport";
   short_desc = "On a waterchannel";
    no_castle_flag = 0;
    long_desc = 
       "You are hanging on the waterchannel of the strange building. "+
       "It is cold and wet here. If you look down you see the outline "+
       "of a big wooden door. If you gaze up you see the outline "+
       "of the big roof. You recognize that the smell of the "+
       "gingerbread is getting stronger and you start to feel "+
       "very hungry.\n";
    dest_dir = 
        ({
        "/players/whisky/garden/room/house1", "down",
       "/players/whisky/garden/room/roof", "up",
        });
items = ({"roof","You can see a big black shingle roof",
          "waterchannel","You see a metal black painted waterchannel",
         "door", "You see the contours of a big wooden door",
        "building","You see only red bricks."});
}
