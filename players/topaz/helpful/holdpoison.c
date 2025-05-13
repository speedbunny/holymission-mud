inherit "obj/monster";

#include "/players/mangla/defs.h"

static int j,k,l;

reset(arg) {
  ::reset(arg);
  if (!arg) {
    set_name("Cildabrin");
    set_alias("cildabrin");
    set_race("insect");
    set_size(5);
    set_level(35);
    set_short("Cildabrin");
    set_long("This appears to be a cross between a spider and a giant\n" +
             "scorpion. It stands 9 feet tall and is about 13 feet\n" +
             "across from tip of leg to tip of leg. The massive fur covered\n" +
             "tail has a fearsome looking stinger at its end.\n");
    set_wc(30);
    set_ac(20);
    set_hp(600);
    set_al(-600);
    set_dex(10);
    set_aggressive(1);
    add_money(8000);
  }
}

int attack() {

    int i;
    object *ob;

    ::attack();
    j = 0;
    ob = all_inventory(ENV(TO));
    while(!j) {
        i = random(sizeof(ob));
        if(living(ob[i]) && ob[i] != TO && !ob[i]->query_npc()) {
            say("The cildabrin crushes "+ob[i]->RNAME+" in a claw.\n",ob[i]);
            TELL(ob[i],"The cildabrin crushes you in a claw.\n");
            ob[i]->hit_player(20);
            j = random(10) + 1;
            ob[i]->hold(TO,j);
       }
    }
    k = 0;
    while(!k) {
        i = random(sizeof(ob));
        if(living(ob[i]) && ob[i] != TO && !ob[i]->query_npc()) {
            say("The cildabrin crushes "+ob[i]->RNAME+" in a claw.\n",ob[i]);
            TELL(ob[i],"The cildabrin crushes you in a claw.\n");
            ob[i]->hit_player(20);
            k = random(10) + 1;
            ob[i]->hold(TO,k);
       }
    }
    l = 0;
    while(!l) {
        i = random(sizeof(ob));
        if(living(ob[i]) && ob[i] != TO && !ob[i]->query_npc()) {
            say("The stinger whips forward and gouges "+ob[i]->RNAME+".\n",ob[i]);
            TELL(ob[i],"You are stung by the cildabrin's poison stinger.\n");
            ob[i]->hitplayer(10);
            l = random(5);
            if (!l) ob[i]->add_poison(3);
            l = 1;
        }
    }
    k-=1;
    j-=1;
}

