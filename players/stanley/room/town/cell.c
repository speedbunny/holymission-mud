inherit "room/room";
int counter, lock, sink;
string room_1, room_2;
object water_bucket;
reset(arg) {
   counter=0; lock=0; sink=0;
   set_no_obvious_exits(1);
   set_light(1);
   short_desc="In Jail";

   room_1=
      "You look around and see that you are in a jail cell. It's not a bad jail cell,\n"
      + "as jail cells go, but all the same, you think you'd rather be someplace else.\n"
      + "On the other side of the bars you see a wooden desk with a small chair behind\n"
      + "it, plainly out of reach. There is a cot, a sink, and small board with a hole\n"
      + "in it covering what you guess is a small well in the corner.\n";

   room_2="The Jailor stands outside waiting for you to leave the cell.\n"
        + "\n    There is one obvious exit: out\n";

   long_desc=room_1;

dest_dir= ({
   "/wiz/belboz/room/town/jail","out",
   });

items= ({
   "jailor",
      "There is no jailor here",
   "man",
      "There is no man here",
   "desk",
      "A wooden desk, clear of everything except the scuffs from someone's feet",
   "chair",
      "A small wooden chair of the kind commonly sat in",
   "cot",
      "It is a small, comfortable cot, still messy from you sleeping in it",
   "sink",
      "There is a faucet in the sink",
   "faucet",
      "The faucet is off",
   "well",
      "It has a board with a hole cut in it laying across the top.\n" 
      + "The board rests about knee level",
   "bars",
      "The bars of the cell are locked tightly closed. You are filled with\n" +
      "a severe feeling of claustrophobia, and have the sudden urge to yell!" +
      "\nPanic sets in as you try to cope with your incarceration",
   "board",
      "The board sits on top of the well in the corner. It looks well worn.\n"
      + "A rancorous odor wafts up at you from within the hole in the board",
   "hole",
      "Inspiration strikes you, making you realize that you would rather not\n" 
      + "examine the hole too closely",
   });
}

init(arg) {
   ::init();
   add_action("faucet","turn");
   add_action("_search","search");
   add_action("escape","out");
   add_action("yell","shout");
   add_action("yell","yell");
   add_action("yell","scream");
   add_action("_hole","enter");
   add_action("_use","use");
   if(lock==0) call_out("imprison",3);
}

faucet(str) {
   if(!str) { write("Turn what?\n"); return 1; }
   if (sink==0) {
      if (str=="faucet" || str=="on faucet" || str=="faucet on") {
         write("You turn the faucet, and water starts to flow into the sink.\n");
         items[11]="There is a faucet with water running from it in the sink";
         items[13]="There is water running from the faucet";
         sink=1;
         return 1;
      }
   }
   if(sink==1) {
      if(str=="faucet" || str=="faucet off" || str=="off faucet") {
         write("You turn off the faucet. Water stops flowing into the sink.\n");
         sink=0;
         items[11]="There is a faucet in the sink";
         items[13]="The faucet is off";
         return 1;
      }
   }
   return 0;
}

water_source() { if(sink==1) return 1; }

escape(str) {
   if(str) {
      write("That makes no sense!\n");
      return 1;
   }
   if(lock==1) {
      write("You cannot open the cell door!  It is locked!\n");
      return 1;
   }
   return 0;
}

yell(str) {
   if(lock=1) {
      if(find_call_out("delay")==-1) {
         call_out("delay",2);
         call_out("delay",5);
         call_out("delay",8);
         call_out("delay",11);
         call_out("delay",14);
         return 1;
      }
      write("Your throat is sore from so much yelling.\n");
      return 1;
   }
   return 0;
}

delay() {
   counter++;
   if(counter==1) {
      tell_room(environment(this_player()),"  \"What? What's that?\"\n\n");
      return 1;
   }
   if(counter==2) {
      tell_room(environment(this_player()),
      "You hear keys jangling, and a moment later, a thin older man comes rushing\n" +
      "in and starts trying to unlock the cell.\n\n");
      return 1;
   }
   if(counter==3) {
      tell_room("/wiz/belboz/room/town/cell",
      "  \"Young people today! Always rushing about and gettin' themselves in trouble!\"\n" +
      "The key clicks home and the man fumbles with the cell door trying to open it.\n\n");
   }
   if(counter==4) {
      tell_room(environment(this_player()),
      "  \"Listen, you! You gotta be more careful around this place!\"\n" +
      "The man, whom you presume to be the jailor, opens the cell door for you.\n");
      return 1;
   }
   if(counter==5) {
      tell_room(environment(this_player()),
      "\n  \"I know I need to get that durn thing fixed someday!\"\n" +
      "\nThe Jailor holds the cell door open for you to leave.\n" +
      "The cell door is now open.\n" +
      ">");
      items[1]=
      "A thin, gangly old man who seems rather embarrassed.\nJailor is in good shape.\n" +
      "       Jailor is carrying:\nA rickety blunderbuss.\nA ring of keys";
      items[2]=
      "A thin, gangly old man who seems rather embarrassed.\nJailor is in good shape.\n" +
      "       Jailor is carrying:\nA rickety blunderbuss.\nA ring of keys";
      counter=0;
      lock=0;
      long_desc=room_1+room_2;
      return 1;
   }
}

_hole(str) {
   write("You decide you'd rather die than enter the hole.\n");
   return 1;
} 

imprison() {
   tell_room(this_object(),"\nAn old thin man says, \"Guess I'll go check on the Bakery..." +
   "be careful comin'\nand goin' into that cell!\"\n\nThe Jailor leaves to the east.\n\n");
   tell_room(this_object(),
   "*CLICK!*\nThe door swings shut with a low squeal.\n");
   lock=1;
   return 1;
}
  
check(arg) {
   return lock;
}

_use(str) {
   if (str != "well") return 0;
   this_player()->empty_bladder();
   write("You add to the atmosphere inside the well.\nYou feel relieved.\n");
   return 1;
}

_search(str) {
   if(!str) {
      write("Search what?\n");
      return 1;
   }
   if(str=="desk") {
      write("You cannot reach the desk from here.\n");
      return 1;
   }
   if(str=="cot") {
      write("You find a couple of hairs from your head. You reluctantly let them go.\n");
      return 1;
   }
   if(str=="chair") {
      write("You cannot reach the chair from here.\n");
      return 1;
   }
   if(str=="hole") {
      write("Inspiration strikes you, making you realize that you would rather not\n" +
      "examine the hole too closely.\n");
      return 1;
   }
   return 0;
}
