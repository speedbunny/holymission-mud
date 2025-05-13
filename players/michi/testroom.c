inherit "room/room";
#include "/players/sourcer/define.h"


void reset(int arg) {


    if(!arg) {
  
        set_light(1);
        short_desc="a workroom";
        long_desc=
        "This is a giant workroom. \n" +
        "There is a huge desk standing in front of the window, \n" + 
        "with piles of papers on it.... you can't imagine how busy \n " +
                "he is";

        dest_dir=({
            "room/post", "post",
            "room/church", "church",
            "room/adv_inner", "guild", 
            "players/sourcer/guild/room","druid",
                });
 
        items=({ 
            "air","It's very thin up here",
            "aquarium","A nice aquarium, you see some turtles there",
            "floor","The floor is covered with smooth carpets.",
            "desk","It's a huge wooden desk with lots of papers on it. ",
            "papers","You won't dare to read it, they are PRIVATE!!",
              });
        smell = "This place is a bit dusty";

    }
}

init()
{
object me;
  ::init(); 
   add_action("read","read");
   add_action("do_give","make");
   add_action("do_get","summon");
   add_action("do_quit","q");
    }

int do_get( string arg) {
object target;
        if(target=find_living(arg)) move_object(target,TO);
        return 1;
        }   
int do_give( string arg ) {

        if(file_size(arg+=".c") >= 0) {
                write("OK, da hast du's.\n");
                move_object(clone_object(arg), TP);
                }
        else write("Mist, das gibts andscheinend net!\n");
        return 1;
        }

         
int do_quit()
{
                move_object(TP,"/players/sourcer/private/workroom");
        return 1;
}
