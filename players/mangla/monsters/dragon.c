inherit "obj/monster";

#include "/players/mangla/defs.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("Lanksos");
    set_alias("dragon");
    set_alt_name("lanksos");
    set_race("reptile");
    set_size(5);
    set_level(70);
    set_short("Lanksos the Great Red Wyrm");
    set_long("    This massive creature is one of the great wyrms. She has been preying\n" +
             "upon the local countryside for many years. No one has been strong enough to\n" +
             "defeat her in battle. Many have tried, but none have succeeded. \n\n" +
             "    You look back down her tail to see large spikes, swishing back an forth,\n" +
             "which can be used to gore an oppenent.  The large claws are also a fearsome\n" +
             "site to behold. As the dragon opens its mouth, the many rows of razor sharp\n" +
             "teeth become evident. A pure heat wave rocks you back as she breathes.\n");
    set_wc(40);
    set_ac(35);
    set_hp(4000);
    set_al(-1000);
    set_dex(3);
    set_aggressive(0);
    add_money(0);
    set_dead_ob(TO);
    set_chance(30);
    set_spell_dam(5);
    set_spell_mess2("The dragon whips its tail forward and gores you.");
    set_spell_mess1("The dragon strikes with its tail.");
  }
}

int hitter() {

    int i,j,k,dam;
    string str;
    object *ob;

    ob = all_inventory(ENV(TO));
    j = 1;
    while(j) {
        i = random(sizeof(ob));
        if (i == 1) j = 0;
        if(living(ob[i]) && ob[i] != TO &&
                !ob[i]->query_npc() && !ob[i]->query_immortal()) {
            j = 0;
            k = random(3);
            switch(k) {
                case 0: str = "breathes on you burning your skin.\n";
                        dam = 50;
                        break;
                case 1: str = "sweeps you with her rear claw.\n";
                        dam = 20;
                        break;
                case 2: str = "chomps down on you with her razor teeth.\n";
                        dam = 40;
                        break;
            }
            TELL(ob[i],"The dragon "+str);
            say("The dragon mutilates "+ob[i]->NAME+"\n",ob[i]);
            ob[i]->hit_player(dam);
        }
    }
    return 1;
}

int attack() {

    ::attack();
    if(TO->query_attack())
        hitter();
}

int monster_died(object ob) {

    object *y;
    object x;
    int i;

    TELLR(ENV(TO),"You have successfully defeated the red dragon, but she was\n" +
                  "devious and laid down a trap for her tormentor. You are magically\n" +
                  "moved to a unknown location, but as you leave you see the mist form\n" +
                  "into the dragon you thought you had vanquished.\n");
    y = all_inventory(ENV(TO));
    for(i=0;i<sizeof(y);i++)
        if(living(y[i]) && y[i] != TO && !y[i]->query_npc())
            y[i]->MOVEP("is moved to#" + ROOM + "mount/slope1");
    x = clone_object(MNST + "dragon");
    MOVE(x,ENV(TO));
    destruct(TO);
    return 1;
}

