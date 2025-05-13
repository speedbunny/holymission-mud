inherit "room/room";
   object man;

  reset(arg) {
  
    if(!man) {
      man=clone_object("players/misticalla/guild/monsters/eman");
      move_object(man,this_object());
    }
   
   if (arg) return;
  
   set_light(1);
   short_desc= "Monk Engagement Chapel";
   long_desc=
         "Passing through the archway you see a beautiful "+
         "altar against one wall which is deocrated in flowers. "+
         "Candles light the room in a soft glow. "+
         "You and your sweetheart can be engaged here in a "+
         "southern room of the abbey. To the east is "+
         "a meeting room where monks congregate, and the "+
         "courtyard lies to the north.\n";
     
    
   items = ({
          "flowers","They are fresh and smell beautiful",
          "candles","Long and slender candles light the room",
          "altar","A beautiful altar with flowers",
           });
            
   dest_dir = ({
         "players/misticalla/guild/rooms/courtyard2","north",
         "players/misticalla/guild/rooms/entrance","west",
         "players/misticalla/guild/rooms/meeting","east",
               });

}
init() {
    ::init();
    add_action("check_move","north");
    add_action("check_move","east");
}
 
check_move() {
    if (this_player()->query_guild() !=7) {
        write("That room is for monk guild members only!!!\n");
        say(this_player()->query_name()+" tried to go "+query_verb()+"!\n");
        return 1;
    }
    else { return 0; }
}
 

       
    
