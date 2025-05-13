inherit "room/room";
 
reset(arg) {
object skull;
 
  ::reset(arg);
  if(!arg) {
    set_light(1);
    short_desc="Prison";
    long_desc=
"This is prison.  You are trapped in a dark and lonely cavern.  The "+ 
"exit is blocked by strong, thick, wrought-iron bars.  Only a pale and "+
"waning light originating from somewhere far beyond the bars illuminates "+ 
"your dreary surroundings.  The walls are covered with blood from where "+ 
"former prisoners tried to claw their way out.  There are bones scattered "+ 
"on the cavern floor.  You gaze upwards and notice two yellow and silent "+
"blinking eyes staring into your soul, just as you were wondering how those "+
"bones became so bare of flesh."+
"   \n";
    
dest_dir=({"/room/church","iwillbegood"});

    no_obvious_msg="";
    property=({"no_teleport"});
    smell="The smell of decay hangs in the air.";
    if(!present("skull",this_object())) {
      skull=clone_object("obj/treasure");
      skull->set_name("skull");
      skull->set_id("skull");
      skull->set_short("A skull.");
      skull->set_long("A former prisoner's skull. He will tell your fate.\n");
      skull->set_weight(1000);
      skull->set_value(0);
//      skull->"load_a_chat", 50, get_chats());
//              n = random(3);

      move_object(skull,this_object());
 
//get_chats() {
//    if (!chats) {
//        chats = allocate(3);
//        chats[0] = "Skull says: You will rot here.\n";
//        chats[1] = "Skull says: I was once an annoying player like you.\n";
//        chats[2] = "Skull regrets what he did.\n";
//    }
//    return chats;
//}


   }    
  }
}
 
init() {
    ::init();
    add_action("van","vanish");
    add_action("quit","goback");
    add_action("quit","goguild");
    add_action("quit","quo_vadis");
    add_action("stronghold","stronghold");
    add_action("shout_it","shout");
    add_action("tell_it","tell");
    add_action("quit","quit");
    add_action("try_prison", "prison");
}
 
quit() { return 1; }
stronghold() { return 1; }
van(str) {return 1;}
try_prison(str) { return 1; }  /* no escape through mage prison! */
shout_it() { return 1; }
 
tell_it(str) {
string tmp;
object who;
 
  if(!str) {
    write("Tell what?\n");
    return 1;
  }
  tmp=explode(str," ");
  who=find_player(tmp[0]);
  if(!who) {
    write("Tell who?\n");
    return 1;
  }
  if(!(who->query_immortal())) {
    write("You can only tell to wizards now!\n");
    return 1;
  }
  return 0;
}
