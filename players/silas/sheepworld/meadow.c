inherit "room/room";

#include "meadow.h"
#define EXTRA_RESET
#ifndef DEST_DIRS
#define DEST_DIRS ({ }) 
#endif
#ifndef LONG_DESC
#define LONG_DESC ""
#endif

void reset(int flag) 
{
    int lev,cnt,i;
    object sh;

    ::reset(flag);
    EXTRA_RESET
    if (flag == 0)
    {
    set_light(1);
    short_desc="Meadow";
    long_desc=LONG_DESC;
    smell="The overpowering aroma of sheep caresses your sense of smell";
    dest_dir=DEST_DIRS;
    items=({ "grass","No, you can't smoke it, sorry",
             "wildflowers","Daisies, thistles, dandelions, etc",
             "pellets","Judging from the taste they must be sheep droppings",
             "breeze","You can't look at a breeze, Silly!" });
    }  /* end creation */
    cnt=random(4)+1;
    lev=25/cnt;
    if(!present("sheep",this_object()) && !random(3)) for(i=0;i<cnt;i++) {
	string type;
        type=({ "white", "black", "grey", "neon green", "hot pink" })[random(5)];
        sh=clone_object("obj/monster");
        sh->set_name(type + " sheep");
        sh->set_race("sheep");
        sh->set_gender(random(2)+1); 
	     sh->set_long("A " + type + " sheep. ");
        sh->load_chat(20, ({ "BAHAHAHAHAHA!.\n",
         "You see a sheep mounting another sheep.\n",
         "A sheep rubs against your legs.\n",
         "A sheep stares at you while chowing down on some grass.\n",
         "A sheep bleats in your general direction.\n",
         "A sheep contributes to the assortment of pellets on the ground.\n"}));
        sh->set_level(lev);
        move_object(sh,this_object());
      }   /* endfor */
    }
