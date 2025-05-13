#include "/players/mangla/defs.h"
#include "/players/mangla/guild/soul.h"

#define SHAPE "feeling very well,slightly hurt,somewhat hurt,hurt,not feeling very well,not in a good shape,in a bad shape,in a very bad shape,terribly hurt,barely alive,at death's door"
#define ALIGNMENT "demonic,evil,nasty,neutral,nice,good,saintly"
#define WCAC "very bad,bad,below average,average,good,very good,excellent,superb"
#define MONSTER "futile,simple,below average,average,above average,strong,very tough,nearly invincible"
#define WEIGHTS "weights less than nothing,weights almost nothing,is pretty light,has average weight,is heavy,is very heavy,extremely heavy"
#define SUGGESTIONS "noattack,fear,weak,brainstorm,discord"

string *align_arr,*shape_arr,*wc_arr,*weight_arr,*suggest_arr,*suggestions,*monsters;

void reset(int arg) {
align_arr = explode(ALIGNMENT,",");
wc_arr = explode(WCAC,",");
shape_arr = explode(SHAPE,",");
weight_arr = explode(WEIGHTS,",");
monsters = explode(MONSTER,",");
suggest_arr = explode(SUGGESTIONS,",");
}

int fear_all();

int shock(string str) {

    object whom;
    int dam,cost;

    dam=20+TPL/3+TP->WIS;
    cost=30-TP->query_int()/4+TPL;

    if(!str) whom=TP->query_attack();
    else whom=present(str,ENV(TP));
    if(!whom) {
        if(!str) write("Bolt whom?!\n");
        else write("No " + CAP(str) + " here.\n");
            return 1;
    }
    if(whom==TP) {
        write("You don't want to do that.\n");
        return 1;
    }
    if(!living(whom)) {
        write(CAP(str)+" is not a living thing.\n");
        return 1;
    }

    write("You hold your hands towards " + whom->NAME + ".\n");
    if(TP->SP < cost) {
        write("You lack the Force to finish the spell.\n");
        return 1;
    }
    write("Blue flashes of electricity crackle out of your hands and strike " +
          whom->NAME + ".\n");
    say("Bolts of electricity crackle out of " + TP->NAME + "'s hands and strike "+
        whom->NAME + ".\n");
    if(whom->HP<dam) dam=whom->HP/2;
    whom->hit_player(1);
    whom->hit_player(dam,5);
    TP->ADDSP(-cost);
    return 1;
}


int brainstorm(string str) {

    object obj;
    int cost;

    if(!str) {
        write("Whom do you want to suggest anything?\n");
        return 1;
    }
    obj=present(str,ENV(TP));
    cost=10+TPL*3-TP->WIS;
    if(!obj) {
        write("That is not here.\n");
        return 1;
    }
    if(!living(obj)) {
        write("That is not a living thing.\n");
        return 1;
    }
    if(TP->SP<cost) {
        write("You are not strong enough.\n");
        return 1;
    }
    if (100*obj->HP/obj->MAXHP<10) {
        if(random(100)<TP->CHA) {
            write(obj->NAME + " suddenly looks very bad." + obj->PRO +
                  " stumbles and falls to the ground.\n");
            obj->hit_player(1000);
        }
        else
            write("You fail to suggest anything.\n");
    }
    else
        write("You concentrate hard, but you fail to affect " +
              obj->NAME + "\n");
    TP->ADDSP(-cost);
    return 1;
}


int cure(string str) {

    int i,cost,a;
    string what,how;

    if(!str) return 0;

    if(str=="wounds" || (sscanf(str,"%s %s",how,what)==2 && what=="wounds")) {
        switch(how) {
            case "light"   : a=3*TP->MAXHP/10; break;
            case "serious" : a=5*TP->MAXHP/10; break;
            case "critical": a = 9*TP->MAXHP/10; break;
            default        : if(str == "wounds")
                                 a = TP->SP-20;
                             else
                                 return 1;
          }

        if(TP->HP + a > TP->MAXHP) {
            if(str!="wounds") {
                write("You don't have " + how + " wounds.\n");
                return 1;
            }
            a = TP->MAXHP - TP->SP-20;
        }

        if(a > TP->SP) {
            write("You don't have the mental energy to do that.\n");
            return 1;
        }

        if(a <= 0) {
            write("You think that this was useless.\n");
            return 1;
        }
        write("You feel better now.\n");
/* 050993 Galadriel: Patch to prevent hp bigger than maxhp */
        if(TP->query_hp()+a>TP->query_maxhp())
            a=TP->query_maxhp()-TP->query_hp();
/* end patch */
        TP->ADDHP(a);
        TP->ADDSP(-a);
        return 1;
    }
    if (str=="poison" || str=="poisonness") {
        cost = TP->query_poisoned() * 2 + TP->query_intoxination() * 2/3;
        if(!TP->query_poisoned() && !TP->query_intoxination()) {
            write("You are not poisoned or intoxicated.\n");
            return 1;
        }
        if(TP->SP < cost) {
            write("You lack the power to do that.\n");
            return 1;
        }
        write("You concentrate your Force.\n"+ 
              "You think your blood is boiling.\n");
        if(TP->HP>10)
            TP->reduce_hit_point(10);
        TP->add_poison(-TP->query_poisoned());
        for (i=0;i<TP->query_intoxination();i++)
            TP->add_intoxination(-1);
        TP->ADDSP(-cost);
        return 1;
    }
    return 1;
}


