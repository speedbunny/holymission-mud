inherit "room/room";
query_no_teleport() { return 1; }
reset(arg) {
    if (arg) return;

    set_light(0);
    short_desc = "Hole";
    no_castle_flag = 1;
    long_desc=
             "You are in the remains of the hole you dug a while ago.\n"+
             "It's dark and smelly.\n";
    dest_dir = ({ "players/dice/quest/q7","out"
      });
          items = ({
                     "hole","The remains of the hole you once dug",
              });

    smell = "This place smells like ashes, sulpher, and old earth.";
}
init(){  
    ::init(); 
   add_action("dig","dig");
 }
dig(str){
 if(!str){
  notify_fail("Dig where ?\n");
  return 0;
  }
if(str=="down"){
   write("You dig down, and fall out of the hole again.\n");
   this_player()->move_player("down#players/dice/quest/q7");
   return 1;
   }
if(str=="up"){
    write("You dig up, and climb out of the hole.\n");
    this_player()->move_player("up#players/dice/quest/q6");
    return 1;
    }
  }
