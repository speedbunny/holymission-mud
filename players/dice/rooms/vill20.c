

inherit "room/room";


reset(arg){::reset(arg);
   if(!arg){

 if (arg) return;

   set_light(1);
   no_castle_flag = 1;

   short_desc = "Transportation room";
   long_desc =
     "You are in the transportation room.\n"+
     "This is really a weird place, coals are laying all around.\n"+
     "And the smell of ozone is really strong. \n"+
     "No sound can be heard all over the place. \n"+
     "But three buttons are set into the wall, \n"+
     "and they are made of some kind of weird metal. \n";


   dest_dir = ({
      "players/dice/rooms/vill19","north",
       });

   items =({
           "buttons","Which buttons, there are 3 ?",
           "button 1","A button made out of pure mithril",
           "button","Which button, there are three ?",
           "button 2","A button made out of stainless chromed steel",
           "button 3","A button made of ordinary iron",
           "metal","A weird sort of metal, examine the buttons for more",
           "sound","I already told you... THERE IS NO SOUND",
           "ozone","A weird kind of gas",
           "coals","just normal coals"
            });

}
  smell = "The smell of ozone is very strong here. \n";
 }

init() { ::init(); add_action("push","press");
                   add_action("push","push"); }
push(str) {
  if(str=="button") {
    write("Which button, 1, 2, or 3 ??\n");
    return 1;                               }
  if((str=="button 1")||(str=="first button")||(str=="button one")){
    write("You push button 1, and a voice tells you, BAD CHOICE.\n\n\n"+
          "REALLY BAD CHOICE !!!! MUUAHAHAHAHA... \n\n\n"+
          "You are magically transferred somewhere, but it doesn't look good.\n");
    this_player()->move_player("through the wall#players/dice/rooms/vill50");
    return 1;
  }
  if((str=="button 2")||(str=="second button")||(str=="button two")){
    write("You push button 2, and a voice tells you, ANOTHER BAD CHOICE.\n\n\n"+
          "You are magically transferred somewhere, but it doesn't look good.\n");
    this_player()->move_player("through the wall#players/dice/rooms/vill52");
    return 1;
  }
  if((str=="button 3")||(str=="button three")||(str=="third button")){
    write("You push button 3, and a voice tells you, YOU'VE CHOSEN WISELY .\n\n\n"+
          "You are magically transferred somewhere, but this looks good.\n");
    this_player()->move_player("through the wall#players/dice/rooms/vill51");
    return 1;
  }
}
