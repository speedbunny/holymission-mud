inherit "/obj/monster";
object scroll,robe;
int i;

#define PLACE ({"/room/church",\
        "players/moonchild/haunter/moor21",\
           "players/dice/vul/purg",\
           "players/warlord/drachall1",\
           "room/shore/p03",\
           "players/rasta/room/entrance",\
        "players/patience/tree_city/orowan",\
            "players/herp/abbey/e05",\
         "room/south/sforest9",\
           "players/whisky/garden/room/forest1",\
               "players/patience/ezo/meadow12",\
              "players/uglymouth/vikings/bay_ne",\
                "/room/adv_guild",\
                "room/sea",\
    "players/padrone/maze/maze25",\
    "room/plane3",\
    "room/hump",\
    "players/dice/vul/3_2",\
                "/room/clearing"})
reset(arg) {
    ::reset(arg);
    if(!scroll);
    if (arg) return 1;
    set_name("Old wise man");
    set_alias("wise man");
    set_alt_name("man");
    set_short("old man");
    set_long("The wise old man from the mountain top.\n"+
      "He's wearing a white robe in the ancient greece style.\n"+
      "His face is carved from the long time in the sun and wind here.\n");
    set_race("human");
    set_level(30);
    set_al(100);
    set_hp(1500);
    set_gender(1);
    set_aggressive(0);
    set_prevent_poison(1);
    set_no_steal(1);
    set_no_ears(1);
    load_chat(10,({
	"Wise man says: I am the guardian\n",
	"Wise man shivers from the cold\n",
	"Wise man asks you: Why have you come here ?\n",
	"Wise man tells you: Be careful\n",
      }));
    set_whimpy(0);
    transfer(clone_object("/players/dice/vulObj/scroll"),this_object());
    transfer(clone_object("players/dice/vulObj/robe"),this_object());
    command("wear robe");
    return 1;
    i = 0;
}


attack(){
    int x;
    object victim;
    victim= this_object()->query_attack();
    victim->stop_fight();
    this_object()->stop_fight();
   this_object()->heal_self(200);
    if(i >= 10){
	tell_object(victim,"The old man mumbles: You are too boring,"+
	  "I guess it's time for me to leave.\n");
	say("Wise old man poits at the sky and is gone.\n");
	destruct(this_object());
	return 1;
    }
    x=random(sizeof(PLACE));
    transfer(victim,PLACE[x]);
    tell_object(victim,"You are transferred somewhere.\n");
    i++;
    return 1;
}

