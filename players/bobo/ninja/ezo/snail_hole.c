inherit "/room/room";
void reset(int flag) {
   if(!present("snail",this_object())) {
        move_object(clone_object("/players/tatsuo/npc/snail"),
        this_object());
    }
    ::reset(flag);
   if(flag==0) {
      set_light(1);
      short_desc = "In the Snail Hole";
      long_desc =
	"You have entered a big, wet hole. The walls are made of wet\n"+
	"earth and the bottom is covered with wet, freen moss. To the\n"+
	"north you can recognize a little cave in where you can see\n"+
	"something glittering.\n";
      dest_dir=({
        "/players/tatsuo/ezo/snail_hole2","north",
	"/players/tatsuo/ezo/meadow32","up",
      });
      items=({
         "walls","The walls are wet and earthy",
         "moss","Green wet moss",
       });
   }
}

status move(string arg) {
   object snail;
   snail = present("giantic snail",this_object());
   if(!arg)
       arg = query_verb();
   if(arg=="north" && snail && living(snail)) {
       write("But the Giantic Snail blocks your way !\n");
       return 1;
   }
   return ::move(arg);
}
