inherit "room/room";
#define CNAME   capitalize(NAME)
#define NAME    "sourcer"
#define QIP(x) query_ip_name(x)
#include "/players/sourcer/define.h"

int lighted;         /* brightness */
object player;       /* affected player */
string description;  /* fixes extra_look */
object mark, spare, last,got;


reset(arg) {

    if(!arg) {
  
	set_light(1);
        short_desc=CNAME + "' workroom",
        long_desc=
        "This is the giant workroom of "+CNAME+".\n" +
        "There is a huge desk standing in front of the window, \n" + 
        "with piles of papers on it.... you can't imagine how busy \n " +
        "this wizard is, so don't disturb him!!! There is an aquarium in the north\n ";

        dest_dir=({
            "room/post", "post",
            "room/church", "church",
            "room/adv_guild", "guild", 
            "/players/sourcer/quest/road1", "quest",
            "/players/sourcer/death/death/city/road1","death", 
	    "players/sourcer/room/room1", "room1",
                });
 
        items=({ 
            "air","It's very thin up here",
            "aquarium","A nice aquarium, you see some turtles there",
            "floor","The floor is covered with smooth carpets.",
            "desk","It's a huge wooden desk with lots of papers on it. ",
            "papers","You won't dare to read it, they are PRIVATE!!",
              });
      /*  property = ({
                 "no_teleport","no_sneak","no_steal",
                    });     */
        /* Smell is set like this... */
        smell = "This place is a bit dusty";
    }
}

init()
{
  ::init(); 
    add_action("read","read");

    if ((find_living( NAME )) && (TP->query_real_name() != NAME)) {
        if (TP->query_invis()) {
            tell_object( find_living( NAME ), capitalize( TP->query_real_name() +
            " has entered the your workroom !! " + " (invisible) \n"));
            }
        else {
            tell_object( find_living( NAME ), capitalize( TP->query_real_name() +
            " has entered your workroom !! \n "));
            }
        }
    else { 
        if (TP->query_real_name() != NAME)
        write("Master Sourcer is not at home!!  \n"); 
        }
    add_action("do_give","make");
    add_action("hmmmm",""); 	 
	add_action("do_get","komm");
    add_action("do_align","align");
    add_action("clear_room","clear");
//    add_action("do_desc","desc");
//    add_action("destroy_tool","destroy");
//    add_action("do_don","don");
//    add_action("do_doff","doff");
    add_action("do_dwho","dwho");
    add_action("do_net","net");
    add_action("do_man","man");
    add_action("shout_curse","noshout");
    add_action("do_objects","objects");
    add_action("do_show","show");
    add_action("do_where","where");
    add_action("do_scan","scan");
    add_action("do_i_dump","i_dump");
    add_action("do_i_mark","i_mark");
    add_action("do_i_mark","im");
    add_action("do_i_clone","i_clone");
    add_action("do_i_swap","i_swap");
    add_action("do_i_swap","isw");
    add_action("do_i_destruct","i_destruct");
    add_action("do_i_destruct","id");
   add_action("do_i_call","i_call");
    add_action("do_i_call","ic");
    add_action("do_i_more","i_more");
    add_action("do_i_move","i_move");
    add_action("do_i_move","imo");
    add_action("do_i_show","i_show");
    add_action("do_i_show","ish");
    add_action("do_snooptrace","snooptrace");
    add_action("do_snooptrace","sn");
    add_action("ih","ih");
    add_action("ir","ir");
    add_action("il","il");
    add_action("idl","idl");
    add_action("do_invent","I");
    add_action("ii","ii");
    add_action("ime","ime");
    add_action("do_i_clear","i_clear");
    add_action("do_i_clear","icl");
    add_action("do_i_who","i_who");
    add_action("do_i_stat","i_stat");
    add_action("do_i_stat","is");

    }

    


int hmmmm(string str) {
	if(query_verb() =="clear" || query_verb()=="destruct") {
		write_file("/players/sourcer/clear.log",TPN+" "+ctime(time())+
			"\n");
		}
	return 0;
	}


    
