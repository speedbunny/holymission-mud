inherit "room/room";

reset(arg) 
  {clone_list=({1,1,"board","obj/board",
   ({"set_file","players/sarge/travel/bull",
   "set_name","bulletin"})});
  set_light(1);
  short_desc="The Holy Mission Travel Bureau";
  long_desc=
   "Visions of far distant lands, and exotic places fill your head, "+
   "while you get an almost overwhelming desire to travel.\n\n"+
   "If you are taking a trip, or you have a spare bed, or just " +
   "don't mind having some mudders visit you, you can post here.  "+
   "You've mudded with them, why not meet them?\n";
   dest_dir=({"players/cashimor/extend/village1","south"});
   ::reset(arg);
   replace_program("room/room");}
