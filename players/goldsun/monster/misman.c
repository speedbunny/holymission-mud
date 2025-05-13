inherit "obj/monster";

 reset(arg) { 
  int i;
  string s;

  :: reset(arg);

 if (arg) return;
 set_name("pacho");
 set_alias("wanderer");
 set_race("humans");
 set_short("Wanderer Pacho");
 set_long("This is wanderer Pacho who has been everywhere.\n"+
	  " His clothes are very dusty.\n");
 set_level(15);
 set_hp(500);
 set_al(10);
 set_gender(1);
 set_aggressive(0);
 set_wc(18);
 set_ac(3);
 set_dead_ob(this_object());
/* move_object(clone_object("/players/goldsun/obj/purse"),this_object()); */
 if (sscanf(file_name(this_object()),"%s#%d",s,i)==2)
       call_out("wandering",30);
}

catch_tell(str){
 string who, where;
 if (sscanf(str, "%s leaves %s.\n",who,where)==2)
      call_out("moven",2,where);
 }

moven(where){
 command(where,this_object());
}


wandering(){
 string s;
 int i;
 random_move();
 while (remove_call_out("wandering") !=-1);
 if (sscanf(file_name(this_object()),"%s#%d",s,i)==2) 
    call_out("wandering",20);
 }


monster_died(ob){
 move_object(clone_object("/players/goldsun/obj/purse"),this_player());
 write("Ok.\n");
 say(capitalize(this_player()->query_name())+" takes a purse from the "
                  +"corpse.\n");
 }


