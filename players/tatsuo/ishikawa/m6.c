inherit "room/room";
int i;
reset (arg) {
set_light(1);
   short_desc="At the top";
   long_desc="As you look around, you see a breath-taking view of Hilo and distant"+
      " Holy Mission.  A grove of trees is off to the left.\n";
   dest_dir=({
     "/players/tatsuo/ishikawa/m5","down",
     "players/tatsuo/guild/garden1","north",
   });
   items=({
      "mountain","A barely climbable mountain",
      "trail","There is no longer any thing around that even remotely resembles a trail...better hope you don't get lost",
   "view","This is the most beautiful view you have ever seen",
      "view","The view is breath-taking!",
      "Hilo","The kender capital; it is far off in the distance",
      "Holy Mission","Home looks VERY far away!",
   });
}
   init(){
   ::init();
   add_action("_climb","climb");
   add_action("_search","search");
   add_action("leave","enter");
}
   _climb(str){
   if(!str){
    notify_fail("Climb what ?\n");
   return 0;
}
   if(str =="up"){
   write("You cannot climb any higher.\n");
   return 1;
}
   if(str=="down"||str=="mountain"){
   write("You climb down Mt. Kender carefully.\n");
   this_player()->move_player("down#players/exos/mountain/mountain4");
   return 1;
}
}
   _search(str) {
   if(!str){
      notify_fail("Search what ?\n");
   return 0;
   }
   if(str =="mountain"){
   write ("There is a small crack leading down into the mountain.\n");
   return 1;
   }
}

   leave(str) {
   if (!str || str!="crack") return 0;
   write ("You slide into the crack.\n");
   this_player()->move_player("disappears#players/exos/rifts/cave1");
   return 1;
}
