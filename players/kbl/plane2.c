/* Top of a rise on the plane, 2 squares west of pryamid
   one square = 3.26 miles */

inherit "room/room";

reset(arg)
{
  ::reset(arg);
  if(!arg)
  {
    set_light(2);
    short_desc = "Middle of the planes on a slight rise";
    long_desc = "The endless planes seem to stretch in all directions.\n"+
                "South you see rugged mountains bordering the planes and\n"+
                "north the planes seem to stretch out to infinity. East\n"+
                "you see a rather large pryamid. Small structures surround\n"+
                "it. There seems to be some activity going on. Smoke rises\n"+
                "from the middle of these structures and screeching noises\n"+
                "can be heard coming from the the direction of that area.\n"+
                "The path your on goes east and west, even tho the planes\n"+
                "are flat and you think you should be able to walk north\n"+
                "or south or any direction here.\n";
    dest_dir = ({"players/kbl/plane3","east",
                 "players/kbl/plane1","west"});
    smell = "Dry grass and dust greet your nose";
    items = ({"planes","Dry brownish green grass is all there seems to be\n"+
                       "on the planes. It is flat as far as you can see north",
              "mountains","A chain of mountains going east/west. The peaks\n"+
                          "are less covered with what looks like snow towards\n"+
                          "the eastern stretch of the mountains",
              "pyramid","Standing on this slight rise in the plane, you can\n"+
                        "see the pyramid is still almost 6k meters away.\n"+
                        "Even so, you think you see some activity in the\n"+
                        "structures surrounding the pyramid",
              "structures","Can't tell too much from here",
              "smoke","Looks to be coming from the center of the village",
              "village","The village is on the west side of the pyramid only",
              "path","Very well used and has many bearfoot prints in the\n"+
                     "soft reddish clay of the path",
              "prints","Four toed prints, very interesting... bearfoot",
              "bearfoot prints","They are from some humanoid type. They\n"+
                                "almost look elfish",
              "peaks","You can't tell much detail from here"});
    property = "no_hide","no_sneak";
  }
}

init()
{
  ::init();
}
