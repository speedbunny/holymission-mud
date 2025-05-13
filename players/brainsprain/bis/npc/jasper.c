inherit "obj/monster";
#include "/players/brainsprain/bis/bisdef.h"

heart_beat(){
        object ob;
        ob=this_object()->query_attack();
        ::heart_beat();
        if(this_object()->query_attack()){
        tell_object(ob,this_object()->query_name()+" envelops you in a fire or righteousness.\n");

        say(this_object()->query_name()+" envelops "+ob->query_name()+" in a fire of righteousness.\n",ob);
        ob->hit_player(random(100));
        return;
      }
}
catch_tell(arg){
 string str1;
if (sscanf(arg,"%s help",str1)==1){
write(
"Jasper says: My brother must have sent you for the sword to kill Darkstaff\n"+
"             with.  I am more than willing to give it to you, however\n"+
"             the final incantation is not done, please bring me the tome.\n"+
"             My father hid is somewhere within the castle.  Let me teleport\n"+
"             You out of this nasty maze.  Oh.... get the enchanted gloves\n"+
"             from the princess, the tome will burn all who touch it without\n"+
"             the gloves.\n");
tle();
return 1;
}
}
tle(){
write("Jasper transfers you to the great hall.\n");
this_player()->move_player("to the great hall#/players/brainsprain/bis/rooms/grnd_hl.c"
);
return 1;
}

void reset(int arg){
    ::reset();
    set_name("jasper");
    set_race("human");
    set_gender(0);
    set_alias("duke");
    set_alt_name("duke jasper");
    set_short("Duke Jasper");
            set_long(
"Duke Jasper is a small fellow.  His shoulders are permenantly hunched "+
"from long hours of crouching over magic experiments.  His eyes are "+
"filled with a sense of mystique and knowledge.  His entire body is "+
"covered in a shining white cloak.\n");
    set_level(20);
    set_hp(1500);
    set_al(1000);
    set_ac(11);
    set_wc(30);
    }
init(){
  ::init();
        heart_beat();
  }