int discord(string str) {

    object *all;
    int i,percentage,w,cost,count;

    cost=TPL*3;

    if(TP->SP < cost) {
        write("You lack the mental energy to suggest anything.\n");
        return 1;
    }
    TP->ADDSP(-cost);
    all=all_inventory(ENV(TP));
    count=0;

    for(i=0;i<sizeof(all);i++) {
        if(all[i]->short() && all[i]->query_attack() == TP) {
            w=random(sizeof(all));
            while ((all[w]==TP && !random(3)) || (w==i) || (!living(all[w])))
                w=random(sizeof(all));
            count++;
            all[i]->attack_object(all[w]);
        }
    }
    if(!count)
        write("Everybody here seems to do somethings else.\n");
    else
        write("You have sown the seeds of discord between your opponents.\n");
    return 1;
}


int fear(string str) {

    object obj;
    if(str=="all") {
        fear_all();
        return 1;
    }
    if(!str) {
        write("Whom do you want to suggest fear?\n");
        return 1;
    }
    obj=present(str,ENV(TP));
    if(!obj) {
        write(CAP(str)+" isn't here.\n");
        return 1;
    }
    if(obj==TP) {
        write("You don't really want to do that.\n");
        return 1;
    }
    if(!living(obj)) {
        write(CAP(str)+" is actually not a living thing.\n");
        return 1;
    }
    if(obj->query_guild()==4 &&
      obj->query_level()>TP->query_level()-2) {
        write(obj->NAME+" is a Jedi, too. You cannot fake him.\n");
        tell_object(obj,TP->NAME+" tries to fear you.\n");
        return 1;
    }
    if(obj->query_wis()-20>TP->query_wis()) {
        write(obj->NAME+" is to wise to fall for that.\n");
        return 1;
    }
    if(obj->query_wimpy() < 0) {
        write("The " + obj->NAME + " is too foolhardy to be afraid of you.\n");
    }
    write("You concentrate your Force and say some words.\n");
    say(TP->NAME + " speaks some strange words and waves with a hand.\n");
    TELL(obj,"As you look up to " + TP->NAME + " you get an unusual "+
             "feeling.\nYour hands begin to sweat.\nYou panic.\n");
    obj->run_away();
    if(ENV(obj) == ENV(TP)) {
        write(obj->NAME + " does not flee from you.\n");
    }
    return 1;
}

int fear_all() {

    object obj, *wimps;
    int i;
    status allow;

    wimps=all_inventory(ENV(TP));
    i=sizeof(wimps)-1;

    say(TP->NAME + " murmurs something you don't understand.\n");
    while(i>=0) {
        allow=1;
        if(living(wimps[i]) && wimps[i]!=TP) {
            if(wimps[i]->query_guild() == 4 &&
               wimps[i]->LEVEL > TP->LEVEL - 4) {
                write(wimps[i]->NAME+" is a Jedi, too. You cannot fake him.\n");
                tell_object(wimps[i],TP->NAME + " tries to fear you.\n");
                allow = 0;
            }
            if((wimps[i]->WIS - 20) > (TP->query_wis())) {
                write(wimps[i]->NAME+" is to wise to fall for that.\n");
                allow = 0;
            }
            if(wimps[i]->query_wimpy() < 0) {
                write(wimps[i]->NAME + " is too foolhardy to fear you.\n");
                allow = 0;
            }
            if(allow) {
                TELL(wimps[i],"As you look up to " + TP->NAME +
                              " you get an unusual feeling.\n" +
                              "Your hands begin to sweat.\nYou panic.\n");
                wimps[i]->run_away();
                if(ENV(wimps[i]) == ENV(TP))
                    write(wimps[i]->NAME + " tried but failed to leave.\n");
            }
        }
        i--;
    }
    return 1;
}


string shapey(object obj) {

    int no;
    no=(sizeof(shape_arr)) * (obj->HP + 1) / (obj->MAXHP + 1);
    if(no<=0) no=1;
    else if (no>sizeof(shape_arr)) no=sizeof(shape_arr);
    return shape_arr[sizeof(shape_arr)-no];
}

string align(object obj) {
    return obj->query_al_string();
}

string armed(object obj) {

    int no;

    if(living(obj)) no=obj->query_wc()/3-1;
    else no=obj->weapon_class()/3-1;
    if(no>7) no=7;
    else if(no<0) no=0;
    return wc_arr[no];
}

