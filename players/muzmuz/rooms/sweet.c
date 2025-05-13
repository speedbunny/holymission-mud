inherit "room/room";

reset(arg) { ::reset(arg);
    if(!arg) {
        set_light(1);

        short_desc="Honeymoonsuite ", 
        long_desc=
            "This is the Honeymoonsweet of XXXX and YYYY.\n"+ 
	    "When you enter the room, you are captured by the romantic\n"+
            "impression you get. You look at the romantic bed and at the\n"+
            "combftable furnitur and you feel home.\n"+
            "You can see some soft pillows on the bed and when you are\n"+ 
            "very quite you can hear the sweet sound of the fire in the\n"+
            "chimney.\n";
 
        dest_dir=({
            "players/muzmuz/rooms/rom", "exit",
                 });

        items=({ 
            "air","It`s very sweet",
            "floor","The floor looks very clean\n", 
            "bed","You see a large bed with some pillows on it\n"+
            "You think it would be wonderful to sleep in it\n",
            "pillows","There are some soft pillows, but one is heart shaped\n",
            "heart shaped pillow","There is a small opening in it\n",
            "heart pillow","There is a small opening in it\n",
            "opening","You get a card\n",
            "card","On the card is written: Happy honeymoon !!!! \n",
            "under bed","You find a lil present box\n",
            "box","In there is a neat silk nightdress\n",
            "nightdress","Its very sexy but also very suitable\n",
 
              });
        property = ({
                     "no_teleport","no_sneak","no_steal",
                    });
        smell = "You have the smell of aples in your nose.";


    }
}

init()
{
  ::init();
}