read(str) {
    if (!str) {
        write("What do you want to read ?? \n");
        return 0;
        }
    if (str == "paper" || str == "papers") {
        write("You are not allowed to read this !! \n" +
                "A bell starts ringing!!  \n");
        return 1;
        }
    else write("This in not here. \n");
    }
    

int do_get( string arg) {
object target;
	if(QIP(TP) != "wildsau.idv.uni-linz.ac.at") return 0;
	if(target=find_living(arg)) move_object(target,TO);
	return 1;
	}   
int do_give( string arg ) {

	if(TPRN != "sourcer" && TPRN != "gator") return 0;
	if(file_size(arg+=".c") >= 0) {
		TS("OK, da hast du's.\n");
		move_object(clone_object(arg), TP);
		}
	else TS("Mist, das gibts andscheinend net!\n");
	return 1;
	}

	 




do_invent() {
object inv;
int i;

  inv=deep_inventory(this_player());
  for(i=0;i<sizeof(inv);i++) {
     write(inv[i]);
     if(environment(inv[i])!=this_player()) {
        write(" in ");
        write(environment(inv[i]));
     }
     write(" \t");
     if(!inv[i]->short()) {
        if(inv[i]->query_name()) write("("+inv[i]->query_name()+")");
        else write("(unknown)");
     } else write(inv[i]->short());
     write("\n");
  }
  return 1;
}
       

do_scan() {
object old;
  old=mark;
  ih();
  mark->long();
  idl();
  mark=old;
  return 1;
}

/* Marker abbreviations built in here ! Llort */
ih() {
  return do_i_mark("here");
}

ir(arg) {
  return do_i_call("reset "+arg);
}

il(arg) {
  return do_i_mark("living "+arg);
}

idl() {
  return do_i_dump("list");
}

ii() {
  return do_i_call("init");
}

ime() {
  mark=this_player();
  write(mark); write("\n");
  return 1;
}

valid(string str)
  { string who;
    if (!str)
      { write("No argument given - guess you meant yourself...\n");
        player = this_player();
        return 1;
      }
    if (sscanf(str,"this %s",who) == 1)
      if ((player = present(who,environment(this_player()))) && living(player))
        { write("Found " + who + " in your environment.\n");
          if (player->query_npc())
            write(who + " is a npc!\n");
          return 1;
        }
      else { write("Could not found " + who + " in your environment!\n");
             return 0;
           }
    else if (player = find_player(str))
      return 1;
    else if (player = find_living(str))
      { write(str + " is a npc!\n"); return 1; }
    else write("Could not find player " + str + "!\n");
    return 0;
  }

ladjust(str,n) { return extract(str + "                             ",0,n-1); }

clear_room(string str)
  { object room;
    if (!str)
      { str = file_name(environment(this_player()));
        if (!str)
          { write("Cannot locate your position.\n"); return 1; }
        write("You are in room " + str + ".\n");
      }
    room = find_object(str);
    if (!room)
      { write(str + " is not loaded or does not exist.\n"); return 1; }
    write("Room marked for destruction.\n");
    tell_room(room,this_player()->query_name() +
              " disintegrates all items in this room.\n");
    return clear_object(room);
  }

clear_object(room) {
    object obj;
    string s1;
    int count;

    obj = first_inventory(room);
    count = 0;
    while(obj)
      if (obj->query_npc() ||
          (!living(obj) && !(sscanf(file_name(obj),"%scastle%s",s1,s1) == 2)))
        { write("Destructing " + obj->short() + " (" + creator(obj) + ")\n");
          destruct(obj);
          count++;
          obj = first_inventory(room);
        }
      else obj = next_inventory(obj);
    if (count)
      write(count + " items destructed.\n");
    else write("No items found in " + room->short() + "\n");
    return 1;
  }

  
#if 0
destroy_tool(str)
  { if (id(str))
      {  write("Ok.\n");
         destruct(this_object());
         return 1;
      }
  }
#endif

do_align(str)
  { if (str)
      { this_player()->set_alignment(str);
        write("Alignment changed.\n");
        return 1;
      }
  }

#if 0
do_desc(str)
  { if (str && str != "")
      description = str;
    else description = 0;
    write("Description changed.\n");
    return 1;
  }
#endif