string protect(object obj) {

    int no;

    no=obj->query_ac()/2-1;
    if(no>7) no=7;
    else if(no<0) no=0;
    return wc_arr[no];
}

string protect2(object obj) {

    int no;

    no=obj->armour_class();
    if(no>7) no=7;
    else if(no<0) no=0;
    return wc_arr[no];
}

string monster(object obj) {

    int no;

    no = obj->query_maxhp()/90-1;
    if(no>7) no=7;
    else if(no<0) no=0;
    return monsters[no];
}

string weight(object obj) {

    int no;

    no=obj->query_weight()+1;
    if(no<0) no=0;
    else if(no>6) no=6;
    return weight_arr[no];
}

int judge_object(object obj) {

    int flag;
    flag=0;
    write(obj->short() + ".\n");
    if(obj->query_weapon()) {
        write("It seems to be some kind of weapon.\n");
        write("It is a "+armed(obj)+" weapon.\n");
        flag=1;
    }
    if(obj->query_armour()) {
         write("It seems to be some kind of armour.\n");
         write("It provides "+protect2(obj)+" protection.\n");
         flag=1;
    }
    if(obj->query_container()) {
         write("It seems to be some kind of a container.\n");
         flag=1;
    }
    if(obj->query_food()) {
        write("It seems you can eat it.\n");
        flag=1;
    }
    if(obj->query_drink()) {
        write("It seems you can drink it.\n");
        flag=1;
    }
    if(!flag)
        write("You don't know exactly what it is used for.\n");
    write("It is "+weight(obj)+".\n");
    return 1;
}

int judge_living(object obj) {

  write(obj->NAME + " is living. " + CAP(obj->PRO) + " is " + align(obj) + ".\n"+
        CAP(obj->NAME) + " is a " + monster(obj) + " " + obj->query_race() + ".\n"+
        CAP(obj->PRO) + " is " + shapey(obj) + ".\n"+
        CAP(obj->PRO) + " is " + armed(obj) + " armed and " + protect(obj) +
        " protected.\n");
    return 1;
}

int judge(string str) {         /* Main proc for jugding */

    object ob;

    if(!str) {
        return 0;
        }
    if(present(LC(str),ENV(TP))) {
        ob=present(LC(str),ENV(TP));
        }
    else {
        ob=present(LC(str),TP);
        }
    if(!ob) {
        write("What do you want to judge?\n");
        }
    else {
        write("You concentrate your Force on " + CAP(str) + ".\n");
        if(living(ob)) {
            judge_living(ob);
            }
        else {
            judge_object(ob);
            }
        }
    return 1;
}   /* end  judge */

void noattack() {

    write("You concentrate your Force.\n");
    say(TP->NAME + " utters some strange words.\n");
    call_out("perform_noattack", 1, ENV(TP));
    return;
}

void perform_noattack(object obj) {

    object env, *ob;
    int i;

    env = ENV(TP);
    if(env != obj)
        return;
    ob = all_inventory(env);
    for (i=0; i<sizeof(ob); i++) {
        if (living(ob[i]) && ob[i]->query_attack()) {
            if(ob[i]->CHA < TP->CHA + 20 * TPL) {
                ob[i]->stop_fight();
                ob[i]->stop_fight();
                ob[i]->stop_hunter(1);
            }
            else
                write("You cannot affect "+ob[i]->query_name()+".\n");
        }
     }
     write("You're no longer attacked.\n");
}


int suggest(string str) {

    int i;
    status found;
    string what,who;

    if(!str) {
        write("Suggestions are :" + SUGGESTIONS + "\n");
        return 1;
    }
    sscanf(str,"%s %s",what,who);
    if(!who) what=str;
    i=sizeof(suggest_arr)-1;
    found=0;
    while(i>=0) {
       if (suggest_arr[i] == what) found = 1;
       i--;
    }
    if(!found) {
        write("You don't know how to do this.\n");
        return 1;
    }
    else {
        call_other(TO,what,who);
        return 1;
    }
}


int weak(string str) {

    object obj,weaker;
    int cost,percentage,duration;

    if(!str) {
        write("Whom do want to suggest anything ?\n");
        return 1;
    }
    obj = present(str,ENV(TP));
    cost = 10+TPL * 2 - TP->WIS;
    if(!obj) {
        write("That is not here.\n");
        return 1;
    }
    if(!living(obj)) {
        write("That is not a living thing.\n");
        return 1;
    }
    if(!present("weakerobj",obj)) {
        if(TP->SP < cost) {
            write("You are not strong enough.\n");
            return 1;
        }
        duration = TP->CHA * 2 - obj->CHA;
        percentage = TPL/12 * 25;
        weaker=clone_object("players/kelly/guild/weaker");
        move_object(weaker,obj);
        weaker->start(duration,percentage);
        write(obj->NAME + " looks less strong than before.\n");
        TP->ADDSP(-cost);
    }
    else {
        write(obj->NAME + "does not appear to be affected.\n");
        TP->ADDSP(-cost/3);
    }
    return 1;
}
