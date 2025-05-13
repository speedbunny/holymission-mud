inherit "room/room";
reset(arg) { 
    if (arg) return;
 
    set_light(1);
    short_desc = "Fire portal. ";
    long_desc =
    "You stand before the entrance to the realm of the fire elementals. The\n"+
    "portal is an unquenchable furnace of fire that threatens you roast you\n"+
    "even though you stand a considerable distance away. The sheer power of\n"+
    "this place is just incredible. You already feel faint from the heat and\n"+
    "you realize that to step through the portal without any protection is to\n"+
    "invite death.\n";
 
    items=({
      "portal", "The portal is so hot it threatens to roast you on the spot and is\n"+
      "the sentinel of the fire elementals against intruders who wish to enter\n"+
      "their realm, if you had protection may be you could enter",
    });
 
 
    dest_dir = ({
      "players/alex/quest/4","north",
    });
 
}
init() {
    add_action("enter","enter");
    ::init();
}
                                                                                 
enter (str) {
    string thing;
 
    if(!str)
                 {
        notify_fail("Enter what?\n");
        return 0;
                 }
 
    if (str != "portal") {
        write("Enter what??\n");
        return 1;
                         }
    if ((present("alex_diamond",this_player())) && (present("alex_opal",this_player()))&& (present("alex_pearl",this_player())))  {
 
 
        write(
          "As you step into the portal the heat is so great that you think\n"+
          "the flesh is being roasted from your bones, but then the diamond\n"+
          "glows and a small peace of ground forms beneath you shielding\n"+
          "your feet and alowing you to walk on the fire.\n"+
          "The opal gives out a bright light a bubble of air forms to let\n"+
          "you breathe and pearl starts to vibrate giving of a cold shower\n"+
          "within the bubble to keep you cool.");
        this_player()->move_player("enters portal#/players/alex/quest/fire7");
        return 1;
                                                                                }
    else {                                                                       
        write("You try to enter the portal but the flames beat you back.\n");
        return 1;
         }
 
          }
        