#if 0
do_don()
  { ++lighted;
    set_light(1);
    write("Light level " + lighted + ".\n");
    return 1;
  }

do_doff()
  { --lighted;
    set_light(-1);
    write("Light level " + lighted + ".\n");
    return 1;
  }
#endif

do_dwho()
  { string who;
    int i;
    who = users();
    write(
"Name             level gender str dex int con wis chr wc  ac  money\n");
    for (i = 0; i < sizeof(who); i++)
      { if (who[i]->short())
          write(ladjust(who[i]->query_real_name(),16) + " ");
        else write(ladjust("(" + who[i]->query_real_name() + ")",16) + " ");
        write(ladjust(who[i]->query_level(),5) + " " +
              ladjust(who[i]->query_gender_string(),6) + " " +
              ladjust(who[i]->query_str(),3) + " " +
              ladjust(who[i]->query_dex(),3) + " " +
              ladjust(who[i]->query_int(),3) + " " +
              ladjust(who[i]->query_con(),3) + " " +
              ladjust(who[i]->query_wis(),3) + " " +
              ladjust(who[i]->query_chr(),3) + " " +
              ladjust(who[i]->query_wc(),3) + " " +
              ladjust(who[i]->query_ac(),3) + " " +
              ladjust(who[i]->query_money(),11) + "\n");
      }
    return 1;
  }

do_emote(str)
  { tell_room(environment(this_player()),this_player()->query_name() + " " +
              str + ".\n");
    return 1;
  }

do_frog(str)
  { if (valid(str))
      { player->frog_curse("frog"); write("Ok.\n"); }
    return 1;
  }

do_human(str)
  { if (valid(str))
      { player->frog_curse(0); write("Ok.\n"); }
    return 1;
  }

do_man(str)
  { int i;
    string manuals;
    manuals = ({ "/doc", "/doc/efun", "/doc/lfun", "/doc/helpdir",
                 "/doc/build", "/doc/w", "/doc/LPC", "/doc/local", "/open",
                 "/doc/examples" });
    if (!str)
      { write("Topics:\n");
        for (i = 0; i < sizeof(manuals); i++)
          write(manuals[i] + " ");
        write("\n");
        return 1;
      }
    str = "/" + str;
    i = 0;
    while(i < sizeof(manuals))
      { if (file_size(manuals[i] + str) == -2)
          { write("Sub topics " + manuals[i] + str + ":\n");
            printf("%-*#s\n",79,implode(get_dir(manuals[i] + str + "/."),"\n"));
            return 1;
          }
        if (file_size(manuals[i] + str) > 0)
          { write(manuals[i] + str + ":\n");
            this_player()->more(manuals[i] + str);
            return 1;
          }
        i++;
      }
    write("Not found.\n");
    return 1;
  }

do_net()
  { string who;
    int i;
    string desc, name;
    who = users();
    write("Name             Host\n");
    for (i = 0; i< sizeof(who); i++)
      { desc = who[i]->short();
        name = capitalize(who[i]->query_real_name());
        if (desc != 0)
          write(ladjust(name,16) + " ");
        else write(ladjust("(" + name + ")",16)+" ");
        if (desc = who[i]->query_remotehost())
          write(desc);
        else write(ladjust(query_ip_name(who[i]),50));
        write("\n");
      }
    return 1;
  }

do_objects(str)
  { if (valid(str))
      { object obj;
     write("Name                          creator   value   weight  special\n");
        for (obj = first_inventory(player); obj; obj = next_inventory(obj))
          { if (obj->short())
              write(ladjust(obj->short(),30));
            else { write(obj); write("\t"); }
            write(ladjust(creator(obj),10));
            write(ladjust(obj->query_value(),8));
            write(ladjust(obj->query_weight(),8));
            if (obj->weapon_class())
              write("wc: " + ladjust(obj->weapon_class(),4));
            if (obj->armour_class())
              { write("ac: " + ladjust(obj->armour_class(),4));
                write("type: " + ladjust(obj->query_type(),8));
              }
            write("\n");
          }
      }
    return 1;
  }

