
#define TP this_player()
#define TPN TP->query_name()

inherit "room/room";

reset(arg) 
{

        if (arg) return;

set_light(0); 
short_desc = "H"; 
long_desc = "You are standing on the letter H.\n"+
            "Around you are squares with the letters V, E, D and I.\n";
            

items = ({
          "squares", "Stone squares, with letters painted on them, each about 1x1 meter.",
          "square", "A stone square.",
          "floor", "As far as you see ahead, it is devided into squares.",
          "letters", "Various letters from A to Z. You wonder what they mean.",
          "letter", "Which one?"
          "I", "It looks safe to step on.", 
          "V", "It looks safe to step on.",
          "D", "It looks safe to step on.",
          "E", "It looks safe to step on.",
          "H", "You are standing on it."
        
});
}

init()
{
add_action("wrong", "I");
add_action("wrong", "D");
add_action("wrong", "V");
add_action("correct", "E");
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
write("You step on the letter E.\n");
TP->move_player("to the square with the letter E on it#/players/etmol/grail/rooms/letter9");
return 1;
}
