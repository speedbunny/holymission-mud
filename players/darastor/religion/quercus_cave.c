/**************   QUERCUS  **************/

inherit "room/room";     
#define TP this_player()
#define TPN TP->query_name()
#define TPOSS TP->query_possessive()
#define RLM "religion/master"
#define RELIGION this_player()->query_religion()
#define PATH "/players/goldsun/sherwood/"
#define SAY(x) tell_room(this_object(),x)
void reset(int arg){

    if(arg) return;
    set_light(1);
    short_desc="Inside a cave";
    long_desc=
      "You are inside a small cave. Large torches light this place.\n"+
      "There is a small altar in the middle of the room. On the wall\n"+
      "you can see a picture.\n";
       
    property=({"has_fire"});
  
    smell="The smoke of torches.";

    dest_dir=({  PATH+ "room/plain1", "out"});

    items=({ "torches","They are fixed to the wall",
	     "torch","Is fixed to the wall",
	     "picture","There is painted a praying man",
	     "altar","Small stony altar with sign of Mighty Quercus"
    });
}

init(){
    ::init();
//    add_action("do_pray","pray");
//    add_action("do_pray","worship");
//    add_action("do_pray","praise");
//    add_action("do_sacrifice","sacrifice");
}


int help_him(){
    tell_room(environment(TP),"Quercus voice says: "+TPN+
	      " is my follower, listen to him.\n");
    return 1;
}

int do_pray(){
    mapping oprop, nprop;
    object soul;
    string *funs;

    if((TP->query_ghost())){
	write("Quercus voice says: What are you?\n");
        write("You says: I am "+TP->query_name()+"\n");
        write("Quercus voice says: No. You are nill. Like a leaf from oak. "+
   "But this\n is not proper time for you. Return back and become a legend.\n");
	say(TP->query_name()+" returns from another word.\n");
	TP->remove_ghost();
	TP->heal(TP->query_max_hp());
	return 1;
    }
    if(TP->query_religion()=="Quercus"){
	write("You kneel down in worship to the mighty Quercus.\n");
	say(TPN+" kneels down in prayer to "+TPOSS+" god.\n");
	call_out("help_him", 5+random(5));
	return 1;
    }
    if(present("goldsun_pass_to_rel",TP)){

        if (mappingp(oprop = this_player()->query_property("extra_soulfuns")))
    	{
            funs = m_indices(oprop);
            if (member_array("praise",funs)!=-1)
      	      oprop = m_delete(oprop,"praise");
            if (member_array("satha",funs)!=-1)
              oprop = m_delete(oprop,"satha");
            nprop = oprop + (["praise":"/players/goldsun/religion/actions/praise",
                              "satha":"/players/goldsun/religion/actions/satha" ]);
        } else {
        nprop = (["praise":"/players/goldsun/religion/actions/praise",
                  "satha":"/players/goldsun/religion/actions/satha" ]);
        }
        this_player()->add_property("extra_soulfuns",nprop);
        soul = present("command_soul",this_player());
        if (soul)
          move_object(soul,this_player()); /* recalling the init */
         else
          move_object(clone_object("/obj/soul"),this_player());
        SAY("The highest god Quercus appears.\nHe says: You are my follower"+
            " from this moment.\nYou can 'praise' and 'satha' to me.\n ");

	TP->set_religion("Quercus");
	destruct(present("goldsun_pass_to_rel",TP));
	return 1;

    }
    else {
	write("You must sacrifice a small path of plant at first.\n");
	return 1;
    }
}
int leave_religion(){
    write("Quercus cast a flesh of lightning at you. You feel very weakly.\n");
    tell_room(environment(TP), "A flash of lightning strikes "+TPN+"!\n");
//    TP->hit_player(TP->query_hp()-1);
 //   if (TP->query_con()>1) TP->set_con(TP->query_con()-1);
 //   if (TP->query_int()>1) TP->set_int(TP->query_int()-1);
    return 1;
}
do_sacrifice(arg){
    if(!arg) return "Sacrifice what?";
    if(arg=="leaf"){
        if(present("leaf",TP)){
           write("You sense Gods are pleased.  Perhaps you should pray.\n");
	   move_object(clone_object(PATH+"obj/rel_ob"),TP);
           destruct(present("leaf",TP));
           return 1;
	}
        write("You haven't leaf.\n");
        return 1;
    }
    write("You try to sacrifice "+arg+", but Gods don't take it.\n");
    return 1;
}

