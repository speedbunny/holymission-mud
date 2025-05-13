inherit "room/room";

#include "/players/mangla/defs.h"
#include "/players/kasgaroth/private/ansi.h"

int LOCKED = 0;

int _arch() {

    object archie;

    if(archie = find_object("/sys/arch"))
        destruct(archie);
    return 1;
}

int not_here() {
   object shad;

   if (!this_player()->priv_shad())
   {
      shad = clone_object(PATH + "gal/priv_shad");
      shad->start_shadow(this_player(),0,"priv_shad");
      printf("Privacy shadow initiated.\n");
   }
   else
   {
        destruct(this_player()->priv_object());
      printf("Privacy shadow removed\n");
   } 
   return 1;
}

int work_here() {

   object shad;

   if (!this_player()->work_shad())
   {
      shad = clone_object(PATH + "gal/work_shad");
      shad->start_shadow(this_player(),0,"work_shad");
       printf("Work shadow initiated.\n");
   }
   else
   {
       destruct(this_player()->work_object());
       printf("Work shadow removed.\n");
   }
   return 1;
}

int my_dump()
{
    "/sys/chatd"->dump();
    return 1;
}

int _lock() {

    if(TP->RNAME == "mangla" || TP->RNAME == "magnal") {
        printf("Workroom is now LOCKed from intruders.\n");
        LOCKED = 1;
    }
    return 1;
}

int _un() {

    if(TP->RNAME == "mangla" || TP->RNAME == "magnal") {
        LOCKED = 0;
        printf("Workroom now _UN_locked.\n");
    }
    return 1;
}

int _st() {

    if(TP->RNAME == "mangla" || TP->RNAME == "magnal") {
        printf("The current status of your workroom is ");
        if (LOCKED) printf("LOCKED.\n");
        else printf("UNLOCKED.\n");
    }
    return 1;
}


reset(arg) {

    if(arg) return;

    set_light(1);

    short_desc=BLUE+"This is Mangla's Workroom. "+RED+"Welcome"+RESET;

    long_desc=CYAN+
          "You have entered the workroom of Mangla. Around the room are " +
          "several papers and items of interest. The desk is almost hidden " +
          "beneath mountain of print_outs. Mangla sits behind the desk relaxing " +
          "in his chair with the keyboard across his lap. He appears to be " +
          "contemplating the step in the revamping of some files. " +
              "\n"+RESET;

    dest_dir=({"room/post","ps",
               "room/church","ch",
               "room/adv_guild","gu",
               "players/mangla/guild/room","je",
               "players/mangla/rooms/newbie/new0","qs",
               "players/mangla/rooms/test","test",
             });

    hidden_dir = ({
                   "players/mangla/rooms/underdark/r5_1","down",
                 });
    property=({"no_teleport","no_sneak","no_steal"});

    smell="You smell old pizza and Mangla's shoes.";

    items=({"desk","Fully cluttered and utterly useless",
            "chair","Softly padded and well used chair",
            "pit","Where Mangla goes to test monsters and weapons.\n" +
                  "Keeps the blood off this floor",
            "picture","A very nice picture of his Mangla's sweet-heart"});

move_object(clone_object("/boards/leslie"),this_object());
#if 0
    MOVE(clone_object("/players/mangla/std/dragline"),TO);
#endif

    ::reset(arg);
}

init() {

    object temp;

    ::init();
    if (LOCKED && (TP->LEVEL < 500) && (TP->RNAME != "mangla") &&
               (TP->RNAME != "magnal") && !TP->query_npc()) {
        if (TP->LEVEL > 30) {
             TP->MOVEP("home#/players/"+TP->RNAME+"/workroom");
        }
        else TP->MOVEP("to the church#/room/church");
        return;
    }
/*
    if(temp = find_player("mangla") &&
        TP->RNAME != "mangla" &&
        TP->RNAME != "magnal" &&
        interactive(TP)) {
        TELL(temp,CAP(TP->RNAME) + " just entered your workroom.\n");
        TELL(temp,"The status of your workroom is " + LOCKED + "\n");
    }
*/
    if(TP->RNAME == "mangla" || TP->RNAME == "nae")
    add_action("not_here","priv");
    if(!TP->query_immortal() && !TP->query_testchar()) return;
    add_action("work_here","work");
    add_action("my_dump","dump");
    add_action("_lock","LOCK");
    add_action("_un","UNLOCK");
    add_action("_st","STAT");
    add_action("_arch","resetarch");
}

