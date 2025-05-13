
#define TP this_player()
#define TPN TP->query_name()

inherit "room/room";

reset(arg) 
{

        if (arg) return;

set_light(0); 
short_desc = "First square"; 
long_desc = "As you step through the door you arrive in a huge chamber.\n"+
            "You look around in awe. The sheer size of the place itself\n"+
            "is enough to take your breath but as you happen to gaze down\n"+
            "at the floor you notice something very unusal.\n"+
            "Beginning where you stand and extending as far as you can see\n"+
            "ahead, it is devided into small squares, on each of which a letter"+ 
            "is painted. Each square is just about large enough to stand on\n"+
            "and you get the feeling that is exactly what they were made for.\n"+
            "On the other hand if all the squares had been made to step on\n"+
            "all those letters wouldn't be necessary...\n"+
            "The first line of the floor in front of you consists of squares\n"+
            "with the letters A, N, B and S on them.\n";
            

items = ({
          "squares", "Stone squares, with letters painted on them, each about 1x1 meter.",
          "square", "A stone square.",
          "floor", "As far as you see ahead, it is devided into squares.",
          "letters", "Various letters from A to Z. You wonder what they mean.",
          "letter", "Which one?"
          "A", "It looks safe to step on.", 
          "N", "It looks safe to step on.",
          "S", "It looks safe to step on.",
          "B", "It looks safe to step on."
        
});
}

init()
{
add_action("wrong", "A");
add_action("wrong", "N");
add_action("wrong", "S");
add_action("correct", "B");
::init();
}
wrong()
{
write("You step on the letter.\n"+
      "For a few seconds it supports your weight, but suddenly it gives way\n"+
      "and crumbles to parts which - along with you - with a huge noise\n"+
      "fall  down into a deep pit previously hidden under the squares.\n"+
      "You try to catch the edge of one of the neighbouring squares in your fall\n"+
      "but your hand slips off of it and you fall\n"+
      "                                        and fall\n"+
      "                                              and fall...\n");
say(TPN+"steps on a letter, which suddenly gives way, and"+TPN+ "disappears\n"+
         "in the pit under the floor.\n");
 TP->set_hp(1);
 TP->move_player("falling down.#/players/etmol/grail/rooms/wrong");
return 1;
}
correct()
{
write("You step on the letter B.\n");
TP->move_player("to the square with the letter B on it#/players/etmol/grail/rooms/letter2");
return 1;
}
