
#define TP this_player()
#define TPN TP->query_name()

inherit "room/room";

reset(arg) 
{

        if (arg) return;

set_light(0); 
short_desc = "T"; 
long_desc = "You are standing on the letter T.\n"+
            "Around you are squares with the letters H, D, O and L.\n"+
            "There is a note scrambled on the square you are standing on\n"+
            "beside the letter.\n";
            

items = ({
          "squares", "Stone squares, with letters painted on them, each about 1x1 meter.",
          "square", "A stone square.",
          "floor", "As far as you see ahead, it is devided into squares.",
          "letters", "Various letters from A to Z. You wonder what they mean.",
          "letter", "Which one?"
          "H", "It looks safe to step on.", 
          "D", "It looks safe to step on.",
          "O", "It looks safe to step on.",
          "L", "It looks safe to step on.",
          "T", "You are standing on it.",
          "note", "It says: 6 more letters to go."
        
});
}

init()
{
add_action("wrong", "D");
add_action("wrong", "O");
add_action("wrong", "L");
add_action("correct", "H");
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
write("You step on the letter H.\n");
TP->move_player("to the square with the letter H on it#/players/etmol/grail/rooms/letter5");
return 1;
}
