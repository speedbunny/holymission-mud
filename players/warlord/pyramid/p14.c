inherit"room/room";
   int i;
   
 reset (arg) {
   i=0;
   
if (arg) return;
  set_light(1);
  short_desc="Tomb room\n";
  long_desc="This is the Mummy tomb room. You see a well decorated room.\n"+
            "You see a large sarcophagus in the corner standing upright.\n";
            
items=({
    "sarcophagus","The sarcophagus looks very old. You notice a small crack in the\n" +
    "side of it. Maybe you can open it",
    "crack","Maybe you can open it because of the crack in the side",
});

dest_dir=({
"players/warlord/pyramid/p10","downnorthwest",
"players/warlord/pyramid/p11","downnortheast",
"players/warlord/pyramid/p12","downsouthwest",
"players/warlord/pyramid/p13","downsoutheast",
});

}
init () {
add_action("open","open");
::init();
}

open(arg) {
  object ob;
  ob=present("Phychor",this_object());  /* if the monster is present */
  
  if ((arg!="the sarcophagus") && (arg!="sarcophagus")) return;
                                       /* stops the function if the wrong arg */
  
  if (i<1) {
   move_object(clone_object("players/warlord/pyramid/phychor"),this_object());
   i++;
   write("Out from the sarcophagus comes an ancient mummy.\n");
   say("Out from the sarcophagus comes an ancient mummy.\n");
   }
   
   else {  
     write("You find nothing in the sarcophagus.\n"); 
   return 1;                           /* if the function is finished */
   }
 return 1;
}