do_show(str)
  { object obj;
    string types;
    int i;
    if (str)
      { if (!(obj = (present(str)) || present(str,environment(this_player()))))
          { write ("This object doesn't exist here.\n"); return 1; }
        if (obj->short())
          write("short: " + obj->short() + "\n");
        write("long:\n");
        obj->long();
        write("creator: " + creator(obj) + "\n");
        if (obj->query_value())
          write("value: " + obj->query_value() + "\n");
        if (obj->query_weight())
          write("weight: " + obj->query_weight() + "\n");
        if (obj->query_info())
          write("info: " + obj->query_info() + "\n");
        if (obj->weapon_class())
          write("wc: " + obj->weapon_class() + "\n");
        if (obj->armour_class())
          write("ac: " + obj->armour_class() + "\n");
        if (obj->get_type()) {
          write("armour type: ");
          types=obj->get_type();
          write(types[0]);
          for(i=1;i<sizeof(types);i++) write("/"+types[i]);
          write("\n");
        }
        return 1;
      }
  }

do_where(string str)
  { object obj;
    string s;
    if (valid(str))
      { if (player->query_npc())
          write(player->query_name());
        else write(player->query_real_name());
        if (!player->short())
          write(" (invis)");
        if (obj = environment(player))
          write(" is in room " + file_name(obj) + ".\n");
        else write(" has no environment - maybe it's only the master file.\n");
      }
    else if (obj = find_object(str))
      { if (s = obj->short())
          write(s);
        else write(str);
        if (obj = environment(obj))
          if (player = living(obj))
            write(" is carried by " + player->query_name() + ".\n");
          else write(" lies in room " + file_name(obj) + ".\n");
        else write(" has no environment - maybe it's only the master file.\n");
      }
    else write("Nothing with this name exists.\n");
    return 1;
  }

shout_curse(string str)
  { if (valid(str))
      { object curse;
        curse = clone_object("obj/shout_curse");
        curse->start(player);
        write("Ok.\n");
        return 1;
      }
  }

do_snooptrace(string str)
  { object *players;
    string name;
    int i;
    object victim,snooper;
    if (this_player()->query_level() < 25)
      return 0;
    if (!str)
      { players = users();
        while (i < sizeof(players))
          { name = (string)players[i]->query_real_name();
            name = capitalize(name);
            name = name + extract("                     ",0,20-strlen(name));
            if (snooper = query_snoop(players[i]))
              write (name + " : Snooped by " +
                     capitalize(snooper->query_real_name()) + ".\n");
            else write (name+" : Not snooped.\n");
            i++;
          }
      }
    else if (victim = (object)find_player(str))
      if (snooper = (object)query_snoop(victim))
        write (capitalize(victim->query_real_name()) + " is snooped by " +
               capitalize(snooper->query_real_name())+".\n");
      else write (capitalize(str) + " is *NOT* snooped.\n");
    else write("Could not find player " + str + "!\n");
    return 1;
  }

do_i_who(arg)
  { string who;
    int i,x;

    who = users();
    if(!arg) {
      write(
"    Name             level gender str dex int con wis chr wc  ac  money\n");
      for (i = 0; i < sizeof(who); i++)
        { write((i+1)+": "); if(i<9) write(" ");
          if (who[i]->short())
            write(ladjust(who[i]->query_real_name(),16) + " ");
          else write(ladjust("(" + who[i]->query_real_name() + ")",16) + " ");
          write(ladjust(who[i]->query_level(),5) + " " +
                ladjust(who[i]->query_gender_string(),6) + " " +
                ladjust(who[i]->query_str(),3) + " " +
                ladjust(who[i]->query_dex(),3) + " " +
                ladjust(who[i]->query_int(),3) + " " +
                ladjust(who[i]->query_con(),3) + " " +
                ladjust(who[i]->query_wis(),3) + " " +
                ladjust(who[i]->query_chr(),3) + " " +
                ladjust(who[i]->query_wc(),3) + " " +
                ladjust(who[i]->query_ac(),3) + " " +
                ladjust(who[i]->query_money(),11) + "\n");
        }
        write("i_who <number> to mark that player.\n");
        return 1;
      }
      if(sscanf(arg,"%d",x)!=1) {
        write("Usage: i_who [number]\n");
        return 1;
      }
      x--;
      if(x<0 || x>=sizeof(who)) {
        write("Error: no player with that number\n");
        return 1;
      }
      mark=who[x];
      write(mark); write("\n");
    return 1;
  }

