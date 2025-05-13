inherit "room/room";
object monster;

reset(arg) {

   ::reset(arg);
   
   if(!monster) {
      monster=clone_object("/players/stanley/mobs/troll");
      move_object(monster,this_object());
   }

   if(arg) return;
   set_light(0);
   short_desc="Under the bridge";
   long_desc=
   "You feel extremely uneasy here under the bridge. The light is dim, and\n" +
   "your footing is unsure. Perhaps you should think about not staying here?\n" +
   "There is a small sign.\n";
   
   dest_dir=({
   "/players/stanley/room/stream/stream1","out",
   });

   items=({
   "bridge","Simply the underside of a bridge",
   "stream","The stream runs to the south. The water looks slightly muddy",
   "sign","You see a perfect opportunity for you to practice your reading skills",
   });
}

init(str) {
   ::init();
   add_action("out","out");
   add_action("read","read");
}

out(str) {
   if(present("troll",this_object())) {
      write("The troll won't let you by!!!\n");
      return 1;
   }
   return 0;
}

read(str) {
   if(!str) return 0;
   if(str=="sign") {
      write(
      "You peer at the sign. The light in the room is dim, and you have to squint,\n" +
      "but after a moment you can make it out...\n\n" +
      "I TRIED TO WARN YOU!!!\n");        
      return 1;
   }
   return 0;
}
