inherit "room/room";
object owner2;
reset(arg) {
    if (arg) return;
    property = ({"no_fight", "no_teleport"});
    if(!owner2){
      owner2=clone_object("players/dice/quest/owner2");
      move_object(owner2,this_object());
      }

    set_light(1);
    short_desc = "Back of house";
    no_castle_flag = 1;
    no_obvious_msg="";
    long_desc=
              "You are standing at the back of the house.\n"+
              "The crack was just wide enough to wiggle yourself through.\n"+
              "and seems to be happy that he got out.\n"+
              "A small pit is in the backyard.\n";
          items = ({
                    "house","A small house",
                    "crack","The crack you came through",
                    "backyard","A small backyard where vegetables are growing",
                    "pit","A small dark pit",
              });

    smell = "The air smells fresh here.";
}
init(){  
    ::init(); 
  add_action("enter","enter");
 }
enter(str){
  if(!str){
    notify_fail("Enter what ?\n");
    return 0;
    }
if(str=="house"){
       if(owner2){
    write("You attempt to enter the house.\n"+
          "The owner says: I'm not ungrateful, but leave my house please.\n");
    return 1;
    }
   else{
   write("You enter the house.\n");
   this_player()->move_player("into the house#players/dice/quest/q11");
   return 1;
   }
  }
if(str=="crack"){
    write("You wiggle yourself through the crack again.\n");
    this_player()->move_player("into the crack#players/dice/quest/q13.c");
    return 1;
    }
if(str=="pit"){
   write("You close your eyes, and jump into the pit.\n");
 this_player()->move_player("into the pit#players/dice/quest/pit");
  this_player()->set_quest("earth_quest");
log_file("dice.quest", ctime(time()) + ": " + this_player()->query_real_name() + " (level " + this_player()->query_level() + ") (" + capitalize(this_player()->query_real_name()) + ") \n" + " freed the owner of the house.\n");
 this_player()->add_money(2000);
   call_out("jump_into_pit",1);
   call_out("jump_into_pit",2);
   call_out("jump_into_pit",3);
   call_out("jump_into_pit",4);
   call_out("jump_into_pit",5);
   call_out("end_pit",6);
   return 1;
   }
 }

jump_into_pit() {
   write("You are falling into the pit !!! \n\n\n\n");
return;
}
end_pit() {
   write("Suddenly you get the idea you are not falling anymore.\n\n\n"+
         "And get the idea that you are somewhere familiar.\n");
   say(this_player()->query_name() + " steps into the pit.\n");
   tell_room("/room/church", this_player()->query_name() + " steps out of a"+
             " black hole.\n");
    move_object(this_player(), "room/church");
   return;
}
