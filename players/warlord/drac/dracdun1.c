

inherit "room/room";
int is_open,is_locked;  /* better than one var */

reset(arg) {

    is_open=0; /* for not open */
    is_locked=1; /* for locked */
    if (arg) return;

    
    set_light(0);
    short_desc = "Dark room";
    long_desc = 
        "By the looks of it , this was a well used dungeon.\n"
        + "There is blood all over the floor and a pile of bones..\n"
        + "It is very dark in here, but you can see a grate on the floor.\n";
     items=({
     "grate","You see a @@query_grate@@", /* is a cool way to descripe changing items */
     "blood","The blood is deep red and fresh",
     "bones","The bones look to be from a small creature, probably a dwarf",
     "floor","The floor is covered in blood. Under the blood you can barely make out a grate",
     });
    
   dest_dir=({"players/warlord/drac/drachall1","east",});
return 1;
    } /* hehe */
   
/*
init () {
::init();
add_action("open","open");
add_action("close","close");
add_action("down","down");
add_action("down","grate");
add_action("unlock","unlock");
add_action("lock","lock");
}

down() {
 if (is_open) {
    this_player()->move_player("down#players/warlord/tunnel/tun1");
     }
 else {
    write("You bang your head against a closed grate.\n");
    return 1;
    }
  return 1;
  }
  
open (str) {
  if ((str=="grate")||(str=="the grate")) {
  
    if (is_locked)  {
      write("You can not open grate it is locked.\n");
      return 1;
      }
      
    else if (is_open) {
      write("The grate is already open.\n");
      return 1;
      }
      
    else {
      write("You open the grate.\n");
      is_open=1;  /* now it's open */
      return 1;
      }
   }
  
  else {
      write("You can't open that.\n");
      return 1;
       }
   return 1;
}

close(str) {
  if ((str=="grate")||(str=="the grate")) {
  
    if (is_locked)  {
      write("You can't close a locked grate.\n");
      return 1;
      }
      
    else if (!is_open) {
      write("The grate is already closed.\n");
      return 1;
      }
      
    else {
      write("You close the grate.\n");
      is_open=0;  /* now it's closed */
      return 1;
      }
   }
  
  else {
      write("You can't close that.\n");
      return 1;
       }
   return 1;
}


unlock(str) {
      if (str=="grate" || str=="the grate") {
        write("Unlock grate with what?\n");
        return 1;
        }
      if (str=="grate with key" || str=="the grate with key" || str=="grate with small key" || str=="the grate with small key") {
      
       if (present("small key",this_player())) {
       
            if (!is_locked) {   /* if unlocked */
               write("But the grate is already unlocked.\n");
               return 1;
               }
            else {
            write("You have unlocked the grate.\n");
            is_locked=0;
            return 1;
              }
           }   
         else {
              write("You do not have the proper key.\n");
              return 1;
              }
        }
      else {
         write("What do you want to unlock?\n");
         return 1;
         }
     return 1;
    }
    
  lock(str) {
      if (str=="grate" || str=="the grate") {
        write("lock grate with what?\n");
        return 1;
        }
      if (str=="grate with key" || str=="the grate with key" || str=="grate with  small key" || str=="the grate with small key") {
      
       if (present("small key",this_player())) {
       
            if (is_locked) {   /* if locked */
               write("But the grate is already locked.\n");
               return 1;
               }
            else if (is_open) {  /* if it's open */
               write("You can't lock an open door.\n");
               }
               
            else {
            write("You have locked the grate.\n");
            is_locked=1;
            return 1;
              }
           }   
         else {
              write("You do not have the proper key.\n");
              return 1;
              }
        }
      else {
         write("What do you want to lock?\n");
         return 1;
         }
     return 1;
    }
    
    
    
query_grate(str) {

   if (!is_open) { 
    return str="grate it is made of iron and is closed";
    }   
    else {
    return str="grate it is made of iron and is opened";
   }
 }

 query_open() { /* we need this for the partner door */
   if (is_open) return 1;
   else
     return;
     }
*/
