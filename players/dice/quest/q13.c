inherit "room/room";

object owner; status has_widened, crack_seen;

reset(arg) {

    /* remove the crack at reset */
    has_widened = 0;
    crack_seen = 0;
    if(!owner){
      owner =clone_object("players/dice/quest/owner");
      move_object(owner,this_object()); }
    if (arg) return;

    property = ({ "no_fight", "no_teleport" });
    set_light(1);
    short_desc = "Small room";
    no_castle_flag = 1;
    no_obvious_msg="";
    long_desc=
      "This a small room behind the wall of the house.\n"+
      "The wall closed right after you fell through it. It is almost dark in here.\n";
    items = ({
      "room","A small room",
      "house","A small house above you",
      "walls","Solid walls, reaching the ceiling",
      "wall","A solid wall, reaching the ceiling",
      "ceiling","A small crack through which sparsely light is falling@@crack@@",
      "light","It's coming from a small crack in the ceiling@@crack@@",
      "crack","@@query_crack_desc@@"
    });
    smell = "A dull smell is hanging here.";
}

init(){  
    ::init();
    if (crack_seen) {
    add_action("break_ceiling","break");
    add_action("break_ceiling","widen");
    add_action("break_ceiling","tear");
    add_action("enter_crack","enter");
    }
}

break_ceiling(str){

  if(!str || (str!="crack" && str!="crack in ceiling")){
  notify_fail("Widen what ?\n");
  return 0;
  }
 
  if(has_widened){
  write("It's already wide enough.\n");
  return 1;
  }
  
  write("You place your fingers in the crack and widen it.\n");
  has_widened = 1;
  add_action("enter_crack","enter");
  return 1;
}


enter_crack(str) {

  if(!str || (str!="crack" && str!="crack in ceiling")){
    notify_fail("Enter what ?\n");
    return 0;}
  
  if (!has_widened) {
    write ("It is too small to enter it.\n");
    return 1;}
    
write("With great efford you wiggle yourself through the crack.\n"+
      "The owner sees how you climb through the crack, and follows you.\n");
  this_player()->move_player("through the crack#players/dice/quest/q14");
  return 1;
}


query_crack_desc () {
  if (!crack_seen) return "You dont see that here";
  if (has_widened) return "A crack wide enough to enter";
  return "A crack in the ceiling, maybe you can widen it";
}

crack () {
  if (crack_seen) return "";
  crack_seen = 1;
  add_action("break_ceiling","break");
  add_action("break_ceiling","widen");
  add_action("break_ceiling","tear");
  add_action("enter_crack","enter");
  return "";
}
