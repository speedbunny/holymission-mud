/* This is a spell book. Version 1.0c By Xanathar - The Beholder */

int light_on;

short() {
    return "an ancient spell book";
    }

long() {
    write("It is an very old spell book. There is something written in it in\n" +
	  "ancient runes. It contains the following spells :\n"+
          " 'Frotz   : create a glowing ball of light'\n" +
	  " 'Defrotz : deactivate light.'\n"+
          " 'Rezrov  : Magically unlock a door.'\n"+
          " 'Padroz  : Restore things as they were.'\n"+
          " 'Vaxum   : Make a hostile creature your friend.'\n"+
          " 'Cleesh  : Change a creature into a small amphibian (and back).'\n"+
          " 'Zifmia  : Magically summon a beeing.'\n");
    write("The book informs you : ");
    if (light_on==0) {
       write("the light is off.\n");
       } else {
       write("the light is on.\n");
       }
    say(this_player()->query_name()+" examines a spell book.\n");
    }

init() {
    add_action("light_activate", "frotz");
    add_action("light_deactivate","defrotz");
    add_action("info_spellbook","info");
    add_action("info_spellbook","read");
    add_action("rezrov_door","rezrov");
    add_action("padroz_it","padroz");
    add_action("vaxum_it","vaxum");
    add_action("cleesh_it","cleesh" );
    add_action("zifmia_it","zifmia");
}

id(str) {
    return str == "book" || str == "spell book";
}

reset(arg) {
     if (arg) {
              if (light_on==1) write("The light flickers briefly.\n");
              return 1;
              }
     light_on=0;
           }

light_activate() {

    if (call_other(this_player(), "query_level") <33) {
        set_light(1);
	write("For a very brief moment there is a blinding flash of\n"+
              "light, which dies out quickly. It seems you are not \n"+
              "powerful enough to cast this spell.\n");
        set_light(-1);
	return 1;
    }
    if (light_on==0) {
       set_light(1);light_on=1;
       write("For a very brief moment there is a blinding flash of light.\n"+
             "It slowly fades to a less painful level, but you have a quite\n"+
             "usable light source now.\n");
       say(this_player()->query_name()+" casts a light spell.\n",this_player());
       return 1; } else {
       write("But the spell is already activated !\n");
       return 1; }
}

light_deactivate() {

    if (light_on==1) {
       set_light(-1);light_on=0;
       write("Slowly the light fades until only darkness remains.\n");
       say("Slowly the light fades until only darkness remains.\n");
       return 1;
       } else {
       write("But the spell is already deactivated !\n");
       return 1; }
}

info_spellbook(arg) {

   if ((arg=="book") || (arg=="spell book")) {
      write("Spell Book Version 1.0c by Xanathar - The Beholder.\n"+
            "Padroz spell made by the Mighty Padrone (Re-Setter)\n"+
            "Rezrov spell made by Xanathar. Works only for doors\n"+
            "             created using DOOR.C\n"+
            "Other spells made by Xanathar.\n\n");
      say(this_player()->query_name()+" takes a good look at his spell book.\n");
      long();
      return 1;
      }
   return 0;
   }

query_weight() { return 1; }

get() { return 1; }

drop() {
    if (light_on==1) {
       write("As you drop the book the light fades....\n");
       say("The light fades....\n");
       set_light(-1);
       light_on=0;
       return 0;
       }
     return 0;
     }

rezrov_door(str) {
       object obj;
       string verify;

    if (call_other(this_player(), "query_level") < 33) {
       write("You concentrate on the spell, but nothing happens. Perhaps \n"+
             "you are not powerful enough to use this spell.\n");
       say(this_player()->query_name()+" tries to look very concentrated.\n");
       return 1;
       }

       obj = present(str, environment(this_player()));

       if (obj) {
          verify = call_other(obj,"short");
          if (((verify[0]==65) && (verify[2]==100)) && (verify[7]=116)) {
            write("A ray of intense enery emits from your hand and hits the\n"+
                  "lock. It becomes glowing hot and lightning bolts erupt from\n"+
                  "the door. Then suddenly the lightning is gone and nothing \n"+
                  "appears to be changed.\n");
            say("Suddenly a ray of intense enery emits from "+this_player()->query_name()+"s hand\n"+
                "and hits the lock. It becomes glowing hot and lightning bolts erupt\n"+
                "from the door.\n");
	    call_other(obj, "set_locked", 0);
	    return 1;
            } else {
              write("The "+str+" becomes glowing hot, but resists the Rezrov spell.\n");
              return 1;
              }

          } else {
          write("Somehow the "+str+" doesn't appear to be here.\n");
          return 1;
          }
   }

