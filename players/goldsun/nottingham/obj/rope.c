inherit "/obj/rope";

string r1, r2;

object query_tied_to_ob(){ return tied_to_ob; }

int id(string str){ return ( str==r1 || str==r2  ); }

string short()
{
  if (tied_to) return ("A "+r1+" tied to "+tied_to);
  return  ("A "+r1) ; 
}

void long()
{ 
    write("A "+r1+" made of cotton.");
    if (r1=="rope") write(" This rope is good for rope ladders.\n");
       else write("\n");
}


string query_name()
{ 
 if (tied_to) return r1+" tied to " + tied_to;
 return r1;
}

int get() {
  if(tied_to) {
    write("The "+r1+" is tied to " + tied_to + ".\n");
    return 0;
  }
  return 1;
}

void reset(int a)
{
 if (a) return;
 r1="rope";
 r2="rope";
}

init()
{
 ::init();
 add_action("_make","make");
 add_action("dump","dump");
}

dump()
{
 write("obj:"+tied_to+":");
write(tied_to_ob->query_long());
return 1;
}

 
int tie(string str) {
    string t1, t2;
    object ob;
    if (!str)
	return 0;
    if (tied_to) {
        write("It is already tied to " + tied_to + ".\n");
	return 1;
    }
    if (sscanf(str, "%s to %s", t1, t2) != 2)
        return 0;
    if (!id(t1))
	return 0;
    if (t2 == "me") {
        write("Why would you do that ?\n");
	return 1;
    }
    ob = present(t2, this_player());
    if (!ob)
	ob = present(t2, environment(this_player()));
    if (!ob) {
	if (call_other(environment(this_player()), "id", t2))
	    ob = environment(this_player());
    }
    if (!ob) {
	write("What ?\n");
	return 1;
    }
    if (r1=="rope ladder"){  /* ladder tie , rope & lader */
      if (!ob->ladder_tie(t2) && !ob->tie(t2)) {
          write("You can't tie the "+r1+" to " + t2 + ".\n");
          return 1; 
      } 
    } else 		/* this is rope, tie only for rope */
      if (!ob->tie(t2)) {
          write("You can't tie the "+r1+" to " + t2 + ".\n");
          return 1;              
      }
    if (environment() == this_player()) {
	move_object(this_object(), environment(this_player()));
	this_player()->add_weight(-query_weight());
    }
    tied_to = t2;
    tied_to_ob = ob;
    write("Ok.\n");
    say((string)this_player()->query_name() + " ties "+r1+" to " + t2 + ".\n");
    return 1;
}

int untie(string str) {
    if (!id(str))
        return 0;
    if (!tied_to) {
        notify_fail("It is not tied to anything.\n");
	return 0;
    }
    if (tied_to_ob->untie()) {
        write("You don't seem to be able to do that.\n");
	return 1;
    }
    write("Ok.\n");
    tied_to = 0;
    tied_to_ob = 0;
    return 1;
}

int _make(string str)
{
 if (r1=="rope ladder") return 0;
 if (str=="rope ladder" || str=="ladder" ||
     str=="ladder from rope" || str=="rope ladder from rope")
 {
   write("You make rope ladder from cotton rope.\n");
   say(this_player()->query_name()+" makes a rope ladder.\n");
   r1="rope ladder";
   r2="ladder";
   return 1;
 }
}

