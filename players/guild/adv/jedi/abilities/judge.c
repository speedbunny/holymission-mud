#include "/players/mangla/defs.h"

#define SHAPE "feeling very well,slightly hurt,somewhat hurt,hurt,\
               not feeling very well,not in a good shape,in a bad shape,\
               in a very bad shape,terribly hurt,barely alive,at death's door"
#define WCAC "very bad,bad,below average,average,good,very good,excellent,superb"
#define MONSTER "futile,simple,below average,average,above average,strong,\
                 very tough,nearly invincible"
#define WEIGHTS "weighs less than nothing,weighs almost nothing,is pretty light,\
                 has average weight,is heavy,is very heavy,extremely heavy"


string *shape_arr, *wc_arr, *monsters, *weight_arr;

string _shape(object obj) {

    int no;
    no=(sizeof(shape_arr)) * (obj->HP + 1) / (obj->MAXHP + 1);
    if(no<=0) no=1;
    else if (no>sizeof(shape_arr)) no=sizeof(shape_arr);
    return shape_arr[sizeof(shape_arr)-no];
}

string _align(object obj) {
    return obj->query_al_string();
}

string _armed(object obj) {

    int no;

    if(living(obj)) no=obj->query_wc()/3-1;
    else no=obj->weapon_class()/3-1;
    if(no>7) no=7;
    else if(no<0) no=0;
    return wc_arr[no];
}

string _protect(object obj) {

    int no;

    no=(2*obj->query_ac()/5)-1;
    if(no>7) no=7;
    else if(no<0) no=0;
    return wc_arr[no];
}

string _protect2(object obj) {

    int no;

    no=obj->armour_class();
    if(no>7) no=7;
    else if(no<0) no=0;
    return wc_arr[no];
}

string _monster(object obj) {

    int no;

    no = obj->MAXHP/90-1;
    if(no>7) no=7;
    else if(no<0) no=0;
    return monsters[no];
}

string _weight(object obj) {

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
        write("It is a " + _armed(obj) + " weapon.\n");
        flag=1;
    }
    if(obj->query_armour()) {
         write("It seems to be some kind of armour.\n");
         write("It provides " + _protect2(obj) + " protection.\n");
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
    write("It is " + _weight(obj) + ".\n");
    return 1;
}

int judge_living(object obj) {

  write(obj->NAME + " is living. " + CAP(obj->PRO) + " is " + _align(obj) + ".\n"+
        CAP(obj->NAME) + " is a " + _monster(obj) + " " + obj->query_race() + ".\n"+
        CAP(obj->PRO) + " is " + _shape(obj) + ".\n"+
        CAP(obj->PRO) + " is " + _armed(obj) + " armed and " + _protect(obj) +
        " protected.\n");
    return 1;
}

/******* JUDGE Judges an object and returns a comparitive
               analysis of the object. IE give the player
               a general idea of what the object is like.
********/

int main(string str) {

    object ob;

    wc_arr = explode(WCAC,",");
    shape_arr = explode(SHAPE,",");
    weight_arr = explode(WEIGHTS,",");
    monsters = explode(MONSTER,",");


    if(!str) return 0;
    if(ob = present(LC(str),ENV(TP)));
    else ob = present(LC(str),TP);
    if(!ob) write("What do you want to judge?\n");
    else {
        write("You concentrate your Force on " + CAP(str) + ".\n");
        if(living(ob) && ob->query_hit_point()) judge_living(ob);
        else judge_object(ob);
        }
    return 1;
}