padroz_it(str) {
    object obj;

    if (call_other(this_player(), "query_level") < 30) {
	write("For some reason, the Padroz spell doesn't seem to do anything.\n");
        say(this_player()->query_name()+" tries to look very concentrated.\n");
	return 1;
    }

    if (!str) {
	obj = environment(this_player());
        say("For a brief moment the room glows brightly",this_player());
	write("The Padroz spell resets the room: " +
	      call_other(obj, "short") + ".\n");
	call_other(obj, "reset", 1);
	return 1;
    }
    obj = present(str, this_player());
    if (obj) {
	write("The Padroz spell resets " +
	      call_other(obj, "short") + ".\n");
	call_other(obj, "reset", 1);
	return 1;
    }
    obj = present(str, environment(this_player()));
    if (obj) {
	write("The Padroz spell resets " +
	      call_other(obj, "short") + ".\n");
	call_other(obj, "reset", 1);
	return 1;
    }
    obj = find_living(str);
    if (obj) {
	write("The Padroz spell resets " +
	      call_other(obj, "short") + ".\n");
	call_other(obj, "reset", 1);
	return 1;
    }
    write("The Padroz spell fails to locate the " + str + " .\n");
    return 1;

  }

vaxum_it(str) {
     object who;
     string name;
     if (call_other(this_player(),"query_level") <33 ) {
        write("Nothing happens.\n");
        say(this_player()->query_name()+" tries to look very concentrated.\n");
        return 1;
        }
     who = present(str, environment(this_player()));
     if (who) {
        name = call_other(who,"short");
        who = present(str, environment(this_player()));
        call_other(who,"stop_fight");
        tell_object(who,"Suddenly you fail to see the point in this fight.\n");
        call_other(this_player(),"stop_fight");
        write("You get a peaceful feeling.\n");
        return 1;
        } else {
        write("There is no one here with that name !\n");
        return 1;
        }
     }

cleesh_it(str) {
     object who;
     string name;
     if (call_other(this_player(),"query_level") <33 ) {
        write("Nothing happens.\n");
        say(this_player()->query_name()+" tries to look very concentrated.\n");
        return 1;
        }
     who = find_living(str);
     if (who) {
        name = call_other(who,"short");
        if (call_other(who,"query_frog")==0) {
            write("You turn "+name+" into a frog.\n");
            say(this_player()->query_name()+" casts a spell...\n");
            call_other(who,"frog_curse",1);
            write("Ok.\n");
            return 1;
            } else {
            write("You turn "+name+" back into its human form.\n");
            say(this_player()->query_name()+" casts a spell...\n");
            call_other(who,"frog_curse",0);
            write("Ok.\n");
            return 1;
            }
        } else {
        write("The cleesh spell was unable to transform "+str+".\n");
        return 1;
        }
     }

zifmia_it(str) {
    object who;

    if (call_other(this_player(), "query_level") < 33) {
	write("For some reason, the zifmia spell doesn't seem to do anything.\n");
        say(this_player()->query_name()+" tries to look very concentrated.\n");
	return 1;
    }

    who = find_living(str);
    if (who) {
        say("In a bright flash of magic "+str+" appears.\n");
        tell_object(who,"Suddenly the world around you fades away into darkness.\n");
        move_object(who,environment(this_player()));
        tell_object(who,"You reappear somewhere else.\n");
        write("In a bright flash of magic "+str+" appears.\n");
       return 1;
       } else {
       write("The zifmia spell fails to locate "+str+".\n");
       return 1;
       }
    }


query_value() { return 1500; }
query_code() { return "zap"; }
query_type() { return "zap"; }