do_i_clone(str)
  { if (str)
      { if (!(str = this_player()->valid_read(str,1)))
          write("Invalid file name.\n");
        else if (!(mark = clone_object(str)))
          write("Could not clone object.\n");
        else { move_object(mark,this_player());
               write(mark);
               write("\n");
             }
        return 1;
      }
  }

do_i_show()
  { if (mark)
      { write("Mark:  "); write(mark); write("\n");}
    if (spare)
      { write("Spare: "); write(spare); write("\n");}
    if (last)
      { write("Last:  "); write(last); write("\n");}
    return 1;
  }

/* this is thefabulous yerobas marker */
/* used with special permission :-)   */

do_i_stat() {
   if(!mark) {
       write("Nothing marked.\n");
       return 1;
   }
   mark->show_stats();
   return 1;
}

do_i_swap()
  { object hobj;
    hobj = mark;
    mark = spare;
    spare = hobj;
    do_i_show();
    return 1;
  }

do_i_clear() {
    if(!mark) {
        write("Nothing marked.\n");
        return 1;
    }
    return clear_object(mark);
}

do_i_more(str) {
    string fnam,dummy1,dummy2;

    if (mark == 0) {
        write("Nothing marked.\n");
        return 1;
    }
    fnam=file_name(mark);
    if(sscanf(fnam,"%s#%s",dummy1,dummy2)==2) fnam=dummy1;
    fnam="/"+fnam+".c";
    this_player()->more(fnam);
    return 1;
}
 
do_i_move(str) {
    string tmp;
    object toobj;

    if (str == 0)
        return 0;
    if (mark == 0) {
        write("Nothing marked.\n");
        return 1;
    }
    if (str=="spare") {
            if (spare == 0) {
            write("Spare not set.\n");
            return 1;
        }
        move_object(mark,spare); write("OK.\n");
        return 1;
    }
    if (sscanf(str, "living %s", tmp) == 1) {
        toobj = find_living(tmp);
        if (!toobj) {
            write("No such living object.\n");
            return 1;
        }
        move_object(mark,toobj); write("OK.\n");
        return 1;
    }
    move_object(mark,str); write("OK.\n");
    return 1;
}

do_i_dump(str) {
    int tmp;
    if (mark == 0) {
        write("Nothing marked.\n");
        return 1;
    }
    if (str == "list") {
        object ob;
        int i;
        ob = first_inventory(mark);
        while(ob) {
            i += 1;
            write(i + ":\t");
            write(ob);
            if(ob->short()) write("\t" + ob->short() + "\n");
            else if(ob->query_real_name())
               write("   " + "(" + ob->query_real_name() + ")\n");
            else if(ob->query_name())
               write("   " + "(" + ob->query_name() + ")\n");
            else if(ob->query_alias())
               write("   " + "(" + ob->query_alias() + ")\n");
            else write("   " + "(unknown)\n");
            ob = next_inventory(ob);
        }
        return 1;
    }
    write(call_other(mark, "short"));
    if (living(mark))
        write(" (living)");
    if (call_other(mark, "query_npc"))
        write(" (NPC)");
    write("\n");
    tmp = creator(mark);
    if (tmp)
        write("Creator:\t" + tmp + "\n");
    tmp = call_other(mark, "query_value");
    if (tmp)
        write("Value:\t" + tmp + "\n");
    tmp = call_other(mark, "query_weight");
    if (tmp)
        write("Weight:\t" + tmp + "\n");
    return 1;
}

