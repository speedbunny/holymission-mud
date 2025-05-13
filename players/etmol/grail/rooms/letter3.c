
#define TP this_player()
#define TPN TP->query_name()

inherit "room/room";

reset(arg) 
{

        if (arg) return;

set_light(0); 
short_desc = "E"; 
long_desc = "You are standing on the letter E.\n"+
            "Around you are squares with the letters F, G, T and J.\n";
            

items = ({
          "squares", "Stone squares, with letters painted on them, each about 1x1 meter.",
          "square", "A stone square.",
          "floor", "As far as you see ahead, it is devided into squares.",
          "letters", "Various letters from A to Z. You wonder what they mean.",
          "letter", "Which one?"
          "J", "It looks safe to step on.", 
          "T", "It looks safe to step on.",
          "G", "It looks safe to step on.",
          "F", "It looks safe to step on.",
          "E", "You are standing on it."
        
});
}

init()
{
add_action("wrong", "F");
add_action("wrong", "J");
add_action("wrong", "G");
add_action("correct", "T");
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
write("You step on the letter T.\n");
TP->move_player("to the square with the letter T on it#/players/etmol/grail/rooms/letter4");
return 1;
}
