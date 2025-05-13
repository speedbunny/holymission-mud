inherit "room/room";
reset (arg) {
if (arg) return;
set_light(3);
short_desc = "North hall...c12...goblin guard";
long_desc =  
 "A long hallway in the east and west direction.\n"
+ "There is a white carpet on the floor.\n"
+  "There is a small window in the north wall.\n";
items = ({
 "floor","It is made of red stone",
 "ceiling","It is made of white stone",
 "wall","A grey stone wall with a small window in it",
 "window","You can see the stables behind the castle",
 "carpet","A beautiful white carpet",
});

dest_dir = ({
  "players/jake/goblin/castle/c11","east",
  "players/jake/goblin/castle/c13","west",
});
clone_list = ({
 1,1,"goblin","players/jake/goblin/castle/monsters/goblin.c",0
});

::reset();
 replace_program("room/room");
}