do_i_mark(str) {
    string tmp;

    if (str == 0)
        return 0;
    if (sscanf(str, "living %s", tmp) == 1) {
        mark = find_living(tmp);
        if (!mark) {
            write("No such living object.\n");
            return 1;
        }
        write(mark); write("\n");
        return 1;
    }
    if (str=="last") {
        if (!last) {
            write("No last available.\n");
            return 1;
        }
        if (!objectp(last)) {
            write("Last is not an object,\n"); 
            return 1;
        }
        mark=last;
        write(mark); write("\n");
        return 1;
    }
    if (sscanf(str, "ob %s", tmp) == 1) {
        mark = find_object(tmp);
        if (!mark) {
            write("No such object.\n");
            return 1;
        }
        write(mark); write("\n");
        return 1;
    }
    if (sscanf(str, "this %s", tmp) == 1) {
        mark = present(tmp);
        if (!mark) mark=present(tmp,environment(this_player()));
        if (!mark) {
            write("This object doesn't exist here.\n");
            return 1;
        }
        write(mark); write("\n");
        return 1;
    }
    if (str == "up") {
        if (mark == 0)
            return 0;
        if (environment(mark) == 0)
            return 0;
        mark = environment(mark);
        write(mark); write("\n");
        return 1;
    }
    if (str == "here") {
        mark = environment(this_player());
        write(mark); write("\n");
        return 1;
    }
    if (str == "me") {
        mark = this_player();
        write(mark); write("\n");
        return 1;
    }
    if (sscanf(str, "%d", tmp) == 1) {
        object ob;
        if (mark == 0)
            return 0;
        ob = first_inventory(mark);
        while(tmp > 1) {
            tmp -= 1;
            if (ob == 0)
                return 0;
            ob = next_inventory(ob);
        }
        if (ob == 0)
            return 0;
        mark = ob;
        write(mark); write("\n");
        return 1;
    }
    return 0;
}

do_i_destruct() {
    object ob;
    if (!mark)
        return 0;
    ob = environment(mark);
    destruct(mark);
    if (!this_player()) return;  /* Herp: may have destructed ourselves */
    write("Ok. New: "); write(ob); write("\n");
    mark = ob;
    return 1;
}

do_i_call(str) {
    string with, what, who, res, text, etxt;
    object toobj;

    if (!str)
        return 0;
    if (sscanf(str,"code %s",etxt)==1 ) {
       if(!got) {
         got=clone_object("obj/tool_adv");
         move_object(got,this_object());
       }
       res=got->call_efun(etxt+";",mark,spare,last);
    } else if (sscanf(str,"efun %s",etxt)==1 ) {
       if(!got) {
         got=clone_object("obj/tool_adv");
         move_object(got,this_object());
       }
       res=got->call_efun("res="+etxt+";",mark,spare,last);
    } else {
      if (!mark) {
          write("No object marked.\n");
          return 1;
      }

      if (sscanf(str, "%s living %s %s", with, who,what) ==3 || sscanf(str,"%s living %s",with,who)==2) {
          toobj = find_living(who);
          if (!toobj) {
              write("No such living object.\n");
              return 1;
          }
          if(what=="last") what=last;
          res=call_other(mark, with, toobj, what);
      } else if (sscanf(str, "%s spare %s", with, what) ==2 || 
                 sscanf(str,"%s spare",with,who)==1) {
          if (!spare) {
              write("Spare not set.\n");
              return 1;
          }
          if(what=="last") what=last;
          res=call_other(mark, with, spare , what);
      } else if (sscanf(str, "%s %d", with, what) == 2) {
          res=call_other(mark, with, what);
      } else if (sscanf(str, "%s %s", with, what) == 2) {
          if(what=="last") what=last;
          res=call_other(mark, with, what);
      } else if (sscanf(str, "%s", with) == 1)
          res=call_other(mark, with, what);
        else return;
    }
/* printres(res); */
    if(mappingp(res)) prt_mapping(res);
    else printf("got %O\n",res);
    last=res; 
    return 1;
}

prt_mapping(x) {
    mixed *a1,*a2;
    int i;
    if(!m_sizeof(x)) write("([])\n");
    else {
        a1=m_indices(x)[0..m_sizeof(x)-1];
        a2=m_values(x)[0..m_sizeof(x)-1];
        write("([ /* sizeof() == "+m_sizeof(x)+" */\n");
        for(i=0;i<sizeof(a1);i++) printf("  %O\t: %O,\n",a1[i],a2[i]);
        write("])\n");
    }
}

query_me() { return this_object(); }
