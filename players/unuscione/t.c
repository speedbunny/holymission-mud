#include "/players/sourcer/define.h"
#define NAME "dragonn"
#define TP this_player()
#define QRL query_real_name()
#define QI query_invis()
#define OWNER "dragonn"
 
inherit "room/room";
#define CNAME   capitalize(NAME)
 
reset(arg) {
object board;
 
    if(!arg) {
        set_light(1);
        short_desc="Lord " + CNAME + " workroom.",
 
        long_desc=
 "You are standing in the most beatifull room in the world.\n" +
 "After a while you noticed that it's the Dragonn's workroom.\n"+
"There is a huge picture  and some bottles to the ground.\n";
 
  dest_dir=({
     "room/post", "post",
     "room/church", "chu",
     "room/adv-guild", "guild",
     "room/prison", "pri",
     "room/quest_room", "que",
 
  });
        items=({
            "botles","Bottles of Aldaris Beer.",
            "picture","Mariage picture of Dragonn and Babkonzerv.",
              });
         board = clone_object("/obj/board");
         board->set_name("Bloody board !");
         board->set_file("players/dragonn/work_board");
         move_object(board,this_object());
         property = ({
            "no_teleport","no_sneak","no_steal",
                    });
        smell = "Ouch";
    }
}
 
init()
{
  ::init();
     if(this_player()->query_newwiz())
        {
        write ("Dragonn arrives. \n");
        write ("Dragonn bows to you.\n");
        write ("Dragonn vanishes!\n");
        }
 if((find_living( NAME ) && (TP->QRL !="dragonn"))) {
    if (TP->QI)
     {
  tell_object(find_living( NAME ),capitalize(TP->QRL +
  " has entered in your workroom (INVISIBLE) !!! \n"));
     }
  else
  {
  tell_object(find_living( NAME ),capitalize(TP->QRL +
  " has entered in your workroom !!!! \n"));
  }
}
}
