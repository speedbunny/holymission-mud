
#define TP this_player()
#define TPN TP->query_name()

inherit "room/room";

reset(arg) 
{

        if (arg) return;

set_light(0); 
short_desc = "M"; 
long_desc = "You step on the last letter.\nGreat!\n"+
            "The Grail awaits you, you can feel its presence.\n";
            

items = ({
          "squares", "Stone squares, with letters painted on them, each about 1x1 meter.",
          "square", "A stone square.",
          "floor", "As far as you see ahead, it is devided into squares.",
          "letters", "Various letters from A to Z. You wonder what they mean.",
          "letter", "Which one?"
          "M", "You are standing on it."
        
});
dest_dir = ({
             "/players/etmol/grail/rooms/grail", "east",
           });


}

return 1;
}
