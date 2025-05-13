inherit "obj/monster";

#include "/players/mangla/defs.h"

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("guath");
    set_alias("beholder");
    set_alt_name("nighteyes");
    set_race("beast");
    set_size(3);
    set_level(100);
    set_short("Nighteyes beholder-kin");
    set_long("This massive creature is akin to the beholder. The body is brown and\n" +
             "approximately 5 feet in diameter. The large central eye is surrounded\n" +
             "by 5 smaller eyes on stalks. Each of these is a powerful weapon is the\n" +
             "guath decides to use it.\n");
    set_wc(30);
    set_ac(20);
    set_al(-800);
    set_chr(20);
    set_str(20);
    set_dex(5);
    set_aggressive(0);
    add_money(0);
    set_dead_ob(this_object());
  }
}

int hitter() {

    int i,j,k,dam;
    string str;
    object *ob;

    ob = all_inventory(ENV(TO));
    j = random(3);
    while(!j) {
        i = random(sizeof(ob));
        if(living(ob[i]) && ob[i] != TO &&
                !ob[i]->query_npc()) {
            j = 1;
            k = random(6);
            switch(k) {
                case 0: str = " causing serious wounds.\n";
                        dam = 30;
                        break;
                case 1: str = " causing minor wounds.\n";
                        dam = 10;
                        break;
                case 2: str = " shooting a lightning bolt.\n";
                        dam = 30;
                        break;
                case 3: str = " freezing you to the core.\n";
                        ob[i]->hold(TO,5);
                        dam = 20;
                        break;
                case 4: str = " sending a wave of energy to your soul.\n";
                        dam = 25;
                        break;
                case 5: str = " and you feel great fear.\n";
                        ob[i]->run_away();
                        dam = 10;
            }
            TELL(ob[i],"The gaunth's stalk stares at you"+str);
            say("A stalk stares at "+ob[i]->NAME+"\n",ob[i]);
            ob[i]->hit_player(dam);
        }
    }
    return 1;
}

int attack() {

  if(::attack()) {
    if(TO->query_attack())
        hitter();
  }
}

int monster_died(object ob) {

    object *y;
    object x;
    int i;

    TELLR(ENV(TO),"Realising that this Nighteyes is above all mortal bounds\n" +
                  "You feel fortunate when when a wave of energy sweeps you\n" +
                  "out of this dreadful place.\n");
    y = all_inventory(ENV(TO));
    for(i=0;i<sizeof(y);i++)
        if(living(y[i]) && y[i] != TO && !y[i]->query_npc())
            y[i]->MOVEP("is moved to#room/church");
    x = clone_object(MNST + "under/guath2");
    MOVE(x,ENV(TO));
    destruct(TO);
    return 1;
}

